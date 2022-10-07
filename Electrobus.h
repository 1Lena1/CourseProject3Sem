#pragma once
#include "Bus.h"
class Electrobus :
	public Bus
{
private:
	bool harmonic;
	bool ecological;
	bool wirelessCharger;
public:
	explicit Electrobus(bool harmonic = false, bool ecological = false, bool wirelessCharger = false, int sum = 0, int id = 0, int numberOfSeats = 0, int day = 0,
		const char* features = "", int status = 0, bool type = false);

	bool isHarmonic() { return harmonic; }
	bool isEcological() { return ecological; }
	bool isWirelessCharger() { return wirelessCharger; }

	friend istream& operator>>(std::istream& is, Electrobus& electrobus);
	friend ostream& operator<<(std::ostream& os, const Electrobus& electrobus);
};

