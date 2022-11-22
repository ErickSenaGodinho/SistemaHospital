#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address
{
private:
    string street;
    string district;
    string number;

public:
    Address();
    Address(string street, string district, string number);
    ~Address();

    void showData() const;
};

#endif