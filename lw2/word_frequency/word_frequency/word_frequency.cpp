#include <fstream>
#include <iostream>
#include <string>
#include <map>

const char* NOTFILE_MATRIX1 = "Файл IN не найден.";
const char* NOTFILE_OUT = "Файл OUT не найден.";
using namespace std;
typedef map<string, int> myMap;

bool CheckFiles(ifstream &file, ofstream &out) {
	if (!file.is_open())
	{
		cout << NOTFILE_MATRIX1 << endl;
		return false;
	}
	if (!out.is_open())
	{
		cout << NOTFILE_OUT << endl;
		return false;
	}
}

void printMap(ofstream &out, myMap &dict) {
	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		out << (*it).first << " : " << (*it).second << endl;
	}
}	

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");

	ifstream in(argv[1]);
	ofstream out(argv[2]);
	string str;
	bool flag = true;
	myMap dict;

	if (!CheckFiles(in, out))
		return 1;

	in >> str;
	while (flag) {
		if (in.eof()) {
			flag = false;
			break;
		}

		dict[str]++;
		in >> str;
	};

	printMap(out, dict);
		
	in.close();
	out.close();

	return 0;
}