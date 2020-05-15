#include <fstream>
#include <iostream>
#include <string>
#include "CTVSet.h"
using namespace std;

const string LINE = "______________________";
const string CHOOSE_COMMAND = "Выберите команду:";
const string TURN_ON = "TurnOn";
const string TURN_OFF = "TurnOff";
const string SELECT_CHANNEL = "SelectChannel";
const string INFO = "Info";
const string EXIT = "Exit";
const string SELECT_PREVIOUS_CHANNEL = "SelectPreviousChannel";
const string UNCORRECT_CHANNEL = "Некорректный канал";

void PrintCommand() {
	cout << LINE << endl;
	cout << CHOOSE_COMMAND << endl;
	cout << TURN_ON << endl;
	cout << TURN_OFF << endl;
	cout << SELECT_CHANNEL << endl;
	cout << INFO << endl;
	cout << SELECT_PREVIOUS_CHANNEL << endl;
	cout << EXIT << endl;
}

bool CheckChannel(int channel) {
	bool flag;
	if ((channel > 0) && (channel < 100))
		flag = true;
	else flag = false;

	return flag;
}

int main()
{
	setlocale(LC_ALL, "ru-RU.UTF-8");
	string toExit, command;
	CTVSet TVSet;
	int channel;
	bool check;

	while (toExit != EXIT) {
		PrintCommand();
		cin >> command;

		if (command == TURN_ON)
			TVSet.TurnOn();
		if (command == TURN_OFF)
			TVSet.TurnOff();
		if (command == SELECT_CHANNEL) {
			cin >> channel;
			check = CheckChannel(channel);
			if (check)
				TVSet.SelectChannel(channel);
			else cout << UNCORRECT_CHANNEL << endl;
		}
		if (command == INFO)
			TVSet.Info();
		if (command == SELECT_PREVIOUS_CHANNEL)
			TVSet.SelectPreviousChannel();
		if (command == EXIT)
			break;
	}

	return 0;
}