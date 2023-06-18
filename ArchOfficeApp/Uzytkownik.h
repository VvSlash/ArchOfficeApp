#pragma once
#include <iostream>
#include <string>
class Uzytkownik
{
protected:
    std::string username;
    std::string password;
    std::string email;
    int age;

public:
    Uzytkownik(const std::string& username, const std::string& password, const std::string& email, int age)
        : username(username), password(password), email(email), age(age) {}

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }

    std::string getEmail() const {
        return email;
    }

    int getAge() const {
        return age;
    }
};

