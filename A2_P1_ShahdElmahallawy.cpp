#include<iostream>
#include<fstream>
#include<string>
#include"Doctor.h"
#include"Queue.h"

using namespace std;
//A function to read what inside patient and doctor files
void readFile(Patient* p1, Doctor* D1, int numberOfPatients, int numberOfDoctors);

// A function to get the data of the doctor and the patient from the user
void ReadFromConsole(Patient* patients, Doctor* doctors, int numberOfPatients, int nubmerOfDoctors);

void main()
{
	char choice; 
	int doctorSize;
	int patientSize;
	cout << "Enter the number of the of the doctors" << endl;
	cin >> doctorSize;
	cout << "Enter the number of the patients" << endl;
	cin >> patientSize;
	// Two dynamic arrays to store the doctors and the patients data and get their size for the user
	Doctor* arrayOfDrs;
	Patient* arrayOfPts;
	cout << "Do you prefer to enter the data or read it from th existed files" << endl;
	cout << "Enter Y if you want to enter it or N if you want the existed file" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		ReadFromConsole(arrayOfPts, arrayOfDrs, patientSize, doctorSize);
	}
	else 
	{
		readFile(arrayOfPts, arrayOfDrs, patientSize, doctorSize);
	}
	//SORT patientsArray

	for (int i = 0; i < patientSize - 1; i++)
	{
		for (int j = 0; j < patientSize - i - 1; j++)
		{
			if (arrayOfPts[j] > arrayOfPts[j + 1])
			{
				Patient temp = arrayOfPts[j];
				arrayOfPts[j] = arrayOfPts[j + 1];
				arrayOfPts[j + 1] = temp;
			}
		}
	}



	Queue<Patient> patientQueue;
	for (int i = 0; i < patientSize; i++)
	{
		patientQueue.enqueue(arrayOfPts[i]);
	}

	int count = 0; //to count the doctor and make sure that it is not more than the number of the doctor entered by the user
	for (int i = 0; i < patientSize; i++)
	{
		Patient tempPatient = patientQueue.dequeue();
		bool assigned = false;
		while (!assigned)
		{	

			if (arrayOfDrs[count].isAvailable(tempPatient.getAppoinment()))
			{
				Appointment app = tempPatient.getAppoinment();
				arrayOfDrs[count].setAppointments(app);
				cout << tempPatient.getName() << " is assigned to the doctor: " << arrayOfDrs[count].getName() <<
					" at " << app.hours << ":" << app.minutes << endl;
				assigned = true;
			}
			count++;
			if (count == doctorSize)
			{
				count = 0;
			}
		}
	}

}

void readFile(Patient* p1, Doctor* D1, int numberOfPatients, int numberOfDoctors)
{
	//Read doctor's file
	ifstream streamReader;
	streamReader.open("Doctor.txt");
	string move;
	int i = 0;
	for (int i = 0; i < numberOfDoctors; i++)
	{
		string name;
		int age, numberOfAppointments;
		string id;
		streamReader >> name >> age >> id >> numberOfAppointments;
		D1[i].setName(name);
		D1[i].setAge(age);
		D1[i].setID(id);
		for (int j = 0; j < numberOfAppointments; j++)
		{
			int hour, mins;
			streamReader >> hour >> mins;
		}
	}
	streamReader.close();
	//Read patient file
	streamReader.open("Patient.txt");
	string move;
	int i = 0;
	for (int i = 0; i < numberOfPatients; i++)
	{
		string name;
		string id;
		int hour, minutes, age;
		streamReader >> name >> age >> id >> hour, minutes;

		p1[i].setName(name);
		p1[i].setID(id);
		p1[i].setAge(age);
		Appointment app;
		app.hours = hour;
		app.minutes = minutes;
		p1[i].setAppoinment(app);
	}
	streamReader.close();
}
void ReadFromConsole(Patient* patients, Doctor* doctors, int numberOfPatients, int nubmerOfDoctors)
{
	//set Dr data 
	Appointment A1;
	doctors = new Doctor[nubmerOfDoctors];
	patients = new Patient[numberOfPatients];
	for (int i = 0; i < nubmerOfDoctors; i++)
	{
		string n, id;
		int age;
		int numberOfDrAppoitments;
		int hour, minutes;
		cout << "please, enter the name of the doctor" << endl;
		cin >> n;
		doctors[i].setName(n);
		cout << "Please, enter the age of the doctor" << endl;
		cin >> age;
		doctors[i].setAge(age);
		cout << "Please, enter doctor's ID" << endl;
		cin >> id;
		doctors[i].setID(id);
		cout << "Please, enter the number of the appointments the doctor has" << endl;
		cin >> numberOfDrAppoitments;

		for (int i = 0; i < numberOfDrAppoitments; i++)
		{
			cout << "Please, enter the appointment of the doctor in hours" << endl;
			cin >> hour;
			cout << "Please, enter the number of the doctor in minutes" << endl;
			cin >> minutes;
			Appointment app;
			app.hours = hour;
			app.minutes = minutes;
			doctors[i].setAppointments(app);
		}
	}
	//set Patient data 

	patients = new Patient[numberOfPatients];
	for (int i = 0; i < numberOfPatients; i++)
	{
		string P_name;
		int P_age;
		string P_id;
		Appointment A1;
		cout << "please, enter the name of the patient" << endl;
		cin >> P_name;
		patients[i].setName(P_name);
		cout << "Please, enter the age of the patient" << endl;
		cin >> P_age;
		patients[i].setAge(P_age);
		cout << "Please, enter patient's ID" << endl;
		cin >> P_id;
		patients[i].setID(P_id);
		cout << "Enter the appointment that patient wants in hours" << endl;
		cin >> A1.hours;
		cout << "Enter the appointment that patient wants in minutes" << endl;
		cin >> A1.minutes;
		patients[i].setAppoinment(A1);
	}
}
