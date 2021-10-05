#pragma once
#include <cstring>
#include <ostream>

class Address {
    private:
        char *city;
        char *zip;
        char *street;
        int number;

        void alloc(const char *city, const char *zip, const char *street);
    public:
        Address(const char *city, const char *zip, const char *street, int number);
        ~Address();
        Address(const Address &ref);

        [[nodiscard]] const char *getCity() const;
        [[nodiscard]] const char *getZip() const;
        [[nodiscard]] const char *getStreet() const;
        [[nodiscard]] int getNumber() const;

        friend std::ostream &operator<<(std::ostream &os, const Address &address);
};



