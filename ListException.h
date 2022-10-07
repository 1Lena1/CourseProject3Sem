#pragma once
#include <iostream>
#include "MyException.h"

class ListException : MyException {
public:
    explicit ListException(int code = 0) : MyException(code) {};
    void ErrorText() override;
};

void ListException::ErrorText() {
    std::cout << "Ошибка (код " << code << "): " << std::endl;
    switch (code) {
        case 1: {
            std::cout << "Список пуст" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Невозможно отменить действие.";
            std::cout << " Все возможные последние действия cо студентами отменены." << std::endl;
            break;
        }
    }
}