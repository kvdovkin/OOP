#include <iostream>
#include "CTVSet.h"
using namespace std;

const string ALREADY_ON = "Уже включен";
const string ALREADY_OFF = "Уже выключен";
const string OFF = "Телевизор выключен, ";
const string ON = "Телевизор включен, ";
const string CURRENT_CHANNEL = "текущий канал: ";
const string ERROR_CHOOSE = "В выключенном состоянии нельзя переключить канал";

int CTVSet::GetCurrentChannel() const {
	return m_currentChannel;
}

int CTVSet::GetPreviousChannel() const {
	return m_previousChannel;
}

bool CTVSet::IsEnabled() const {
	return m_turn;
}

void CTVSet::TurnOn() {
	if (!m_turn) {
		if (m_previousChannel == 0)
			m_currentChannel = 1;
		else m_currentChannel = m_previousChannel;
		m_turn = true;
	}
	else cout << ALREADY_ON << endl;
}

void CTVSet::TurnOff() {
	if (m_turn) {
		m_previousChannel = m_currentChannel;
		m_currentChannel = 0;
		m_turn = false;
	}
	else cout << ALREADY_OFF << endl;
}

void CTVSet::SelectChannel(int channel) {
	if (m_turn) {
		m_previousChannel = m_currentChannel;
		m_currentChannel = channel;
	}
	else cout << ERROR_CHOOSE << endl;
}

void CTVSet::Info() const {
	if (m_turn)
		cout << ON;
	else cout << OFF;

	cout << CURRENT_CHANNEL << m_currentChannel << endl;
}

void CTVSet::SelectPreviousChannel() {
	if (m_turn) {
		int temp;
		temp = m_currentChannel;
		m_currentChannel = m_previousChannel;
		m_previousChannel = temp;
	}
	else cout << ERROR_CHOOSE << endl;

}