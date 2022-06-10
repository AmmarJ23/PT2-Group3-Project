//------------------------------------------------------------------------------
// School of Computing, Universiti Teknologi Malaysia
// SECJ J1023- Programming Technique II
// Semester 2, 2021/2022
// Tutorial Polymorphism
// 
// Group 3
//
// Members: 1.AFIQ FAHMI BIN ROSLAN (A21EC0153)
//			2.AMMAR BIN JAMALLUDIN 	(A21EC0160)
//			3.AZHAN HANIFF BIN AZNI (A21EC0017)
//			4.RYAN LIM SHEN 		(A21EC0223)
//------------------------------------------------------------------------------

#include<iostream>
using namespace std;

// The class Person is FULLY given
// Do not change anything for this class
class Person
{
	protected:
		string name;
	public:
		Person(string name=""){ setName(name); }
		string getName() const{return name;}
		void setName(string name) {this->name = name;}
};


//---------------------------------------Doctor class---------------------------------------//
class Doctor : public Person
{
	private:
		string department;
	public:
		Doctor(string n, string d)  // n is doctor's name,  d is department
		{
			name = n;
			department = d;
		}

		string getDepartment() const
		{
			return department;
		}
};

//--------------------------------------Guardian class--------------------------------------//
class Guardian : public Person
{	
   protected:
		string phone;
   public:
		Guardian(string n="", string p="") // n is guardian's name,  p is phone number
		{
			name = n;		
			phone = p;
		}

		string getPhoneNumber() const
		{
			return phone;
		}

		void setPhone(string p)
		{
			phone = p;
		}
};

//--------------------------------------Patient class---------------------------------------//
class Patient : public Person
{
	protected:
		string illness;
		Guardian g1;
		Doctor *docAssign = NULL;
	public:
		Patient(string pn="", string pi="",   // patient's name and the illness
		        string gn="", string gp="" ) : g1(gn, gp) // guardian's name and phone number
		{
			name = pn;
			illness = pi;
			g1.setName(gn);
			g1.setPhone(gp);
	    }

		virtual void print()
		{
			cout << "Patient's Name   :" << getName() << endl;
			cout << "Illness          :" << illness << endl;
			cout << "Guardian's Name  :" << g1.getName() << endl;
			cout << "Guardian's Phone :" << g1.getPhoneNumber() << endl;

			cout << "Doctor's Name    :" << endl;
			cout << "Doctor's Dept.   :" << endl;

			cout << " *** No doctor assigned yet *** " << endl;
	    }

		void assignDoctor(Doctor * doc)
		{
			docAssign = doc;
		}

};

//-------------------------------------Outpatient class-------------------------------------//
class Outpatient : public Patient
{
	private: 
		string diagnosis;
	public:
		Outpatient( string pn="", string pi="",    // patient's name and illness
		            string gn="", string gp="",    // guardian's name and phone number
					string pdiagnosis="")          // diagnosis type
        {
			name = pn;
			illness = pi;
			g1.setName(gn);
			g1.setPhone(gp);
			diagnosis = pdiagnosis;
		}

		void print()
		{
		    cout << "Patient Type:  OUTPATIENT " 	<< endl;
			cout << "Diagnosis   :  "<<  diagnosis	<< endl;
			cout << endl;

			cout << "Patient's Name   :" << getName() << endl;
			cout << "Illness          :" << illness << endl;
			cout << "Guardian's Name  :" << g1.getName() << endl;
			cout << "Guardian's Phone :" << g1.getPhoneNumber() << endl;

			if(docAssign == NULL){
				cout << " *** No doctor assigned yet *** " << endl;
			} else {
				cout << "Doctor's Name    :" << docAssign->getName() << endl;
				cout << "Doctor's Dept.   :" << docAssign->getDepartment() << endl;
			}
			
		}
};

//-------------------------------------Inpatient class--------------------------------------//
class Inpatient : public Patient
{
	private:
		string ward;
	public:
		Inpatient( string pn="", string pi="",    // patient's name and illness
		           string gn="", string gp="",    // guardian's name and phone number
				   string pward="")               // patient's ward
        {
			name = pn;
			illness = pi;
			g1.setName(gn);
			g1.setPhone(gp);
			ward = pward;
		}

