#ifndef PRIORITY_H
#define PRIORITY_H

class Priority
{
private:
    unsigned int value;
    string name[5] = {"Red", "Orange", "Yellow", "Green", "Blue"};
    string time_for_attendance[5] = {"Immediate medical assistance",
                                     "Medical assistance within 10 minutes",
                                     "Medical assistance within 60 minutes",
                                     "Medical assistance within 120 minutes",
                                     "Medical assistance within 140 minutes"};

public:
    Priority();
    Priority(unsigned int value);
    ~Priority();

    unsigned int getValue() const { return value; }
    string getName() const { return name[value]; }
    string getTimeForAttendance() const { return time_for_attendance[value]; }
};

#endif