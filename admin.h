#include <iostream>
#include <string>
#include "loginInfo.h"
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

//----------------------------------------------User class---------------------------------------------//
class admin : public loginInfo{
    private:
        string AdminID;
    public:
        admin(string u, string p, string ID)
        {
            userName = u;
            password = p;
            AdminID = ID;
        }

        string getAdminID(){
            return AdminID;
        }

        void print()
        {
            cout << "Username : " << userName << endl;
            cout << "Password : " << password << endl;
            cout << "AdminID  : " << AdminID  << endl;
        }
};

#endif