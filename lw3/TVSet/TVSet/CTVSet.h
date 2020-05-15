#pragma once

class CTVSet {
public:

	int GetCurrentChannel() const;

	int GetPreviousChannel() const;

	bool IsEnabled() const;

	void TurnOn();

	void TurnOff();

	void SelectChannel(int channel);

	void Info() const;

	void SelectPreviousChannel();

private:
	int m_currentChannel = 0;
	int m_previousChannel = 1;
	bool m_turn = false;
};