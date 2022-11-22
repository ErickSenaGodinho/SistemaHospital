#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

using namespace std;

class Doctor
{
private:
    string name;
    string specialty;
    string crm;
    bool avaible;

public:
    Doctor();
    Doctor(string name, string specialty, string crm);
    ~Doctor();

    void setAvaible(bool avaible);

    string getName() const { return name; }
    bool isAvaible() const { return avaible; }
};

#endif