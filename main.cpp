#include <iostream>
#include "Interface.h"
#include "Machine.h"
#include "Windows.h"
#include "File.h"
#include "Bus.h"
#include "Microbus.h"
using namespace Error;

int main() {
    system("Color 75");
    SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
    int select;
    User* user = Interface<User>::authorization();
    if (user == nullptr) {
        return 0;
    }
    if (user->isAdmin()) {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Машины." << std::endl;
            std::cout << "2. Автобусы." << std::endl;
            std::cout << "3. Микробусы." << std::endl;
            std::cout << "4. Электробусы." << std::endl;
            std::cout << "5. Выход." << std::endl;
            select = InputError::Input(1, 5);
            switch (select) {
                case 1: {
                    List<Machine> list;
                    File<Machine>::openMachine(list, "machine.txt");
                    Interface<Machine>::adminMenu(list);
                    File<Machine>::saveMachine(list, "machine.txt");
                    break;
                }
                case 2: {
                    List<Bus> list;
                    File<Bus>::openBus(list, "bus.txt");
                    Interface<Bus>::adminMenu(list);
                    File<Bus>::saveBus(list, "bus.txt");
                    break;
                }
                case 3: {
                    List<Microbus> list;
                    File<Microbus>::openMicrobus(list, "microbus.txt");
                    Interface<Microbus>::adminMenu(list);
                    File<Microbus>::saveMicrobus(list, "microbus.txt");
                    break;
                }
                case 4: {
                    List<Electrobus> list;
                    File<Electrobus>::openElectrobus(list, "electrobus.txt");
                    Interface<Electrobus>::adminMenu(list);
                    File<Electrobus>::saveElectrobus(list, "electrobus.txt");
                    break;
                }
                case 5: {
                    return 0;
                }
            }
        }
    } else {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Машины." << std::endl;
            std::cout << "2. Автобусы." << std::endl;
            std::cout << "3. Микробусы." << std::endl;
            std::cout << "4. Электробусы." << std::endl;
            std::cout << "5. Выход." << std::endl;
            select = InputError::Input(1, 5);
            switch (select) {
                case 1: {
                    List<Machine> list;
                    File<Machine>::openMachine(list, "machine.txt");
                    Interface<Machine>::menu(list);
                    File<Machine>::saveMachine(list, "machine.txt");
                    break;
                }
                case 2: {
                    List<Bus> list;
                    File<Bus>::openBus(list, "bus.txt");
                    Interface<Bus>::menu(list);
                    File<Bus>::saveBus(list, "bus.txt");
                    break;
                }
                case 3: {
                    List<Microbus> list;
                    File<Microbus>::openMicrobus(list, "microbus.txt");
                    Interface<Microbus>::menu(list);
                    File<Microbus>::saveMicrobus(list, "microbus.txt");
                    break;
                }
                case 4: {
                    List<Electrobus> list;
                    File<Electrobus>::openElectrobus(list, "electrobus.txt");
                    Interface<Electrobus>::menu(list);
                    File<Electrobus>::saveElectrobus(list, "electrobus.txt");
                    break;
                }
                case 5: {
                    return 0;
                }
            }
        }
    }
    return 0;
}