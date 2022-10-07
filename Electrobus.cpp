#include "Electrobus.h"
#include "InputError.h"

using namespace Error;

Electrobus::Electrobus(bool harmonic, bool ecological, bool wirelessCharger, int sum, int id, int numberOfSeats, int day, const char* features,
    int status, bool type) : Bus(sum, id, numberOfSeats,
        day, features, status, type), harmonic(harmonic), ecological(ecological), wirelessCharger(wirelessCharger) {
}

std::ostream& operator<<(std::ostream& os, const Electrobus& electrobus) {
    os << static_cast<const Bus&>(electrobus);
    os << "Дополнительно (1 - Есть. 0 - Нет)" << endl;
    os << "Наличие гармошки: " << electrobus.harmonic << endl;
    os << "Экологический: " << electrobus.ecological << endl;
    os << "Наличие беспроводной зарядки: " << electrobus.wirelessCharger << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Electrobus& electrobus) {
    is >> dynamic_cast<Bus&>(electrobus);
    std::cout << "Дополнительно (1 - Есть. 0 - Нет):" << endl;
    std::cout << "Есть ли гармошка: ";
    electrobus.harmonic = InputError::Input(0, 1);
    std::cout << "Является ли экологическим: ";
    electrobus.ecological = InputError::Input(0, 1);
    std::cout << "Есть ли беспроводная зарядка: ";
    electrobus.wirelessCharger = InputError::Input(0, 1);
    return is;
}