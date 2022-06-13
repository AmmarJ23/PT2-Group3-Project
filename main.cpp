#include <iostream>
#include <string>
using namespace std;

class loginInfo{
    protected:
        string userName, password;
    public:

        loginInfo(string n="", string p = ""){setNP(n,p);}

        string getUsername() const{
            return userName;
        }

        string getPassword()const {
            return password;
        }

        void setNP(string n, string p) {
            this->userName = n;
            this->password = p;
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

        void print(){
            cout << "Name        : " << name << endl;
            cout << "Address     : " << address << endl;
            cout << "Vaccine     : " << vaccine << endl;
            cout << "Phone Number: " << phoneNumber << endl;
        }



};

bool loginValidation(User user){
    bool valid = false;
    string userName, password;

    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    if (userName.compare(user.getUsername()) == true){

        if (userName.compare(user.getPassword()) == true){
            valid = true;
        }else{
            cout << "Incorrect password" << endl;
        }

    } else {
        cout << "Username not found" << endl;
    }


    
    return valid;
}


int main(){

    User user1("Username1", "Username1Password","John Doe", "123, Street name, 0000, District", "Pfizer", 12345); 

    user1.print();

    system("PAUSE");
    return 0;
}