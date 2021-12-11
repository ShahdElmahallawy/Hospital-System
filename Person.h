#pragma once
#include <iostream>
using namespace std;
struct Appointment
{
	int hours;
	int minutes;
};
class Person
{
private:
	string name;
	string ID;
	int age;
public:
	Person();
	Person p1(Person p2);
	//how to write a copy constructor????
	void setName(string n);
	void setID(string id);
	void setAge(int a);
	string getName();
	string getID();
	int getage();
	void print();
};
