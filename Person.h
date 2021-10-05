#pragma once
#include "Address.h"
#include <cstring>

class Person {
    private:
        char* name;
        Address address;
    public:
        Person(const char *name, const Address &address);
        ~Person();
        Person(const Person &ref);

        [[nodiscard]] const char *getName() const;
        [[nodiscard]] const Address &getAddress() const;
};



