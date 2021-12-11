#include"Person.h"
Person::Person()
{
	name = "";
	ID = "";
	age = 0;
}
void Person::setName(string n)
{
	name = n;
}
void Person::setID(string id)
{
	ID = id;
}
void Person::setAge(int a)
{
	age = a;
}
string Person::getName()
{
	return name;
}
string Person::getID()
{
	return name;
}
int Person::getage()
{
	return age;
}
void Person::print()
{

}