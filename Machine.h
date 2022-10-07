#pragma once

#include <ostream>
#include "Ticket.h"

class Machine : public Ticket {
protected:
    int numberOfSeats;
    int day;
    char features[50];
public:
    Machine(int sum = 0, int id = 0, int numberOfSeats = 0, int day = 0,
            const char *features = "");

    int getNumberOfSeats() const;
    void setNumberOfSeats(int numberOfSeats);
    int getDay() const;
    void setDay(int day);
    const char* getFeatures() const;
    void setFeatures(const char *features);

    friend std::istream &operator>>(std::istream &is, Machine &machine);
    friend std::ostream &operator<<(std::ostream &os, const Machine &machine);
};
