#include "../std_lib_facilities.h"

// Выводит в поток cout вектор целых чисел - v и метку, string - s
void print (const string& s, const vector<int>& v) {
	cout << s << ": ";
	for (int x : v) cout << x << ' ';

	cout << endl;
}

int main () {
	vector<int> vint {0,1,2,3,4,5,6,7,8,9};
	string mark = "Вектор 1";
	print (mark, vint);
}