#include <iostream>
using namespace std;

class loginInfo{
    protected:
        string userName, password;
    public:

        loginInfo(string n, string p)
        {
            userName = n;
            password = p;
        }

        string getUsername(){
            return userName;
        }

        string getPassword(){
            return password;
        }
};


class User: public loginInfo{ 
    


};


int main(){



    return 0;
}