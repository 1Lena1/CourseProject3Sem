#include <iostream>
#include "Ticket.h"

Ticket::Ticket(int sum, int id) : sum(sum), id(id) {
}

int Ticket::getSum() const {
    return sum;
}

void Ticket::setSum(int sum) {
    Ticket::sum = sum;
}

int Ticket::getId() const {
    return id;
}

void Ticket::setId(int id) {
    Ticket::id = id;
}

std::ostream &operator<<(std::ostream &os, const Ticket &ticket) {
    os << "Сумма оплаты: " << ticket.sum << std::endl << "Номер: " << ticket.id << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Ticket &ticket) {
    std::cout << "Введите ID номер: ";
    ticket.id = InputError::Input(100000, 999999);
    std::cout << "Введите сумму оплаты: ";
    ticket.sum = InputError::Input(0, 1000000);
    return is;
}
