#pragma once
#include "Doctor.hpp"

Doctor::Doctor() {}

Doctor::Doctor(string name, string specialty, string crm) : name(name), specialty(specialty), crm(crm), avaible(true) {}

Doctor::~Doctor() {}

void Doctor::setAvaible(bool avaible)
{
    this->avaible = avaible;
}