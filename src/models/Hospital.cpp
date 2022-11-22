#pragma once
#include "Hospital.hpp"

Hospital::Hospital() : registered_doctors(0), avaible_doctors(0), treated_patients(0) {}

Hospital::~Hospital() {}

void Hospital::setAvaibleDoctors(unsigned int avaible_doctors)
{
    this->avaible_doctors = avaible_doctors;
}

void Hospital::initDoctors()
{
    addDoctor("Geziel", "Surgery", "400289220-18");
    addDoctor("Ulisses", "Urology", "742832773-24");
    addDoctor("Marcos", "Anesthesiology", "824320821-65");
    addDoctor("Rayner", "Dermatology", "286257429-26");
    addDoctor("André", "Neurology", "392143259-00");
}

void Hospital::addDoctor(string name, string specialty, string crm)
{
    this->doctors[this->registered_doctors] = Doctor(name, specialty, crm);
    this->registered_doctors++;
    this->avaible_doctors++;
}

void Hospital::addAttendance(Attendance &attendance)
{
    this->running_attendances.push_back(attendance);
}

void Hospital::increaseTreatedPatients()
{
    this->treated_patients++;
}
