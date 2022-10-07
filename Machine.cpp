#include "Machine.h"
#include "InputError.h"
#include <cstring>
#include <iostream>

using namespace Error;

Machine::Machine(int sum, int id, int numberOfSeats, int day, const char *features) :
    Ticket(sum, id), numberOfSeats(numberOfSeats), day(day) {
    strcpy_s(this->features, features);
}

int Machine::getNumberOfSeats() const {
    return numberOfSeats;
}

void Machine::setNumberOfSeats(int numberOfSeats) {
    Machine::numberOfSeats = numberOfSeats;
}

int Machine::getDay() const {
    return day;
}

void Machine::setDay(int day) {
    Machine::day = day;
}

const char *Machine::getFeatures() const {
    return features;
}

void Machine::setFeatures(const char *features) {
    strcpy_s(Machine::features, features);
}

std::ostream &operator<<(std::ostream &os, const Machine &machine) {
    os << "Количество мест: " << machine.numberOfSeats << std::endl
       << "Срок эксплуатации: " << machine.day << std::endl << "Особенности использования: " << machine.features << std::endl;
    os << static_cast<const Ticket &>(machine);
    return os;
}

std::istream &operator>>(std::istream &is, Machine &machine) {
    std::cout << "Введите количество мест: ";
    machine.numberOfSeats = InputError::Input(0, 1000);
    std::cout << "Введите срок эксплуатации: ";
    machine.day = InputError::Input(0, 100);
    rewind(stdin);
    std::cout << "Введите особенности использования: ";
    is >> machine.features;
    is >> dynamic_cast<Ticket&>(machine);
    return is;
}

