#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <chrono>
#include "Doctor.cpp"
#include "Patient.cpp"

using namespace std;

class Attendance
{
private:
    Doctor *doctor;
    Patient patient;
    tm start_time;
    tm end_time;

    void setStartTime(time_t start_date);
    time_t calculateEndDate(time_t actual_date);
    void setEndTime(time_t end_date);

public:
    Attendance(Doctor &doctor, Patient patient);
    ~Attendance();

    Doctor &getDoctor() { return *doctor; }
    Patient &getPatient() { return patient; }
    tm *getStartTime() { return &start_time; }
    tm *getEndTime() { return &end_time; }
};

#endif