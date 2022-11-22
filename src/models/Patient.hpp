#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include "Address.hpp"
#include "Priority.hpp"

using namespace std;

struct Screening
{
    string questions[18] = {"Compromised Airways?", "Trouble Breathing?", "Shock?", "Not responding to stimuli?",
                            "Convulsing?", "Severe Pain?", "Large uncontrollable hemorrhage?", "Alteration in consciousness?",
                            "Temperature above 39°C?", "Severe Head Trauma?", "Moderate Pain?", "Small uncontrollable hemorrhage?",
                            "Continuous Vomiting?", "Temperature between 38°C  and 39°C?", "Elderly or Pregnant?", "Mild Pain?", "Nausea?",
                            "Temperature between 37°C e 38°C?"};
    char answers[18];
    Priority priority;
};

class Patient
{
private:
    static unsigned int static_id;

    unsigned int id;
    string name;
    Address address;
    unsigned int age;
    unsigned int gender;
    Screening screening;
    bool attended;

public:
    Patient();
    Patient(string name, Address address, unsigned int age, unsigned int gender);
    ~Patient();

    void setScreening(Screening screening);
    void setAttended(bool attended);

    unsigned int getId() const { return id; }
    string getName() const { return name; }
    Priority getPriority() const { return screening.priority; }
    bool wasAttended() const { return attended; }

    void showData() const;
};

/** Structure to sort patients based on priority/urgency
 */
struct GreaterThanByPriority
{
    /** Compares two patients and ranks them
     *
     * @see getId
     * @see getPriority
     *
     */
    bool operator()(const Patient &lhs, const Patient &rhs) const
    {
        return lhs.getPriority().getValue() == rhs.getPriority().getValue() ? lhs.getId() > rhs.getId() : lhs.getPriority().getValue() > rhs.getPriority().getValue();
    }
};

#endif