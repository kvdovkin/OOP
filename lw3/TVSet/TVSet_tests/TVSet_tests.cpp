#include <iostream>
#include "..\TVSet\CTVSet.h"
#include "Runner_tests.h"

TEST_CASE("TV tests")
{
	CTVSet tv;

	SECTION("Turn On") {
		tv.TurnOn();
		REQUIRE(tv.IsEnabled()== true);
	}

	SECTION("Turn On channel") {
		tv.TurnOn();
		REQUIRE(tv.GetCurrentChannel() == 1);
	}

	SECTION("Turn Off") {
		tv.TurnOn();
		tv.TurnOff();
		REQUIRE(tv.IsEnabled() == false);
	}

	SECTION("Turn Off channel") {
		tv.TurnOn();
		tv.TurnOff();
		REQUIRE(tv.GetCurrentChannel() == 0);
	}

	SECTION("Change channel") {
		tv.TurnOn();
		tv.SelectChannel(20);
		REQUIRE(tv.GetCurrentChannel() == 20);
	}

	SECTION("Change channel #2") {
		tv.TurnOn();
		tv.SelectChannel(99);
		REQUIRE(tv.GetCurrentChannel() == 99);
	}

	SECTION("Get previous channel") {
		tv.TurnOn();
		tv.SelectChannel(20);
		tv.SelectChannel(30);
		tv.SelectPreviousChannel();
		REQUIRE(tv.GetCurrentChannel() == 20);
	}
}