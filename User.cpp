#define KEY 6

#include <conio.h>
#include "User.h"
#include "InputError.h"

User::User(std::string username, std::string password, bool admin) : username(username), password(password) , admin(admin) {
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}

bool User::isAdmin() const {
    return admin;
}

void User::setAdmin(bool admin) {
    User::admin = admin;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "Имя пользователя: " << user.username << std::endl << "Пароль: " << user.password << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, User &user) {
    rewind(stdin);
    std::cout << "Введите имя пользователя: ";
    is >> user.username;
    std::cout << "Введите пароль: ";
	char BUFFER[20], c;
	int i = 0;
	while ((c = _getch()) != '\r') {
		_putch('*');
		BUFFER[i] = c;
		i++;
	}
	BUFFER[i] = '\0';
	for (int j = 0; j < i; j++) {
		BUFFER[j] = KEY;
	}
	user.password = std::string(BUFFER);
    user.admin = false;
    return is;
}

User &User::operator=(const User &user) {
    this->username = user.username;
    this->password = user.password;
    this->admin = user.admin;
    return *this;
}
