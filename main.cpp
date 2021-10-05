#include "PersonList.h"
#include <cassert>
#include <iostream>
#include <cstring>

void testProperties(const PersonList &original, const char *name1, const Address &address1);
void test_add(const PersonList &original, const Person &add, const PersonList &result);
void test_removeAt(const PersonList &original, int index, const PersonList &result);
void test_getPersonListFromWithZIP(const PersonList &list, const char *filter, const PersonList &filtered);

int main() {
    //some data
    Address address1("Churdan", "IA 50050", "Hazelwood Avenue", 1941);
    Person person1("Gale J. Dorsey", address1);
    Address address2("Marquette", "MI 49855", "Railroad Street", 3481);
    Person person2("Dudley S. Martin", address2);

    //tests
    testProperties(
        PersonList({person1}),
        person1.getName(),
        address1
    );

    test_add(
        PersonList({person1}),
        person2,
        PersonList({person1, person2})
    );

    test_removeAt(
        PersonList({person1, person2, person1}),
        1,
        PersonList({person1, person1})
    );

    test_getPersonListFromWithZIP(
        PersonList({person1, person2, person1, person2}),
        "MI 49855",
        PersonList({person2, person2})
    );

    return 0;
}

void testProperties(const PersonList &original, const char *name1, const Address &address1) {
    assert(strcmp(original[0]->getName(), name1) == 0);

    const Address &address = original[0]->getAddress();
    assert(address.getNumber() == address1.getNumber());
    assert(strcmp(address.getZip(), address1.getZip()) == 0);
    assert(strcmp(address.getCity(), address1.getCity()) == 0);
    assert(strcmp(address.getStreet(), address1.getStreet()) == 0);
}

void test_add(const PersonList &original, const Person &add, const PersonList &result) {
    PersonList modified = original;
    modified.add(add);

    assert(result.flatcmp(modified));
}

void test_removeAt(const PersonList &original, int index, const PersonList &result) {
    PersonList modified = original;
    modified.removeAt(index);

    assert(result.flatcmp(modified));
}

void test_getPersonListFromWithZIP(const PersonList &list, const char *filter, const PersonList &filtered) {
    PersonList res = list.getPersonListFromWithZIP(filter);

    assert(filtered.flatcmp(res));
}