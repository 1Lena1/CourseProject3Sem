#pragma once

#include <ostream>
#include "Ticket.h"

class Microbus : public Ticket {
private:
    int brand;
    int numberOfCompletedTrips;
public:
    Microbus(int sum = 0, int id = 0, int brand = 0, int numberOfCompletedTrips = 0);

    int getBrand() const;
    void setBrand(int brand);
    int getNumberOfCompletedTrips() const;
    void setNumberOfCompletedTrips(int numberOfCompletedTrips);

    friend std::istream &operator>>(std::istream &is, Microbus &microbus);
    friend std::ostream &operator<<(std::ostream &os, const Microbus &microbus);
};
