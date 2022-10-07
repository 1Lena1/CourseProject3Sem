#pragma once

#define KEY 5

#include "InputError.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "List.h"
#include "User.h"
#include "ListException.h"
#include "File.h"

using namespace Error;

template <class T>
class Algorithm {
public:
    static void registration();
    static User* authorization();
    static void add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action);
    static void remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action);
    static void update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
    static void giveAdminRole(List<T>& list);

    static void pay();
};

template<class T>
void Algorithm<T>::add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action) {
    //system("cls");
    T tmp;
    std::cin >> tmp;
    list.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);
    action.insert(action.end(), 1);
    system("pause");
}

template<class T>
void Algorithm<T>::remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action) {
    //system("cls");
    if (list.size() == 0) {
        throw ListException(1);
    } else {
		std::cout << "Введите номер элемента для удаления: ";
		int num;
		num = InputError::Input(1, list.size());
        T tmp = list[num - 1];
        returnPrev.insert(returnPrev.end(), tmp);
        action.insert(action.end(), 2);
        list.pop(num);
    }
    system("pause");
}

template<class T>
void Algorithm<T>::update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    //system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    list.output();
    std::cout << std::endl;
    std::cout << "Введите номер изменяемой машины : ";
    int tempNum = InputError::Input(1, list.size());
    T tmp;
    std::cin >> tmp;
    returnPrev.insert(returnPrev.end(), list[tempNum - 1]);
    action.insert(action.end(), 3);
    place.insert(place.end(), tempNum);
    list[tempNum - 1] = tmp;
    system("pause");
}

template<class T>
void Algorithm<T>::sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    //system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    list.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать:" << std::endl;
    std::cout << "1. По ID по возрастанию." << std::endl;
    std::cout << "2. По ID по убыванию." << std::endl;
    std::cout << "3. По оплате по возрастанию." << std::endl;
    std::cout << "4. По оплате по убыванию." << std::endl;
    int type = InputError::Input(1, 4);
    list.sort(type);
	list.output();
}

template<class T>
void Algorithm<T>::cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
    if (!action.size()) {
        //system("cls");
        throw ListException(2);
    }
    switch (action.back()) {
        case 1: {
            list.popTail();
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 2: {
            list.pushTail(returnPrev.back());
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 3: {
            list[place.back() - 1] = returnPrev.back();
            place.erase(place.end() - 1);
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
    }
}

template<class T>
User* Algorithm<T>::authorization() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    char BUFFER[20], c;
    std::string username, password;
    std::cout << "Введите логин: ";
    std::cin >> username;
    std::cout << "Введите пароль: ";
    int i = 0;
	while ((c = _getch()) != '\r') {
		_putch('*');
		BUFFER[i] = c;
		i++;
	}
	BUFFER[i] = '\0';
	for (int j = 0; j < i; j++) {
		BUFFER[j] = 6 * BUFFER[j] + (BUFFER[j] / 6);
	}
    password = std::string(BUFFER);
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            return new User(users[i]);
        }
    }
    std::cout << "Неверный пользователь или пароль!" << std::endl;
    return nullptr;
}

template<class T>
void Algorithm<T>::registration() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    User newUser;
    std::cin >> newUser;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == newUser.getUsername() && users[i].getPassword() == newUser.getPassword()
                    && newUser.isAdmin() != users[i].isAdmin()) {
            std::cout << "Данный пользователь уже существует!" << std::endl;
            return;
        }
    }
    users.pushTail(newUser);
    File<User>::saveUser(users, "users.txt");
}

template<class T>
void Algorithm<T>::giveAdminRole(List<T> &list) {
    list.output();
    std::cout << std::endl;
    std::cout << "Введите номер пользователя для предоставления прав администратора : ";
    int tempNum = InputError::Input(1, list.size());
    list[tempNum - 1].setAdmin(1);
}

template<class T>
void Algorithm<T>::pay() {
    std::cout << "Заполните форму!" << std::endl;
    Trip trip;
    std::cin >> trip;
    List<Trip> tripList;
    File<Trip>::openTrip(tripList, "trip.txt");
    tripList.pushTail(trip);
    File<Trip>::saveTrip(tripList, "trip.txt");
    std::cout << "Форма заполнена успешно!" << std::endl;
}
