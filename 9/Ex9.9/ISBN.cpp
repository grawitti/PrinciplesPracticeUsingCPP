#include "Ex9.9.h"

// Проверка на соответсвие с стандартом использования ISBN, например: 0-1-20-33-S
bool isISBN (const string& s) {
	const char SEPARATOR = '-'; // разделитель для ISBN, например: 0-1-20-33-S
	if (s.find("-")) {
		stringstream ss(s);
		vector<string> vs;
		string tempS = "";
		while (getline(ss, tempS, SEPARATOR)) vs.push_back(tempS); // разделяем строки из потока ss
		if (vs.size() != 4) return 0;
		stringstreamClear(ss);
		char tempC;
		for (int i = 0; i < vs.size(); ++i) {
			stringstream buf(vs[i]);
			buf >> tempC;
			if (isspace(tempC)) return 0;
			 if (!(i == vs.size()-1)) {
			 	if (!isNumber(tempC)) return 0;
			 	buf.putback(tempC);
			 	int tempI;
				buf >> tempI;
			}	else {
					if (vs[i].length() > 1 || vs[i].length() <= 0) return 0;
					if (!(isalpha(tempC) || isdigit(tempC)) || isspace(tempC)) return 0;
				}
			tempC = ' ';
			tempS = "";
			buf >> tempS;
			if (tempS != "") return 0;
			stringstreamClear(buf);
		}
	} else return 0;
	return 1;
}