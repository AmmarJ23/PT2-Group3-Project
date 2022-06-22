#include <iostream>
#include <string>
#include "loginInfo.hpp"
using namespace std;

#ifndef USER_H
#define USER_H

//----------------------------------------------User class---------------------------------------------//
class User: public loginInfo{ 
    private:
        string name, address, vaccine, phoneNumber;
        hotspotInfo *college;
        
    public:

        healthCondition userHealth;

        User(){}

        User(string Un, string p, string n, string ad, string vc, string pN)
        {
            userName = Un;
            password = p;
            name = n;
            address = ad;
            vaccine = vc;
            phoneNumber = pN;
        }

        void print(){
            cout << "Name        : " << name << endl;
            cout << "Address     : " << address << endl;
            cout << "Vaccine     : " << vaccine << endl;
            cout << "Phone Number: " << phoneNumber << endl;
        }

        void setCollege(hotspotInfo obj)
        {
            college = &obj;
        }

        hotspotInfo* getCollege()
        {
            return college;
        }
};

#endif