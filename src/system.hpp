#ifndef SYSTEM_H
#define SYSTEM_H

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <windows.h>
#include "models/Address.cpp"
#include "models/Attendance.cpp"
#include "models/Doctor.cpp"
#include "models/Hospital.cpp"
#include "models/Patient.cpp"
#include "models/Priority.cpp"

using namespace std;

#define EXIT_OPTION 6

unsigned int Patient::static_id = 0;

void menu();
void registerAttendance(Hospital &hospital);
Patient registerPatient();
Address registerAddress();
Screening registerScreening();
void showAttendances(Hospital hospital);
void showQueue(Hospital hospital);
void update(Hospital &hospital);
void showReport(Hospital hospital);

#endif