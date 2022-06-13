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
    private:
        string name, address, vaccine;
        int phoneNumber;
    public:
        User(string Un, string p, string n, string ad, string vc, int pN)
        {
            userName = Un;
            password = p;
            name = n;
            address = ad;
            vaccine = vc;
            phoneNumber = pN;
        }



};

bool loginValidation(User user){
    bool valid;
    string userName, password;

    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    if (userName.compare(user.getUsername()) == true){

        userName.compare(user.getPassword);


    } else


    

}


int main(){

    



    system("PAUSE");
    return 0;
}