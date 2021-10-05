#include "Person.h"

Person::Person(const char *name, const Address &address) : address(address) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::~Person() {
    delete[] this->name;
}

Person::Person(const Person &ref) : address(ref.address) {
    this->name = new char[strlen(ref.name) + 1];
    strcpy(this->name, ref.name);
}

const char *Person::getName() const {
    return name;
}

const Address &Person::getAddress() const {
    return address;
}
