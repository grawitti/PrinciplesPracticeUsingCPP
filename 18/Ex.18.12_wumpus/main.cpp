/*
    Date: 03.12.18
    Author: Grawitti
	Description: 
    Chapter 18 – Principles and Practice Using C++   
	Exercise 12 - Vumpus
*/

#include "Game_logic.h"

using namespace std;

int main()
{
	try
	{	
		const int min = 7;	// set minimum rooms
		const int max = 15;	// set maximum rooms
		const int rooms_n = random_int(min,max);	// set rooms amount

		SL_list sl;
        for(int i=0; i<rooms_n; ++i) { sl.push_back(new Link(i)); }
		set_rooms_refs(sl,rooms_n-1);
		set_wump_bat_hole(sl,1,rooms_n-1);

		cout << "Охота на Вампуса.\n";
		help();

		// sl.print_list(); // Debug info

		Game_status game{sl,sl.first()};

		while(game.status == 'c') 
		{
			check_game_status(game);
			if(game.status != 'o') {
				room_info(game.current_room);
				game.current_room = step(game);
				check_game_status(game);
			}
			if(!check_wumpus_life(game.sl)) {
				print_wumpus_killed();
				game.status = 'w';
			}
		}
		if(game.status == 'o') cout << "Игра окончена :(\n";
		if(game.status == 'w') cout << "Победа! ;)\n";
		return 0;
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown exception!" << '\n';
		keep_window_open();
		return 2;
	}
}