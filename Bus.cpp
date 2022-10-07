#include <iostream>
#include "Bus.h"
#include "InputError.h"
using namespace Error;

Bus::Bus(int sum, int id, int numberOfSeats, int day, const char *features,
                       int status, bool type) : Machine(sum, id, numberOfSeats,
                               day, features), status(status), type(type) {
}

int Bus::getStatus() const {
    return status;
}

void Bus::setStatus(int status) {
    Bus::status = status;
}

bool Bus::isType() const {
    return type;
}

void Bus::setType(bool type) {
    Bus::type = type;
}

std::ostream &operator<<(std::ostream &os, const Bus &bus) {
    os << "Статус (1. На базе. 2. В рейсе. 3. В ремонте. 4. Списан.): " << bus.status << std::endl
       << "Тип автобуса (0 - Мягкий, 1 - Жёсткий): " << bus.type << std::endl
       << static_cast<const Machine &>(bus);
    return os;
}

std::istream &operator>>(std::istream &is, Bus &bus) {
    std::cout << "Введите статус автобуса (1. На базе. 2. В рейсе. 3. В ремонте. 4. Списан.): ";
    bus.status = InputError::Input(1, 4);
    std::cout << "Введите тип автобуса (0 - Мягкий, 1 - Жёсткий): ";
    bus.type = InputError::Input(0, 1);
    is >> dynamic_cast<Machine&>(bus);
    return is;
}
