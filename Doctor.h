#pragma once
#include"Person.h"
#include"Patient.h"
class Doctor : public Person
{
private:
	int counter;
	Appointment DrAppointments[100];
public:
	Doctor();
	bool isAvailable(Appointment App);
	void setCounter(int);
	int getCounter();
	void setAppointments(Appointment);
	Appointment* getAppointments();
};