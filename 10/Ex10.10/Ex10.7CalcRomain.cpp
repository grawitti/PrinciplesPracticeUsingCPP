

/*
 * Глава 10, задание 7. Страуструп "Принципы и правктика с исп. С++"
 * Проверка ввода правильности римских чисел не реализована см. Romain.h
 * Операции с римскими числами производятся как с арабскими (не во всех случаях это корректно)
 * Результат выводится арабскими числами 
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

	CHANGELOG
	
	8.1 Выделение потока ввода как явного параметра, конструктор класса Token_stream.
	7.6 Вывод Инструкция при вводе help
	7.5 Добавлена обработка символа перехода на новую строку \n Enter.
	7.4 Добавлен класс SymbolTable.
	7.3 Добалены константы (const x = 3;).
	7.2 Добавлена функция переопределения переменных (присвоение, при повторном определении переменной).
	7.1 Добавлена возможность задавать в именах переменных символ подчеркивания _ (test_variable).
*/

#include "../../std_lib_facilities.h"
#include <cmath>
#include "Roman.h"

bool file = false; // Если чтение лексем из фала = true
const char CONSTS = 'C';
const char let = 'L';
const char quit = 'q'; 
const char print = ';';
const char number = '0';
const char romain = 'r';
const char name = 'a';
const char SQRT = '2';
const char POW = 'p';
const char declkey = '#';
const char input = 'i';
const char output = 'o';
const string prompt = "> ";
const string result = "= ";
const string decSqrt = "sqrt";
const string decPow = "pow";
const string decConst = "const";
const string quitKey = "exit";
const string help = "help";
const string fromFile = "from";
const string toFile = "to";



// Класс для лексем
class Token {
public:
	char kind;
	double value;
	string name;

	Token () {  }
	Token(char ch) :kind(ch), value(0) { } // конструктор для операторов +, -, / ...
	Token(char ch, double val) :kind(ch), value(val) { } // конструктор для цисел
	Token(char ch, string n) :kind(ch), name(n) { } // конструктор для переменных
};

// Поток лексем
class Token_stream {
public:

	Token_stream(); // буфер
	Token get(); // получение следующей лексемы
	Token getFile(); // получение следующей лексемы из файла
	void putback(Token t); // возврат символа в буфер
	void ignore(char c); // удаление символов до символа print
private:
	bool full;
	Token buffer;
};


// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

// Вывод инструкции в консоль
void printHelp () {
	cout << "Инструкция" << endl;
}


// открытие файла для чтения
fstream fs;
void openFile () 
{
	string iname;
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs) error("Невозможно открыть файл для чтения", iname);
	while (!ifs.eof()) 
	{
		char ch;
		ch = ifs.get();
		fs << ch;
	}
}

// Считывание лексем из файла
Token Token_stream::getFile()
{
	if (full) { 
		full=false; 
		return buffer; 
	}
	
	char ch;
	ch = fs.get();
	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // Выввод результата если введен символ перехода на новую строку Enter
		else ch = fs.get();
	}
	switch (ch) {

	// операторы
	case quit:
		return Token(quit);
	case declkey:
		return Token(let);
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
		return Token(ch);

	// числа
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	fs.putback(ch);
		double val;
		fs >> val;
		return Token(number,val);
	}
	case 'I': case 'V': case 'X': case 'C': case 'L': case 'M': case 'D':
	{
		string tmp;
		tmp+= ch;
		while(fs.get(ch) && (baseIntDigit(ch))) tmp+=ch;
		fs.putback(ch);
		Roman_int r;
		r = {tmp};
		return Token(romain,r.asInt());
	}
	default:
	// переменные
		if (isalpha(ch)) { // Если символ
			string s;
			s += ch;
			while(fs.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch; // добавляем символы в строку пока символы буквы или цифры
			fs.putback(ch);
			if (s == quitKey) return Token(quit);
			if (s == fromFile) 
			{
				if (!file) openFile();
				file = true;
				return Token(input);
			}
			if (s == toFile) return Token(output);
			if (s == decSqrt) return Token(SQRT);
			if (s == decPow) return Token(POW);
			if (s == decConst) return Token(CONSTS);
			if (s == help) {printHelp(); return Token(quit);}
			return Token(name,s);
		}
		error("Bad token");
	}
}

// Считывание лексем
Token Token_stream::get()
{
	if (full) { 
		full=false; 
		return buffer; 
	}

	char ch;
	ch = cin.get();
	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // Выввод результата если введен символ перехода на новую строку Enter
		else ch = cin.get();
	}
	switch (ch) {

	// операторы
	case quit:
		return Token(quit);
	case declkey:
		return Token(let);
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
		return Token(ch);

	// числа
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.putback(ch);
		double val;
		cin >> val;
		return Token(number,val);
	}
	case 'I': case 'V': case 'X': case 'C': case 'L': case 'M': case 'D':
	{
		string tmp;
		tmp+= ch;
		while(cin.get(ch) && (baseIntDigit(ch))) tmp+=ch;
		cin.putback(ch);
		Roman_int r;
		r = {tmp};
		return Token(romain,r.asInt());
	}
	default:
	// переменные
		if (isalpha(ch)) { // Если символ
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch; // добавляем символы в строку пока символы буквы или цифры
			cin.putback(ch);
			if (s == quitKey) return Token(quit);
			if (s == fromFile) 
			{
				if (!file) openFile();
				file = true;
				return Token(input);
			}
			if (s == toFile) return Token(output);
			if (s == decSqrt) return Token(SQRT);
			if (s == decPow) return Token(POW);
			if (s == decConst) return Token(CONSTS);
			if (s == help) {printHelp(); return Token(quit);}
			return Token(name,s);
		}
		error("Bad token");
	}
}

