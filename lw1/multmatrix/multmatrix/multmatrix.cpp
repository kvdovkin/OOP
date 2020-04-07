#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

const int N = 3;
const char* NOTFILE_MATRIX1 = "Файл 1 не найден.";
const char* NOTFILE_MATRIX2 = "Файл 2 не найден.";
const char* NOTFILE_OUT = "Файл OUT не найден.";
const char* LINE = "__________________________";
typedef double matrix[N][N];
using namespace std;

void PrintMatrix(ofstream &out, matrix matrix3) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setprecision(4) << matrix3[i][j] << "\t";
		}
		cout << endl;
	}
}

void EnterMatrix(ifstream &file, matrix matrix) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			file >> matrix[i][j];
}

void PrintMatrixOut(ofstream &out, matrix matrix3) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			out << setprecision(4) << matrix3[i][j] << "\t";
		}
		out << endl;
	}
}

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

void Multmatrix(matrix matrix1, matrix matrix2, matrix matrix3) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix3[i][j] = 0;
			for (int k = 0; k < N; k++)
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");

	ifstream file1(argv[1]);
	ifstream file2(argv[2]);
	ofstream out(argv[3]);
	
	double matrix1[N][N];
	double matrix2[N][N];
	double matrix3[N][N];
	
	if (!CheckFiles(file1, file2, out))
		return 1;

	EnterMatrix(file1, matrix1);
	EnterMatrix(file2, matrix2);

	Multmatrix(matrix1, matrix2, matrix3);
	PrintMatrix(out, matrix3);
	PrintMatrixOut(out, matrix3);

	file1.close();
	file2.close();
	out.close();

	return 0;
}