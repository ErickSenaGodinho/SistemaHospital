#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include <queue>
#include "Attendance.hpp"

using namespace std;

class Hospital
{
private:
    Doctor doctors[5];
    vector<Attendance> running_attendances;
    priority_queue<Patient, vector<Patient>, GreaterThanByPriority> queue;
    unsigned int registered_doctors;
    unsigned int avaible_doctors;
    unsigned int treated_patients;

public:
    Hospital();
    ~Hospital();

    void setAvaibleDoctors(unsigned int avaible_doctors);

    Doctor *getDoctors() { return doctors; }
    vector<Attendance> &getRunningAttendances() { return running_attendances; }
    priority_queue<Patient, vector<Patient>, GreaterThanByPriority> &getQueue() { return queue; }
    unsigned int getRegisteredDoctors() const { return registered_doctors; }
    unsigned int getAvaibleDoctors() const { return avaible_doctors; }
    unsigned int getTreatedPatients() const { return treated_patients; }

    void initDoctors();
    void addDoctor(string name, string specialty, string crm);
    void addAttendance(Attendance &attendance);
    void increaseTreatedPatients();
};

#endif