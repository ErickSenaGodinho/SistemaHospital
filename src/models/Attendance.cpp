#pragma once
#include "Attendance.hpp"

Attendance::Attendance(Doctor &doctor, Patient patient) : doctor(&doctor), patient(patient)
{
    time_t actual_date = chrono::system_clock::to_time_t(chrono::system_clock::now());
    setStartTime(actual_date);
    time_t end_date = calculateEndDate(actual_date);
    setEndTime(end_date);
}

Attendance::~Attendance() {}

void Attendance::setStartTime(time_t start_date)
{
    this->start_time = *localtime(&start_date);
}

time_t Attendance::calculateEndDate(time_t actual_date)
{
    unsigned int attendance_time;

    switch (patient.getPriority().getValue())
    {
    case 0:
        attendance_time = 50 + (rand() % 21) - 10;
        break;

    case 1:
        attendance_time = 20 + (rand() % 11) - 5;
        break;

    case 2:
        attendance_time = 15 + (rand() % 11) - 5;
        break;

    case 3:
        attendance_time = 10 + (rand() % 5) - 2;
        break;

    case 4:
        attendance_time = 5 + (rand() % 7) - 3;
        break;
    }

    time_t end_date = actual_date + (60 * attendance_time);
    return end_date;
}

void Attendance::setEndTime(time_t end_date)
{
    this->end_time = *localtime(&end_date);
}