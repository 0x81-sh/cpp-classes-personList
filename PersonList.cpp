#include "PersonList.h"

PersonList::PersonList() : length(0), array(nullptr) {}

PersonList::~PersonList() {
    for (int i = 0; i < length; i++) delete array[i];
    delete[] array;
}

PersonList::PersonList(const std::initializer_list<const Person> &init) : array(nullptr) {
    changeLength(init.size());
    for (int i = 0; i < length; i++) array[i] = new Person(*(init.begin() + i));
}

PersonList::PersonList(const PersonList &ref) : array(nullptr) {
    changeLength(ref.length);
    for (int i = 0; i < ref.length; i++) array[i] = new Person(*ref.array[i]);
}

int PersonList::getLength() const {
    return length;
}

void PersonList::changeLength(int to) {
    Person **temp = new Person*[to];
    if (array != nullptr) {
        if (to >= length) {
            for (int i = 0; i < length; i++) temp[i] = array[i];
            for (int i = length; i < to; i++) temp[i] = nullptr;
        } else {
            for (int i = 0; i < to; i++) temp[i] = array[i];
        }
    }

    delete[] array;
    array = temp;
    length = to;
}

Person *PersonList::getAt(int index) const {
    if (!checkBounds(index)) return nullptr;
    return array[index];
}

Person *PersonList::operator[](int index) const {
    return getAt(index);
}

void PersonList::add(const Person &ref) {
    add(new Person(ref));
}

void PersonList::add(Person *ref) {
    this->changeLength(length + 1);
    array[length - 1] = ref;
}

void PersonList::removeAt(int index) {
    if (!checkBounds(index)) return;

    delete array[index];
    for (int i = index; i < length; i++) array[index] = array[index + 1];

    changeLength(length - 1);
}

PersonList PersonList::getPersonListFromWithZIP(const char* str) const {
    PersonList filtered;
    for (int i = 0; i < length; i++) if (strcmp(str, array[i]->getAddress().getZip()) == 0) filtered.add(*array[i]);
    return filtered;
}

bool PersonList::checkBounds(int v) const {
    return v < length && v >= 0;
}

bool PersonList::flatcmp(const PersonList &ref) const {
    if (length != ref.length) return false;
    for (int i = 0; i < length; i++) {
        if (strcmp(array[i]->getName(), ref.array[i]->getName()) != 0) return false;
    }

    return true;
}
