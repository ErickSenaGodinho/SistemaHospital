#include "system.cpp"

int main(int argc, char const *argv[])
{
    UINT UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    Hospital hospital;
    hospital.initDoctors();

    unsigned int option;
    do
    {
        menu();
        cin >> option;
        cin.ignore();
        system("cls");

        switch (option)
        {
        case 1:
            registerAttendance(hospital);
            break;

        case 2:
            showAttendances(hospital);
            break;

        case 3:
            showQueue(hospital);
            break;

        case 4:
            update(hospital);
            break;

        case 5:
            showReport(hospital);
            break;
        }
    } while (option != EXIT_OPTION);

    return 0;
}
