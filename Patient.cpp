#include"Patient.h"

Patient::Patient()
{
	A.hours = 0;
	A.minutes = 0;
}
void Patient::setAppoinment(Appointment A1)
{
	A = A1;
}
bool Patient::operator>(Patient p)
{
	if (A.hours > p.A.hours)
		return true;
	else if (A.hours == p.A.hours && A.minutes > p.A.minutes)
		return true;
	else
		return false;
}
bool Patient::operator<(Patient p)
{
	if (A.hours < p.A.hours)
		return true;
	else if (A.hours == p.A.hours && A.minutes < p.A.minutes)
		return true;
	else
		return false;
}
bool Patient::operator==(Patient p)
{
	if (A.hours == p.A.hours && A.minutes == p.A.minutes)
		return true;
	else
		return false;
}
Appointment Patient::getAppoinment()
{
	return A;
}