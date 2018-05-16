/**
 Дата создания: 12.04.18
 Автор: Руслан
 Назначение: Реализация класса Roman_int для хранения римских цифр.
 Глава 10, упр. 6, стр. 427, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../std_lib_facilities.h"

const char MILDELIM = '&';


//Convert base digit 1,5,10,50,100,500,1000 to Rom digit
string  baseDigit(const int& i)
{  
	string r;
	switch (i)
   	{
		case 1: r = "I";
		break;
		case 5: r = "V";
		break;
		case 10: r = "X";
		break;
		case 50: r = "L";
		break;
		case 100: r = "C";
		break;
		case 500: r = "D";
		break;
		case 1000: r = "M";
		break;
		default: 
			r = "I dont know";
	}
	return r;
}

//Convert Digit between 1 and 3,999,999
string digConvert(int i) 
{
	string rom = "";
	int base = 0;

	if ((i < 0) || (i > 3999999)) return "err";

	while (i > 0)
	{
		if ((i >= 1) && (i <= 9)) base = 1;
		else if ((i >= 10) && (i <= 99)) base = 10;
		else if ((i >= 100) && (i <= 999)) base = 100;
		else if((i >= 1000) && (i <= 3999)) base = 1000;

// experimental
		else if (i >= 4000)
		{
			int baseMil = (i-i%1000)/1000; // Как делать round я не знаю =)
			string romMil = digConvert(baseMil);
			base = 100;
			rom = romMil+MILDELIM; // Разделитель тысяч
			i -= (i-i%1000); // Точно такая же проблема
		} else return "err";  // Если что-то совсем страшное
// 

		if (i >= 9*base)
		{
			rom = rom + baseDigit(base) + baseDigit(base*10);
			i -= 9*base;
		} 
		else if (i >= 5*base)
 		{
			rom = rom + baseDigit(5*base);
			i -= 5*base;
		}
		else if (i >= 4*base)
		{
			rom = rom + baseDigit(base) + baseDigit(5*base);
			i -= 4*base;
		}
		while (i >= base)
		{
			rom = rom + baseDigit(base);
			i -= base;
		}
	}
	return rom;
}

//
int baseIntDigit (const char& c) 
{
	switch (c) {
		case MILDELIM: return -1;
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:
			return 0;
	}
}

// Перевод римских знаков в вектор арабских чисел (MCCIXL = 1000, 100, 100, 1, 10, 50).
vector<int> srcArabVector (const string& s) 
{
	vector<int> vi;
	stringstream ss{s};
	char c = ' ';
	while (ss)
	{
		c = ss.get();
		if (baseIntDigit(c)) vi.push_back(baseIntDigit(c));
	}
	return vi;	
}

// Копирование элементов вектора с bigin до end
vector<int> copyRange (const vector<int>& ivi, int begin, int end) 
{
	vector<int> ovi;
	if (begin > end || begin < 0) error("Неверные значения begin или end.");
	for (int i = begin; i <= end; ++i) {
		ovi.push_back(ivi[i]);
	}
	return ovi;
}

// Обработка вектора арабских чисел (1000, 100, 100, 1, 10, 50 = 1239).
int romanToInt (const vector<int>& vi) 
{
	int arab = 0;
	int arabMil = 0;
	for (int i = vi.size()-1; i >= 0; --i)
   	{
		if (i == vi.size()-1) 
		{
			if (vi[i] == -1) // Если у нас только тысячи без сотен десятков и единиц
			{
				arabMil = romanToInt(copyRange(vi,0,vi.size()-2))*1000; // Выделяем диапазон тысяч, вызываем себя умножаем на 1000.
				return arabMil;
			}
			arab = vi[i];
		}
		if (i != 0)
		{
			if (vi[i-1] == -1) // Если наше число имеет тысячи, а так же сотни или десятки или единицы
			{
				arabMil = romanToInt(copyRange(vi,0,i-2))*1000;
				return arabMil + arab;
			} 
			if (vi[i] > vi[i-1]) arab -= vi[i-1];
			else arab += vi[i-1];
		}
	}
	if (vi[vi.size()-1] == -1) return arab*1000;
	return arab;
}

//
class Roman_int {
public:
	string romain () const { return r; }
	int asInt ();

	Roman_int () {  }
	Roman_int (string rr) :r{rr} {  }
private:
	string r{"err"};
};

// Вернуть Romain_int как арабское число
int Roman_int::asInt () 
{
	return romanToInt(srcArabVector(r));
}

ostream& operator<< (ostream& os, const Roman_int& r) 
{
	return os << r.romain();
}

// Не проверяет правильность последовательности римских знаков в римском числе и максимальное повторенние 3 знаков подряд.
istream& operator>> (istream& ist, Roman_int& r) 
{
	string s;
	for (char c; ist && c != '\n'; )
	{
		c = ist.get();
		if (c == '\n') break;
		if (!baseIntDigit(c) && (c)) error ("Неверный формат римских чисел.");
		else s += c;
	}
	if(!ist) return ist;
	r = {s};
	return ist;
}