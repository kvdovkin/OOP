#include <fstream>
#include <iostream>
#include <string>

const char* NOTFILE_OUT = "Файл OUT не найден.";
using namespace std;

bool CheckFiles(ofstream &out) {
	if (!out.is_open())
	{
		cout << NOTFILE_OUT << endl;
		return false;
	}
}

string FindAndReplace(string subject, string search, string replace) {
	string::size_type index;
	while ((index = subject.find(search)) != string::npos)
		subject.replace(index, search.size(), replace);
	
	return subject;
}

void printSubject(ofstream &out, string subject) {
	out << subject << endl;
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");

	string subject(argv[1]);
	string search(argv[2]);
	string replace(argv[3]);
	ofstream out(argv[4]);

	if (!CheckFiles(out))
		return 1;

	printSubject(out, FindAndReplace(subject, search, replace));

	out.close();
	return 0;
}