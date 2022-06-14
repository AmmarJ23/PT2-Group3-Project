#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//---------------------------------------loginInfo class---------------------------------------//
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

//---------------------------------------User class---------------------------------------//
class User: public loginInfo{ 
    private:
        string name, address, vaccine;
        int phoneNumber;
    public:

        User(){}

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

//---------------------------------------loginValdation function---------------------------------------//
bool loginValidation(User user){
    bool valid = false;
    string userName, password;

    cout << "Enter username: ";
    cin >> userName;

    cout << "Enter password: ";
    cin >> password;

    if (userName.compare(user.getUsername()) == 0){

        if (password.compare(user.getPassword()) == 0){
            valid = true;
        }else{
            cout << "Incorrect password" << endl;
        }

    } else {
        cout << "Username not found" << endl;
    }
    
    return valid;
}

//---------------------------------------main function---------------------------------------//
int main(){

    string temp1[5];
    int temp2;


    User user1("Username1", "Username1Password","John Doe", "123, Street name, 0000, District", "Pfizer", 12345); 

   // cout << loginValidation(user1) << endl << endl;

    user1.print();

    User userArray[3];

    ifstream inputFile("User_Data.txt");

    
    
    for (int k = 0; k < 3; k++)
    {

        for (int i = 0; i < 5; i++)
        {
            getline(inputFile,temp1[i]);
        }
            inputFile >> temp2;
        
        User userTemp(temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp2);

        userArray[k] = userTemp;

    }

    for (int i = 0; i < 3; i++)
    {
        cout << endl;

        userArray[i].print();

        cout << endl;
    }
    

    cout << endl;

    //user2.print();


    system("PAUSE");
    return 0;
}