#pragma once

#include "List.h"
#include "Algorithm.h"
#include <iostream>
#include <string>
#include <vector>
#include "InputError.h"
#include "ListException.h"
#include "User.h"
using namespace Error;

template<class T>
class Interface {
public:
    static void menu(List<T>& list);
    static void adminMenu(List<T>& list);
    static User* authorization();
};

template<class T>
void Interface<T>::menu(List<T>& list) {
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<int> place;
    int select = 0;
    do {
        //system("cls");
        std::cout << "Вас приветствует система автобусного парка!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить машину в систему" << std::endl;
        std::cout << "2. Посмотреть список машин" << std::endl;
        std::cout << "3. Удалить последнюю машину из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретной машине" << std::endl;
        std::cout << "5. Отмена предыдущего действия с машинами" << std::endl;
        std::cout << "6. Отсортировать список машин" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 6);
            switch (select) {
                case 1:
                {
                    //system("cls");
                    Algorithm<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2:
                {
                    //system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    //system("cls");
                    Algorithm<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4:
                {
                    //system("cls");
                    Algorithm<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5:
                {
                    //system("cls");
                    Algorithm<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6:
                {
                    //system("cls");
                    Algorithm<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
            }
        }
        catch (ListException e) {
            e.ErrorText();
            system("pause");
            std::cin.sync();
            std::cin.clear();
            rewind(stdin);
        }
    } while (select != 0);
}

template<class T>
User* Interface<T>::authorization() {
    int select = 0;
    do {
        //system("cls");
        std::cout << "Вас приветствует система автобусного парка!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Авторизация в систему" << std::endl;
        std::cout << "2. Регистрация нового пользователя" << std::endl;
        std::cout << "3. Оформить путёвку" << std::endl;
        std::cout << "4. Выход из системы" << std::endl;
        select = InputError::Input(1, 4);
        switch (select) {
            case 1: {
                User *currentUser = Algorithm<User>::authorization();
                if (currentUser != nullptr) {
                    return currentUser;
                }
                break;
            }
            case 2: {
                system("cls");
                Algorithm<User>::registration();
                break;
            }
            case 3: {
                Algorithm<Trip>::pay();
                break;
            }
            case 4: exit(0);
        }
    } while (select != 4);
}

template<class T>
void Interface<T>::adminMenu(List<T>& list) {
    List<User> userList;
    File<User>::openUser(userList, "users.txt");
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<User> ReturnPrevForUsers;
    std::vector<int> actionOfUsers;
    std::vector<int> place;
    int select = 0;
    do {
        //system("cls");
        std::cout << "Вас приветствует система автобусного парка!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить машину в систему" << std::endl;
        std::cout << "2. Посмотреть список машин" << std::endl;
        std::cout << "3. Удалить последнюю машину из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретной машине" << std::endl;
        std::cout << "5. Отмена предыдущего действия с машинами" << std::endl;
        std::cout << "6. Отсортировать список машин" << std::endl;
        std::cout << "7. Добавить пользователя" << std::endl;
        std::cout << "8. Просмотреть список пользователей" << std::endl;
        std::cout << "9. Удалить пользователя" << std::endl;
        std::cout << "10. Назначить пользователя администратором" << std::endl;
        std::cout << "11. Удалить путёвку" << std::endl;
        std::cout << "12. Просмотреть путёвки" << std::endl;
		std::cout << "13. Поиск машины по номеру" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 16);
            switch (select) {
                case 1:
                {
                    //system("cls");
                    Algorithm<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2:
                {
                    //system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    //system("cls");
                    Algorithm<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4:
                {
                    //system("cls");
                    Algorithm<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5:
                {
                    //system("cls");
                    Algorithm<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6:
                {
                    //system("cls");
                    Algorithm<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
                case 7: {
                    //system("cls");
                    Algorithm<User>::add(userList, ReturnPrevForUsers, actionOfUsers);
                    File<User>::saveUser(userList, "users.txt");
                    break;
                }
                case 8: {
                    //system("cls");
                    if (userList.size() == 0) {
                        throw ListException(1);
                    } else {
                        userList.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 9: {
                    //system("cls");
					if (userList.size() == 0) {
						throw ListException(1);
					}
					else {
						userList.output();
						std::cout << std::endl;
						std::cout << "Введите номер пользователя для удаления : ";
						int tempNum = InputError::Input(1, userList.size());
						userList.pop(tempNum - 1);
						File<User>::saveUser(userList, "users.txt");
						system("pause");
					}
                    break;
                }
                case 10: {
                    //system("cls");
                    Algorithm<User>::giveAdminRole(userList);
                    File<User>::saveUser(userList, "users.txt");
                    break;
                }
                case 11:
                {
                    List<Trip> tripList;
                    File<Trip>::openTrip(tripList, "trip.txt");
                    tripList.popTail();
                    File<Trip>::saveTrip(tripList, "trip.txt");
                    break;
                }
                case 12:
                {
                    List<Trip> tripList;
                    File<Trip>::openTrip(tripList, "trip.txt");
					std::cout << "№ |  Пункт назначения  |Дальность пути|День\n";
                    tripList.output();
                    break;
                }
				case 13:
				{
					if (list.size() == 0) {
						throw ListException(1);
					}
					else {
						list.output();
						std::cout << std::endl << "Введите номер для поиска: ";
						int id = InputError::Input(100000, 999999);
						bool flag = false;
						for (int i = 0; i < list.size(); i++) {
							if (list[i].getId() == id) {
								flag = true;
							std:cout << list[i];
							}
						}
						if (!flag) {
							std::cout << "Ничего не найдено!" << std::endl;
						}
						system("pause");
					}
					break;
				}
            }
        }
        catch (ListException e) {
            e.ErrorText();
            system("pause");
            std::cin.sync();
            std::cin.clear();
            rewind(stdin);
        }
    } while (select != 0);
}