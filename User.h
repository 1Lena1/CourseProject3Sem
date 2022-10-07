#pragma once

#include <iostream>
#include <string>

class User {
private:
    std::string username;
    std::string password;
    bool admin;
public:
    explicit User(std::string username = "", std::string password = "", bool admin = false);

    const std::string &getUsername() const;
    void setUsername(const std::string &username);
    const std::string &getPassword() const;
    void setPassword(const std::string &password);
    bool isAdmin() const;
    void setAdmin(bool admin);

    User& operator=(const User& user);

    friend std::ostream &operator<<(std::ostream &os, const User &user);
    friend std::istream &operator>>(std::istream &is, User &user);
};
