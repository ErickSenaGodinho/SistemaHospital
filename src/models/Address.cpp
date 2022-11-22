#pragma once
#include "Address.hpp"

Address::Address() {}

Address::Address(string street, string district, string number) : street(street), district(district), number(number) {}

Address::~Address() {}

void Address::showData() const
{
    cout << "Street: " << this->street << endl;
    cout << "District: " << this->district << endl;
    cout << "Number: " << this->number << endl;
}