		void print()
		{
			cout << "Patient Type:  INPATIENT "<< endl;
			cout << "Ward        :  "<< ward   << endl;
			cout << endl;

			cout << "Patient's Name   :" << getName() << endl;
			cout << "Illness          :" << illness << endl;
			cout << "Guardian's Name  :" << g1.getName() << endl;
			cout << "Guardian's Phone :" << g1.getPhoneNumber() << endl;

			if(docAssign == NULL){
				cout << " *** No doctor assigned yet *** " << endl;
			} else {
				cout << "Doctor's Name    :" << docAssign->getName() << endl;
				cout << "Doctor's Dept.   :" << docAssign->getDepartment() << endl;
			}
		}

};

//---------------------------------------Menu Function--------------------------------------//
// The menu function is fully given
int menu()
{
	cout << endl;
	cout << "========== Menu ==========" << endl;
	cout << "1. List Doctors"   << endl;
	cout << "2. List Patients" << endl;
	cout << "3. Assign Doctor"  << endl;
	cout << "4. Exit"  << endl;
	cout << endl;

	int choice;
	cout << "Choose an operation [1-4] => ";
	cin >> choice;

	cin.ignore();
	cout << endl;

	return choice;
}

//--------------------------------------main function---------------------------------------//
int main()
{
	const int NDOC = 2;  // Number of of doctor.
	const int NPATIENT   = 3;  // Number of patients.

	Doctor docArray[NDOC] = {	Doctor("Dr. Ramli", "ICU"), 
								Doctor("Dr. Kamariah", "Radiology")};

	Patient** patientArray = new Patient*[NPATIENT];

	patientArray[0] = new Outpatient("Rozita", "Sprained Ankle", "Saleh", "4466", "X-Ray");
	patientArray[1] = new Inpatient("Nurdiana", "Respiratory Failure", "Jalil", "7731", "ICU 101");
	patientArray[2] = new Outpatient("Ali", "Coronary Artery", "Bakar", "1234", "CT Scan");

	Doctor *docPtr;
	// For convenience (for copy-and-paste purposes), the data of doctors and patients
	//  are given at the bottom of this program.

	// The program structure regarding the menu operation is given
	int c = menu();

	while (c!=4){

		switch (c){
			case 1: // List Doctors
				
				for(int i=0; i<NDOC; i++){
					cout <<"Doctor's Name: " << docArray[i].getName() << "\t"
						 <<"Department: " 	 << docArray[i].getDepartment()  << endl;
				}

				break;

			case 2: // List Patients
				for(int i=0; i<NPATIENT; i++){
					cout << "Patient #" << i << endl;
					patientArray[i]->print();
					cout << endl;
				}

				cout << endl << endl;

				break;

			case 3:  // Assign Doctor
				     // The operation regarding getting inputs from the user is given
				     // You must use the exception handling strategy
				     // to handle the "out of range" error

				int pIndex;   // The array index of the patient to be assigned with a doctor.
				int dIndex;   // The array index of the doctor to assign to the patient.

				cout <<"Enter the patient index and doctor index => ";
				cin >> pIndex >> dIndex;

				if((pIndex>=0 && pIndex <NPATIENT) && (dIndex >=0 && dIndex < NDOC))
				{
					docPtr = &docArray[dIndex];
					patientArray[pIndex]->assignDoctor(docPtr);
				}

				else
				{
					cout << "** Error: Index is out of range" << endl;
					break;
				}

				break;
		}

		c = menu();
	}

	return 0;
}

/*

Doctors and patients data

Doctors:
name and department

Dr. Ramli , ICU
Dr. Kamariah ,  Radiology

Patients:
name, illness,guardian'name, guardian's phone, diagnosis, ward number, and patient type

Rozita   , Sprained ankle , Salleh , 4466, X-ray , Outpatient
Nurdiana , Respiratory failure , Jalil, 7731, ICU 101, Inpatient
Ali , Coronary artery , Bakar , 1234 ,CT Scan, Outpatient

*/
