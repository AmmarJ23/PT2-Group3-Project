#include <string>
#include <iostream>
using namespace std;

#ifndef LOGININFO_H
#define LOGININFO_H

//-------------------------------------------loginInfo class-------------------------------------------//
class loginInfo{
    protected:
        string userName, password;
    public:

        loginInfo(string n="", string p = ""){setNP(n,p);}

        string getUsername() const
        {
            return userName;
        }

        string getPassword() const
        {
            return password;
        }

        void setNP(string n, string p)
        {
            this->userName = n;
            this->password = p;
        }

        virtual void print()
        {
            cout<< userName << endl;
            cout<< password << endl;
        }
};

#endif