#pragma once
#include "system.hpp"

void menu()
{
    system("cls");
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                    Hospital                    #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#               1 - Register Attendance          #" << endl;
    cout << "#                                                #" << endl;
    cout << "#               2 - Show Attendances             #" << endl;
    cout << "#                                                #" << endl;
    cout << "#               3 - Show Queue                   #" << endl;
    cout << "#                                                #" << endl;
    cout << "#               4 - Update                       #" << endl;
    cout << "#                                                #" << endl;
    cout << "#               5 - Show Report                  #" << endl;
    cout << "#                                                #" << endl;
    cout << "#               6 - Exit                         #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
}

void registerAttendance(Hospital &hospital)
{
    int option;
    do
    {
        system("cls");
        cout << "##################################################" << endl;
        cout << "#                                                #" << endl;
        cout << "#              Register Attendance               #" << endl;
        cout << "#                                                #" << endl;
        cout << "##################################################" << endl;

        Patient new_patient = registerPatient();
        Screening screening = registerScreening();
        system("cls");

        new_patient.setScreening(screening);
        hospital.getQueue().push(new_patient);

        cout << screening.priority.getName() << endl;
        cout << screening.priority.getTimeForAttendance() << endl;
        cout << "\n";

        do
        {
            cout << "Do you want to register a new attendance?" << endl;
            cout << "1-Yes" << endl;
            cout << "2-No" << endl;
            cin >> option;
            cin.ignore();
        } while (option != 1 && option != 2);
    } while (option == 1);
    update(hospital);
}

Patient registerPatient()
{
    cout << "#                                                #" << endl;
    cout << "#               Register Patient                 #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;

    string name;
    Address address;
    unsigned int age, gender;

    cout << "Name: ";
    getline(cin, name);
    address = registerAddress();
    cout << "Age: ";
    cin >> age;
    cin.ignore();
    do
    {
        cout << "Gender: " << endl;
        cout << "1-Masculine" << endl;
        cout << "2-Feminine" << endl;
        cin >> gender;
    } while (gender != 1 && gender != 2);
    cin.ignore();

    Patient patient(name, address, age, gender);

    system("cls");
    return patient;
}

Address registerAddress()
{
    string street, district, number;
    cout << "Address" << endl;
    cout << "\tStreet: ";
    getline(cin, street);
    cout << "\tDistrict: ";
    getline(cin, district);
    cout << "\tNumber: ";
    cin >> number;
    cin.ignore();
    return Address(street, district, number);
}

Screening registerScreening()
{
    Screening screening;
    unsigned int i = 1;
    bool urgency_found = false;
    for (auto &&question : screening.questions)
    {
        cout << i << "-" << question << " ";
        cin >> screening.answers[i - 1];

        if (screening.answers[i - 1] == 'S' || screening.answers[i - 1] == 's')
        {
            urgency_found = true;
        }
        if (urgency_found && (i % 5 == 0 || i == 18))
        {
            screening.priority = Priority(i == 18 ? i / 5 : i / 5 - 1);
            break;
        }
        i++;
    }

    if (!urgency_found)
    {
        screening.priority = Priority(4);
    }

    return screening;
}

void showAttendances(Hospital hospital)
{
    if (hospital.getRunningAttendances().empty())
    {
        cout << "No Attendance" << endl;
        Sleep(1000);
        return;
    }
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#              Running Attendances               #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "\n";
    for (auto &attendance : hospital.getRunningAttendances())
    {
        cout << "Doctor: " << attendance.getDoctor().getName() << endl;
        cout << "Patient: " << attendance.getPatient().getName() << endl;
        cout << "Urgency: " << attendance.getPatient().getPriority().getName() << endl;
        cout << "Start Time: " << put_time(attendance.getStartTime(), "%d/%m/%Y %H:%M:%S") << endl;
        cout << "End Time Forecast: " << put_time(attendance.getEndTime(), "%d/%m/%Y %H:%M:%S") << endl;
        cout << "\n";
    }
    system("pause");
}

void showQueue(Hospital hospital)
{
    if (hospital.getQueue().empty())
    {
        cout << "No Waiting Patients" << endl;
        Sleep(1000);
        return;
    }
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                     Queue                      #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "\n";

    priority_queue<Patient, vector<Patient>, GreaterThanByPriority> queue = hospital.getQueue();

    while (!queue.empty())
    {
        Patient patient = queue.top();
        queue.pop();
        patient.showData();
    }

    system("pause");
}

void update(Hospital &hospital)
{
    chrono::system_clock::time_point actual_date = chrono::system_clock::now();
    vector<Attendance> &attendances = hospital.getRunningAttendances();
    vector<unsigned int> to_remove;
    for (unsigned int i = 0; i < attendances.size(); i++)
    {
        Attendance &attendance = attendances.at(i);
        chrono::system_clock::time_point end_date = chrono::system_clock::from_time_t(mktime(attendance.getEndTime()));

        if (end_date <= actual_date)
        {
            Doctor &doctor = attendance.getDoctor();
            doctor.setAvaible(true);
            attendance.getPatient().setAttended(true);
            hospital.setAvaibleDoctors(hospital.getAvaibleDoctors() + 1);
            hospital.increaseTreatedPatients();
            to_remove.push_back(i);
            cout << doctor.getName() << ": Medical assistance has been completed. " << endl;
            system("pause");
        }
    }

    for (auto &&id : to_remove)
    {
        attendances.erase(attendances.begin() + id);
    }

    while (hospital.getAvaibleDoctors() > 0 && !hospital.getQueue().empty())
    {
        for (size_t i = 0; i < hospital.getRegisteredDoctors(); i++)
        {
            Doctor &doctor = hospital.getDoctors()[i];
            if (doctor.isAvaible())
            {
                Patient patient = hospital.getQueue().top();
                hospital.getQueue().pop();
                Attendance attendance(doctor, patient);
                doctor.setAvaible(false);
                hospital.setAvaibleDoctors(hospital.getAvaibleDoctors() - 1);
                hospital.addAttendance(attendance);
                system("cls");
                cout << patient.getName() << ", please come to the doctor's office " << doctor.getName() << endl;
                system("pause");
                break;
            }
        }
    }
}

void showReport(Hospital hospital)
{
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                     Report                     #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "Running Attendances: " << hospital.getRunningAttendances().size() << endl;
    cout << "Registered Doctors: " << hospital.getRegisteredDoctors() << endl;
    cout << "Avaible Doctors: " << hospital.getAvaibleDoctors() << endl;
    cout << "Treated Patients: " << hospital.getTreatedPatients() << endl;
    cout << "Waiting Patients: " << hospital.getQueue().size() << endl;
    system("pause");
}