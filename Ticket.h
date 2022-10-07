#pragma once

#include "InputError.h"
#include <iostream>

using namespace Error;

class Ticket {
protected:
    int sum;
    int id;
public:
    Ticket(int sum = 0, int id = 0);

    int getSum() const;
    void setSum(int sum);
    int getId() const;
    void setId(int id);

    friend std::istream &operator>>(std::istream &is, Ticket &ticket);
    friend std::ostream &operator<<(std::ostream &os, const Ticket &ticket);
};
