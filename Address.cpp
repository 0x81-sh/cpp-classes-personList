#include "Address.h"

Address::Address(const char *city, const char *zip, const char *street, int number) : number(number) {
    alloc(city, zip, street);
}

Address::Address(const Address &ref) : number(ref.number) {
    alloc(ref.city,ref.zip, ref.street);
}

void Address::alloc(const char *city, const char *zip, const char *street) {
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);

    this->zip = new char[strlen(zip) + 1];
    strcpy(this->zip, zip);

    this->street = new char[strlen(street) + 1];
    strcpy(this->street, street);
}

Address::~Address() {
    delete[] city;
    delete[] zip;
    delete[] street;
}

const char *Address::getCity() const {
    return city;
}

const char *Address::getZip() const {
    return zip;
}

const char *Address::getStreet() const {
    return street;
}

int Address::getNumber() const {
    return number;
}

std::ostream &operator<<(std::ostream &os, const Address &address) {
    os << "{ city: \"" << address.city << "\", zip: \"" << address.zip << "\", street: \"" << address.street << "\", number: "
       << address.number << " }";
    return os;
}
