#include <iostream>
#include "Microbus.h"
#include "InputError.h"
using namespace Error;

Microbus::Microbus(int sum, int id, int brand, int numberOfCompletedTrips) : Ticket(sum,id), brand(brand),
    numberOfCompletedTrips(numberOfCompletedTrips) {
}

int Microbus::getBrand() const {
    return brand;
}

void Microbus::setBrand(int brand) {
    Microbus::brand = brand;
}

int Microbus::getNumberOfCompletedTrips() const {
    return numberOfCompletedTrips;
}

void Microbus::setNumberOfCompletedTrips(int numberOfCompletedTrips) {
    Microbus::numberOfCompletedTrips = numberOfCompletedTrips;
}

std::ostream &operator<<(std::ostream &os, const Microbus &microbus) {
    os << "№ бренда: " << microbus.brand << std::endl << "Количество выполненных поездок: "
       << microbus.numberOfCompletedTrips << std::endl;
    os << static_cast<const Ticket &>(microbus);
    return os;
}

std::istream &operator>>(std::istream &is, Microbus &microbus) {
    std::cout << "Введите номер бренда: ";
    microbus.brand = InputError::Input(1, 999);
    std::cout << "Введите количество поездок, выполненных микроавтобусом: ";
    microbus.numberOfCompletedTrips = InputError::Input(0, 1000);
    is >> dynamic_cast<Ticket&>(microbus);
    return is;
}
