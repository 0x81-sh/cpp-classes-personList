#pragma once
#include "Person.h"
#include <iostream>
#include <cstring>
#include <initializer_list>

class PersonList {
    private:
        Person **array;
        int length;

        void changeLength(int to);
        [[nodiscard]] bool checkBounds(int v) const;
    public:
        PersonList();
        PersonList(const std::initializer_list<const Person> &init);
        ~PersonList();
        PersonList(const PersonList &ref);

        [[nodiscard]] int getLength() const;
        [[nodiscard]] Person *getAt(int index) const;
        Person *operator[] (int index) const;

        void add(const Person &ref);
        void add(Person *ref);
        void removeAt(int index);
        [[nodiscard]] PersonList getPersonListFromWithZIP(const char* str) const;

        [[nodiscard]] bool flatcmp(const PersonList &ref) const;
};



