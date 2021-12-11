#include"Doctor.h"
Doctor::Doctor()
{
	counter = 0;
}
bool Doctor::isAvailable(Appointment A)
{
	for (int i = 0; i < counter; i++)
	{
		if (DrAppointments[i].hours == A.hours && DrAppointments[i].minutes == A.minutes)
			return false;
	}
	return true;
}
void Doctor::setCounter(int count) 
{
	counter = count;
}
int Doctor::getCounter()
{
	return counter;
}
void Doctor::setAppointments(Appointment App)
{
	DrAppointments[counter].hours= App.hours;
	DrAppointments[counter].minutes = App.minutes;
	counter++;
}
Appointment* Doctor::getAppointments()
{
	return DrAppointments;
}