// Пропуск символов до char c
void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}

Token_stream ts;

// Класс для создания переменных и их значений
class Variable {
public:
	string name;
	double value;
	bool isConst;
	Variable(string n, double v) :name(n), value(v) { }
	Variable(string n, double v, bool c) :name(n), value(v), isConst(c) { }
};

// Обработка переменных и констант
class Symbol_table {
public:
	vector<Variable> varTable;
	string name;
	double value;
	bool isConst;
	
	double getV(string s);
	void set(string s, double d);
	bool is_declared(string s);
	void reDeclaration (string s, double d, bool c);
	double define_name(string s, double d, bool c);

	Symbol_table() { }
	Symbol_table(string s) :name(s) { }
	Symbol_table(string s, double d) :name(s), value(d) { }
	Symbol_table(string s, double d, bool c) :name(s), value(d), isConst(c) { }
};


// Поиск значения переменной по имени в векторе varTable
double Symbol_table::getV(string s)
{
	for (int i = 0; i<varTable.size(); ++i)
		if (varTable[i].name == s) return varTable[i].value;
	error("get: undefined name ",s);
}

// Присвоение значения - d, переменной с именем - s, в векторе - varTable
void Symbol_table::set(string s, double d)
{
	for (int i = 0; i<=varTable.size(); ++i)
		if (varTable[i].name == s) {
			varTable[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

// Проверка существует ли переменная с именем - s в векторе - varTable
bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i<varTable.size(); ++i)
		if (varTable[i].name == s) return true;
	return false;
}

// Переопределение переменной новым значанием
void Symbol_table::reDeclaration (string s, double d, bool c) {
	//if (c) error ("Нельзя переопределить значение константы");
	for (int i = 0; i<varTable.size(); ++i) {
		if (varTable[i].name == s) { 
			if (!varTable[i].isConst) {
				varTable[i].value = d;
				varTable[i].isConst = c;
			}
			else error ("Нельзя переопределить значение константы");
		}
	}
}

// Объяеление с присвоением занчения - val переменной - var в векторе - varTable
double Symbol_table::define_name(string s, double d, bool c)
{
    if (is_declared(s)) reDeclaration(s, d, c);
    varTable.push_back(Variable(s, d, c));
    return d;
}

// объявление функции выражение
double expression(Token_stream& ts);

Symbol_table st;

// первичное выражение 
double primary(Token_stream& ts)
{
	Token t;
	if (file) t = ts.getFile();
	else t = ts.get();
	switch (t.kind) {
	case input:
		t = ts.getFile();
		return primary(ts);
	case '(':
		{	
			double d = expression(ts);
			if (file) Token t = ts.getFile();
			else t = ts.get();
			if (t.kind != ')') error("'(' expected");
			return d;
		}
	case '-':
		return - primary(ts); // обработка отрицательного числа
	case number:
		return t.value;
	case romain:
		return t.value;
	case name: {
		double d2 = st.getV(t.name);
		return d2; // получение значения из переменной
	}
	case SQRT: {	// квадратный корень числа
			double d = primary(ts);
			if (d < 0) error("квадратный корень из отрицательного числа");
			return sqrt(d);
		}
	case POW: {	// врзведение в степень числа
			double d = expression(ts);
			if (file) Token t = ts.getFile();
			else t = ts.get();
			if (t.kind != ',') error("',' пропущена");
			int x = narrow_cast<int>(primary(ts));
			if (x == 0) error("возведение в степень 0");
			return pow(d,x);
		}
	default:
		error("primary expected");
	}
}

// терминал
double term(Token_stream& ts)
{
	double left = primary(ts);
	while(true) {
		Token t;
		if (file) t = ts.getFile();
		else t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%': {
			double d = primary(ts);
			if (d == 0) error("% деление на 0");
			left = fmod(left,d);
			break;	
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

// определение выражения
double expression(Token_stream& ts)
{
	double left = term(ts);
	while(true) {
		Token t;
		if (file) t = ts.getFile();
		else t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

// Присвоение значения переменной
double declaration(bool c)
{
	Token t;
	if (file) t = ts.getFile();
	else t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string name = t.name;

	Token t2;
	if (file) t = ts.getFile();
	else t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);

	double d = expression(ts);
	st.define_name(name,d,c);
	return d;
}

// При объявлении переменной вызывает функцию declaration() для объявления новой переменной
double statement()
{
	Token t;
	if (file) t = ts.getFile();
	else t = ts.get();
	switch(t.kind) {
	case let:
		return declaration(false);
	case CONSTS:
		return declaration(true);
	default:
		ts.putback(t);
		return expression(ts);
	}
}

// Вызывает функцию которая пропускает символы до print
void clean_up_mess()
{
	ts.ignore(print);
}

// Вычисление выражения и вывод результата
void calculate()
{
	while(true) 
		try {
			cout << prompt;
			Token t;
			if (file) t = ts.getFile();
			else t = ts.get();
			while (t.kind == print) 
			{
				Token t;
				if (file) t = ts.getFile();
				else t=ts.get();

			}		
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
	try {
		st.define_name("k",1000,true);
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=print) ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=print);
		return 2;
	}
