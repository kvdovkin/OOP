#include <fstream>
#include <iostream>
#include <string>

const char* NOTFILE_MATRIX1 = "Файл 1 не найден.";
const char* NOTFILE_MATRIX2 = "Файл 2 не найден.";
const char* NOTFILE_OUT = "Файл OUT не найден.";
const char* ERR_MESSAGE = "Filesaredifferent.Linenumber is ";
const char* COMPLITE_MESSAGE = "Filesareequal";
using namespace std;

bool CheckFiles(ifstream &file1, ifstream &file2, ofstream &out) {
	if (!file1.is_open())
	{
		cout << NOTFILE_MATRIX1 << endl;
		return false;
	}
	if (!file2.is_open())
	{
		cout << NOTFILE_MATRIX2 << endl;
		return false;
	}
	if (!out.is_open())
	{
		cout << NOTFILE_OUT << endl;
		return false;
	}
}

int SizeFile(ifstream &file, int size_file, string s) {
	while (getline(file, s)) {
		size_file += 1;
	}
	return size_file;
}

bool ComparisonSizeFile(ofstream &out, int size_file1, int size_file2) {
	if (size_file1 < size_file2) {
		out << ERR_MESSAGE << size_file1 + 1 << endl;
		return false;
	}
	else {
		if (size_file1 > size_file2) {
			out << ERR_MESSAGE << size_file2 + 1 << endl;
			return false;
		}
		else return true;
	}
}

bool ComparisonFile(ifstream &file1, ifstream &file2, ofstream &out, string s1, string s2) {
	int err_line = 1, flag = 0, size_file1 = 0, size_file2 = 0;
	while (getline(file1, s1) && getline(file2, s2)) {
		if (s1 != s2) {
			out << ERR_MESSAGE << err_line << endl;
			flag = 1;
			break;
		}
		else {
			err_line += 1;
		}
	}
	if (flag == 0) {
		return true;
	}
	else return false;
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");

	ifstream file1(argv[1]);
	ifstream file2(argv[2]);
	ofstream out(argv[3]);
	string s1, s2, s3, s4;
	int size_file1 = 0, size_file2 = 0;
	int err_line = 1;

	if (!CheckFiles(file1, file2, out))
		return 1;

	size_file1 = SizeFile(file1, size_file1, s1);
	size_file2 = SizeFile(file2, size_file2, s2);
	file1.close();
	file2.close();

	file1.open(argv[1]);
	file2.open(argv[2]);
	if (ComparisonSizeFile(out, size_file1, size_file2) == true) {
		if (ComparisonFile(file1, file2, out, s3, s4) == false) {
			return 1;
		}
		else out << COMPLITE_MESSAGE << endl;
	}

	file1.close();
	file2.close();
	out.close();

	return 0;
}