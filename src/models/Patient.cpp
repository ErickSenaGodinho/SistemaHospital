#pragma once
#include "Patient.hpp"

Patient::Patient() {}

Patient::Patient(string name, Address address, unsigned int age, unsigned int gender)
{
    this->id = ++static_id;
    this->name = name;
    this->address = address;
    this->age = age;
    this->gender = gender;
    this->attended = false;
}

Patient::~Patient() {}

void Patient::setScreening(Screening screening)
{
    this->screening = screening;
}

void Patient::setAttended(bool attended)
{
    this->attended = attended;
}

void Patient::showData() const
{
    cout << "Name: " << this->name << endl;
    this->address.showData();
    cout << "Age: " << this->age << endl;
    cout << "Gender: " << this->gender << endl;
    cout << "Priority: " << this->getPriority().getName() << endl;
    cout << "\n";
}
