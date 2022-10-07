#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Trip.h"
#include "InputError.h"

using namespace Error;

Trip::Trip(const std::string &destination, int way, int day, int number) : destination(destination),
                                                                                            way(way),
                                                                                            day(day),
                                                                                            number(number) {}

const std::string &Trip::getDestination() const {
    return destination;
}

void Trip::setDestination(const std::string &destination) {
    Trip::destination = destination;
}

int Trip::getWay() const {
    return way;
}

void Trip::setWay(int way) {
    Trip::way = way;
}

int Trip::getDay() const {
    return day;
}

void Trip::setDay(int day) {
    Trip::day = day;
}

int Trip::getNumber() const {
    return number;
}

void Trip::setNumber(int number) {
    Trip::number = number;
}

std::ostream &operator<<(std::ostream &os, const Trip &trip) {
    os << std::setw(20) << trip.destination << "|" << std::setw(14) << trip.way << "|" << std::setw(4) << trip.day;
    return os;
}

std::istream &operator>>(std::istream &is, Trip &trip) {
    std::cout << "Введите пункт назначения: ";
	rewind(stdin);
    getline(is, trip.destination);
    std::cout << "Введите дальность пути (км): ";
    trip.way = InputError::Input(0, 10000);
    std::cout << "Введите номер дня: ";
    trip.day = InputError::Input(1, 31);
    trip.number = abs(2 * trip.way - trip.day * trip.day);
    return is;
}
