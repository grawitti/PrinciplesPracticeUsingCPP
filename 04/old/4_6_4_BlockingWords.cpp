#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	string const outWord = "BLEEP";
	// Ввод слов которые будут блокироваться
	vector <string> blockingWords;
	cout << "Введите слова которые надо заменить, в конце ввдеите символ е" << '\n';
	for (string word; word!="e"; ) {
		cin>>word;
		blockingWords.push_back(word);
	}
	// Ввод слов которые необходимо отфильтровать, т.е. заменить на BLEEP
	for (string inWord; cin >> inWord; ) {
		//for (int i = 0; i <= blockingWords.size(); i++) {
		for (string x : blockingWords) {
			//if (inWord == blockingWords[i]) {
			if (x == inWord) {
				inWord = outWord;
			}
		}
		cout << inWord << '\n';
	}
}
