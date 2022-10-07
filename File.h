#pragma once

#include "Electrobus.h"
#include "List.h"
#include "Machine.h"
#include "Bus.h"
#include "Microbus.h"
#include "Trip.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

template <class T>
class File {
public:
    File() = default;
    ~File() = default;

    static void openUser(List<T>& list, const char *file);
    static void openMachine(List<T>& list, const char *file);
    static void openBus(List<T>& list, const char* file);
    static void openElectrobus(List<T>& list, const char *file);
    static void openMicrobus(List<T>& list, const char *file);
    static void openTrip(List<T>& list, const char *file);

    static void saveTrip(List<T>& list, const char *file);
    static void saveUser(List<T>& list, const char *file);
    static void saveMachine(List<T>& list, const char *file);
    static void saveBus(List<T>& list, const char* file);
    static void saveElectrobus(List<T>& list, const char *file);
    static void saveMicrobus(List<T>& list, const char *file);
};

template<class T>
void File<T>::openUser(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[20];
    int val3;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        std::string val1(BUFFER);
        i = 0;
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        std::string val2(BUFFER);
        in >> val3;
        T t(val1, val2, val3);
        list.pushTail(t);
    }
    in.close();
}

template<class T>
void File<T>::openMachine(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[50];
    char val5[50];
    int val1, val2, val3, val4;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        strcpy_s(val5, BUFFER);
        in.get();
        in >> val1 >> val2 >> val3 >> val4;
        Machine machine(val1, val2, val3, val4, val5);
        list.pushTail(machine);
    }
    in.close();
}

template<class T>
void File<T>::openBus(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[50];
    char val5[50];
    int val1, val2, val3, val4, val6;
    bool val7;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        strcpy_s(val5, BUFFER);
        in.get();
        in >> val1 >> val2 >> val3 >> val4 >> val6 >> val7;
        Bus bus(val1, val2, val3, val4, val5, val6, val7);
        list.pushTail(bus);
    }
    in.close();
}

template<class T>
void File<T>::openElectrobus(List<T>& list, const char* file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[50];
    char val5[50];
    int val1, val2, val3, val4, val6;
    bool val7, val8, val9, val10;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        strcpy_s(val5, BUFFER);
        in.get();
        in >> val1 >> val2 >> val3 >> val4 >> val6 >> val7 >> val8 >> val9 >> val10;
        Electrobus bus(val8, val9, val10, val1, val2, val3, val4, val5, val6, val7);
        list.pushTail(bus);
    }
    in.close();
}

template<class T>
void File<T>::openMicrobus(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    int val1, val2, val3, val4;
    while (EOF | in.failbit) {
        in >> val1;
        if (in.failbit) {
            in.clear();
            break;
        }
        in >> val2 >> val3 >> val4;
        Microbus microbus(val1, val2, val3, val4);
        list.pushTail(microbus);
        in.get();
    }
    in.close();
}

template<class T>
void File<T>::saveUser(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getUsername() << "|" << list[i].getPassword() << "|" << list[i].isAdmin();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveMachine(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getFeatures() << "| " << list[i].getSum() << " " << list[i].getId() << " " <<
            list[i].getNumberOfSeats() << " " << list[i].getDay();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveBus(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getFeatures() << "| " << list[i].getSum() << " " << list[i].getId() << " " <<
           list[i].getNumberOfSeats() << " " << list[i].getDay() << " " << list[i].getStatus()
           << " " << list[i].isType();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveElectrobus(List<T>& list, const char* file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getFeatures() << "| " << list[i].getSum() << " " << list[i].getId() << " " <<
            list[i].getNumberOfSeats() << " " << list[i].getDay() << " " << list[i].getStatus()
            << " " << list[i].isType() << " " << list[i].isHarmonic() << " " << list[i].isEcological() << " " << list[i].isWirelessCharger();
        on << std::endl;
    }
    on << "%";
    on.close();
}


template<class T>
void File<T>::saveMicrobus(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSum() << " " << list[i].getId() << " " <<
           list[i].getBrand() << " " << list[i].getNumberOfCompletedTrips();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::openTrip(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    rewind(stdin);
    std::string val1;
    int val2, val3, val4;
    while (EOF) {
        getline(in, val1);
        if (!in || val1.empty() || val1 == "%") {
            in.clear();
            break;
        }
        in >> val2 >> val3 >> val4;
        Trip trip(val1, val2, val3, val4);
        list.pushTail(trip);
        in.get();
    }
    in.close();
}

template<class T>
void File<T>::saveTrip(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
		on << list[i].getDestination() << "\n" << list[i].getWay() << " " << list[i].getDay() << " " <<
        list[i].getNumber();
        on << std::endl;
    }
    on << "%";
    on.close();
}
