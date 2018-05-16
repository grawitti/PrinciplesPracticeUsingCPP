/**
 Дата создания: 14.05.18
 Автор: Руслан
 Назначение: Конвертация текстового файла в бинарный и обратно.
 Глава 11, упр. 9, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

int main() {
	try 
	{
		cout << "Конвертация текстового файла в бинарный и обратно.\n"; 
		cout << "Введите имя файла: ";
		string iname;
		cin >> iname;
		ifstream ifs{iname,ios_base::binary};
		if(!ifs) error("Невозможно открыть файл ", iname);
		
		vector<int> v;
		for (int x; ifs.read(as_bytes(x),sizeof(int));) v.push_back(x);

		string oname = iname + ".bin";
		ofstream ofs{oname,ios_base::binary};
		if(!ofs) error("Невозможно открыть файл ", oname);

		for(int x: v) ofs.write(as_bytes(x),sizeof(int));

		keep_window_open();
	}
	catch (exception& e) 
	{
		cerr << "\nОшибка: " << e.what() << endl;
		return 1;
		keep_window_open();
	}
	catch (...) 
	{
		cerr << "\nНеизвестное исключение!\n";
		return 2;
		keep_window_open();
	}
}
