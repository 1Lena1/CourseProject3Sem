#pragma once

#include <string>
#include <ostream>

class Trip {
private:
    std::string destination;
    int way;
    int day;
    int number;
public:
    Trip(const std::string &destination = "", int way = 0, int day = 0, int number = 0);

    const std::string &getDestination() const;
    void setDestination(const std::string &destination);
    int getWay() const;
    void setWay(int way);
    int getDay() const;
    void setDay(int day);
    int getNumber() const;
    void setNumber(int number);

    friend std::ostream &operator<<(std::ostream &os, const Trip &trip);
    friend std::istream &operator>>(std::istream &is, Trip &trip);
};
