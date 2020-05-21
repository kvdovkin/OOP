#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string NOTFILE_MATRIX1 = "File input 1 not found.";
const string NOTFILE_MATRIX2 = "File input 2 not found.";
const string NOTFILE_OUT = "File output not found.";
const string ERR_MESSAGE = "Files are different. Line number is ";
const string COMPLITE_MESSAGE = "Files are equal";


bool CheckFiles(ifstream &firstInputFile, ifstream &secondInputFile, ofstream &out) {
	if (!firstInputFile.is_open())
	{
		cout << NOTFILE_MATRIX1 << endl;
		return false;
	}
	if (!secondInputFile.is_open())
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

int SizeFile(ifstream &file, int size_file, string str) {
	while (getline(file, str)) {
		size_file += 1;
	}
	return size_file;
}

bool ComparisonSizeFile(ofstream &out, int sizeFirstInputFile, int sizeSecondInputFile) {
	if (sizeFirstInputFile < sizeSecondInputFile) {
		out << ERR_MESSAGE << sizeFirstInputFile + 1 << endl;
		return false;
	}
	else {
		if (sizeFirstInputFile > sizeSecondInputFile) {
			out << ERR_MESSAGE << sizeSecondInputFile + 1 << endl;
			return false;
		}
		else return true;
	}
}

bool ComparisonFile(ifstream &firstInputFile, ifstream &secondInputFile, ofstream &out, string stringToSizeFile1, string stringToSizeFile2) {
	int errLine = 1, flag = 0;
	while (getline(firstInputFile, stringToSizeFile1) && getline(secondInputFile, stringToSizeFile2)) {
		if (stringToSizeFile1 != stringToSizeFile2) {
			out << ERR_MESSAGE << errLine << endl;
			flag = 1;
			break;
		}
		else errLine += 1;
	}
	if (flag == 0) {
		return true;
	}
	else return false;
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");

	ifstream firstInputFile(argv[1]);
	ifstream secondInputFile(argv[2]);
	ofstream out(argv[3]);
	string stringToSizeFile1, stringToSizeFile2, stringToComparisonFile1, stringToComparisonFile2;
	int sizeFirstInputFile = 0, sizeSecondInputFile = 0;

	if (!CheckFiles(firstInputFile, secondInputFile, out))
		return 1;

	sizeFirstInputFile = SizeFile(firstInputFile, sizeFirstInputFile, stringToSizeFile1);
	sizeSecondInputFile = SizeFile(secondInputFile, sizeSecondInputFile, stringToSizeFile2);
	firstInputFile.close();
	secondInputFile.close();

	firstInputFile.open(argv[1]);
	secondInputFile.open(argv[2]);
	if (ComparisonSizeFile(out, sizeFirstInputFile, sizeSecondInputFile) == true) {
		if (ComparisonFile(firstInputFile, secondInputFile, out, stringToComparisonFile1, stringToComparisonFile2) == false) {
			return 1;
		}
		else out << COMPLITE_MESSAGE << endl;
	}

	firstInputFile.close();
	secondInputFile.close();
	out.close();

	return 0;
}