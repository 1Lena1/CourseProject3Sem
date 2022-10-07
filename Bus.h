#pragma once

#include <ostream>
#include "Machine.h"

class Bus : public Machine {
protected:
    int status;
    bool type;
public:
    Bus(int sum = 0, int id = 0, int numberOfSeats = 0, int day = 0,
               const char *features = "", int status = 0, bool type = false);

    int getStatus() const;
    void setStatus(int status);
    bool isType() const;
    void setType(bool type);

    friend std::istream &operator>>(std::istream &is, Bus &bus);
    friend std::ostream &operator<<(std::ostream &os, const Bus &bus);
};
