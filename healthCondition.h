#include <iostream>
#include <string>
using namespace std;

#ifndef HEALTHCONDITION_H
#define HEALTHCONDITION_H

//----------------------------------------healthCondition class----------------------------------------//
class healthCondition{
    private:
        string symptoms, closeContact, testResult, travelStatus, location;
        
    public:
        healthCondition(){}
    
        healthCondition(string symp, string CC, string TR, string loc, string TS)
        {
            symptoms = symp;
            closeContact = CC;
            testResult = TR;
            travelStatus = TS;
            location = loc;
        }

        void setHealthCondition()
        {
            cin.ignore();
            cout<<"Health condition menu"<< endl;
            cout<<"Please enter the informations about your health conditions"<< endl;
            cout<<"Are you having any Covid-19 symptoms?(yes/no)"<< endl;
            getline(cin, symptoms);

            cout<<"\nHave you had close contact?(yes/no)"<<endl;
            getline(cin, closeContact);

            cout<<"\nWhat is your test result?(positive/negative)"<<endl;
            getline(cin, testResult);

            cout<<"\nHave you travelled outside of campus in the last 14 day?(yes/no)"<<endl;
            getline(cin, travelStatus);

            cout<<"\nWhere are you currently residing?(KTHO/KTDI/KTC/KTF)"<<endl;
            getline(cin, location);

        }// location == ktdi/ktho && TR == positive{+1 dekat infectednummber dalam hotspotinfo}

        string getTestResult(){return testResult;}
        string getLocation(){return location;}
};

#endif