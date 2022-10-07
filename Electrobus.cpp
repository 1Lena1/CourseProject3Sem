#include "Electrobus.h"
#include "InputError.h"

using namespace Error;

Electrobus::Electrobus(bool harmonic, bool ecological, bool wirelessCharger, int sum, int id, int numberOfSeats, int day, const char* features,
    int status, bool type) : Bus(sum, id, numberOfSeats,
        day, features, status, type), harmonic(harmonic), ecological(ecological), wirelessCharger(wirelessCharger) {
}

std::ostream& operator<<(std::ostream& os, const Electrobus& electrobus) {
    os << static_cast<const Bus&>(electrobus);
    os << "������������� (1 - ����. 0 - ���)" << endl;
    os << "������� ��������: " << electrobus.harmonic << endl;
    os << "�������������: " << electrobus.ecological << endl;
    os << "������� ������������ �������: " << electrobus.wirelessCharger << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Electrobus& electrobus) {
    is >> dynamic_cast<Bus&>(electrobus);
    std::cout << "������������� (1 - ����. 0 - ���):" << endl;
    std::cout << "���� �� ��������: ";
    electrobus.harmonic = InputError::Input(0, 1);
    std::cout << "�������� �� �������������: ";
    electrobus.ecological = InputError::Input(0, 1);
    std::cout << "���� �� ������������ �������: ";
    electrobus.wirelessCharger = InputError::Input(0, 1);
    return is;
}