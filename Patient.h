#pragma once
#include"Person.h"

class Patient : public Person
{
private:
	Appointment A;
public:
	Patient();
	bool operator> (Patient p);
	bool operator< (Patient p);
	bool operator== (Patient p);
	void setAppoinment(Appointment);
	Appointment getAppoinment();
};

