#include "SL_list.h"
#include "Randomization.h"
#include "Dialogs.h"

// Очистка потока cin, до символа: \n
void clearCin() {
  char с = 'c';
  while (с != '\n') с = cin.get();
}

// Очистка потока - ss по ссылке
void stringstreamClear(stringstream& ss) {
	ss.str("");
	ss.clear();
}

// Обаботка ввода из потока cin занчения - int
int get_int (stringstream& ss) {
  char c = '0';
  while (true) {
    ss >> c;
    switch (c) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        ss.putback(c);
        int i;
        ss >> i;
        stringstreamClear(ss);
        return i;       
      }
      default:
        cerr << "Введите целое положительное число:\n";
        return -1;
        stringstreamClear(ss);
        break;
    }  
  }
}

struct Game_status {
    Game_status(SL_list& l, Link* cr, char s = 'c', int a = 5) : sl(l), current_room(cr), status(s), arrows(a) {}
    SL_list sl;
    Link* current_room;
    char status;
    int arrows;
};

// Set references for room_b & room_c
void set_rooms_refs(SL_list& sl, int rooms_n) {
	Link* current = sl.first();
	int temp_n = random_int(0,rooms_n);
	int next_n = -1;
	while(current) {
		next_n = (current->next) ? current->next->n : -1;
		while(temp_n == current->n || temp_n == next_n) {
			temp_n = random_int(0,rooms_n);
		}
		current->room_b = sl.find(temp_n);
		while(temp_n == current->n || temp_n == next_n || temp_n == current->room_b->n) {
			temp_n = random_int(0,rooms_n);
		}
		current->room_c = sl.find(temp_n);
		if(current) current = current->next;
	}
}

// Set Wumpus & bat & hole rooms
void set_wump_bat_hole(SL_list& sl, int min, int max) {
	int wumpus_n = random_int(min,max);
	while(wumpus_n == 0) { wumpus_n = random_int(min,max); }
	sl.find(wumpus_n)->wumpus = true;

	int bat_n = random_int(min,max);
	while(bat_n == 0 || bat_n == wumpus_n) { bat_n = random_int(min,max); }
	sl.find(bat_n)->bat = true;

	int hole_n = random_int(min,max);
	while(hole_n == 0 || hole_n == wumpus_n || hole_n == bat_n) { hole_n = random_int(min,max); }
	sl.find(hole_n)->hole = true;
}

// check wumpus
bool check_wump(Link* l) 
{
    if(l->next) if(l->next->wumpus) return true;
    if(l->room_b->wumpus) return true;
    if(l->room_c->wumpus) return true;
    return false;
}

// check bat
bool check_bat(Link* l) {
    if(l->next) if(l->next->bat) return true;
    if(l->room_b->bat) return true;
    if(l->room_c->bat) return true;
    return false;
}

// check hole
bool check_hole(Link* l) {
    if(l->next) if(l->next->hole) return true;
    if(l->room_b->hole) return true;
    if(l->room_c->hole) return true;
    return false;
}

// move in next room
Link* move(const SL_list& sl, int n) {
    return sl.find(n); 
}

// shot 
void shot(Game_status& game, int n) {
    Link* l = game.sl.find(n);
    if(l->wumpus) {
        l->wumpus = false;
        return;
    }
    if(l->bat) {
        l->bat = false;
        print_bat_killed(game.arrows);
        return;
    }
    print_miss(game.arrows);
}

//Wumpus is life?
bool check_wumpus_life(const SL_list& sl) {
    Link* current_l = sl.first();
    while(current_l) {
        if(current_l->wumpus) return true;
        if(current_l) current_l = current_l->next;
    }
    return false;
}

// Bat is life?
bool check_bat_life(const SL_list& sl) {
    Link* current_l = sl.first();
    while(current_l) {
        if(current_l->bat) return true;
        if(current_l) current_l = current_l->next;
    }
    return false;
}


bool check_correct_room(const Game_status& game, int n) {
    Link* l = game.current_room;
    if(n!=l->next->n && n!=l->room_b->n && n!=l->room_c->n) 
    {
        print_incorrect_room(n);
        return false;
    }                
    if(n>game.sl.size()-1) {
        print_rooms_range(n);
        return false;
    }
    return true;
}

//
Link* step(Game_status& game) {
    print_step();
    string line;
    getline(cin,line);
    stringstream ss{line};
    for (char ch = '0'; ss >> ch; ) {
        switch(ch) {
            case 'm':
            {
                int n = get_int(ss);
                return (check_correct_room(game,n)) ? move(game.sl,n) : game.current_room;
            break;
            }
            case 's':
            {
                int n = get_int(ss);
                if(check_correct_room(game,n)) {
                    if(game.arrows > 0) { 
                        game.arrows--;
                        shot(game,get_int(ss));
                    }
                    else 
                    {
                        get_int(ss);
                        print_end_arrows();
                    }
                } 
                else return game.current_room; 
            break;
            }
            case 'q': error("Выход из игры!\n");
            default:
                cout << "Не поддерживаемое действие: " << ch << endl;
                return game.current_room;
            break;
        }
    }
    return game.current_room;
}

void check_game_status(Game_status& game)
{
    if(game.current_room->wumpus) {
        print_wump_eat();
        game.status = 'o';
        return;
    }
    if(game.current_room->bat) {
        int n = random_int(0,game.sl.size()-1);
        print_bat_catch(n);
        game.current_room = move(game.sl,n);
        return;
    }
    if(game.current_room->hole) {
        print_fall();
        game.status = 'o';
        return;
    }
}

// help
void help() {
    cout << "Показать правила игры? (y/n): ";
    for (char ch = '0'; ch != 'q'; ) {
        cin>>ch;
        switch(ch){
            case 'y': 
                print_help(); 
                ch = 'q';
            break;
            case 'n': ch = 'q';
            break;
            default: cout << "Введите y - Да или n - Нет!\n";
            break;
        }
    }
    clearCin();
}

// room info
void room_info(Link* l) {
    int next = -1;
    if(l->next) next = l->next->n;
    print_room_info(l->n,l->room_b->n,l->room_c->n,next);

    if(check_wump(l)) cout << "Я чувствую запах Вампуса.\n";
    if(check_bat(l)) cout << "Я слышу летучую мышь.\n";
    if(check_hole(l)) cout << "Я чувствую ветерок.\n";
} 