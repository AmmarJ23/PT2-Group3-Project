#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//global variable for number of users
int USER_NUM;

//---------------------------------------loginReturnData struct----------------------------------------//
struct loginReturnData
{
    bool valid;
    int userIndex;
};

//-------------------------------------------loginInfo class-------------------------------------------//
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

//----------------------------------------------User class---------------------------------------------//
class User: public loginInfo{ 
    private:
        string name, address, vaccine, phoneNumber;
        healthCondition userHealth;
    public:

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

};

//----------------------------------------healthCondition class----------------------------------------//
class healthCondition{
    private:
        int symptoms, closeContact, testResult, travelAbroad;
        string location;
    public:
        healthCondition(){}
    
        healthCondition(string symp, string CC, string TR, string loc, string TA)
        {
            symptoms = symp;
            closeContact = CC;
            testResult = TR;
            travelAbroad =TA;
            location = loc;
        }

        void InputHC()
        {
            cout<<"health condition menu"<<endl;
            cout<<"Please enter the informations about your health conditions"<<endl;
            cout<<"Are you having any Covid-19 symptoms?(yes/no)"<<endl;
            getline(cin, symp);

            cout<<"Have you had close contact?(yes/no)"<<endl;
            
            cout<<"What is your test result?(positive/negative)"<<endl;
            
            
        }
};


//---------------------------------------loginValdation function---------------------------------------//
loginReturnData loginValidation(User user[]){

    string userName, password;
    loginReturnData logReturn;

    cout << "Enter username: ";
    cin >> userName;

    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < USER_NUM; i++)
    {
        bool userValid = userName.compare(user[i].getUsername());
        bool passValid = password.compare(user[i].getPassword());

        if (userValid == 0 && passValid == 0)
        {
            logReturn.valid = true;
            logReturn.userIndex = i;
        }
    }

    if (logReturn.valid == false)
    {
        cout << "Incorrect username or password" << endl;
    }
    
    return logReturn;
}

//----------------------------------------getUserData function-----------------------------------------//
void getUserData(User user[]){

    string temp1[6];
    int temp2;

    ifstream inputFile("User_Data.txt");

    inputFile >> USER_NUM;
                    // ! test & check with cin.ignore() / inputFile.ignore();

    for (int k = 0; k < USER_NUM; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            getline(inputFile,temp1[i]);
        }
        
        User userTemp(temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5]);
        user[k] = userTemp;
    }

    inputFile.close();
}

//--------------------------------------------menu function--------------------------------------------//
void menu(User user[]){
    int choice;
    
 	cout<<"WELCOME TO COV19 ASSIST AND TRACING SYSTEM"<<endl;
  	cout<<"------------------------------------------"<<endl;
    cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
    cout<<"------------------------------------------"<<endl;
  
    cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Donno"<<endl;
    cout<< setw(10)<<" 2. "<<setw(10)<<"Login Validation"<<endl;
    cout<< setw(10)<<" 3. "<<setw(10)<<"HotSpot Info"<<endl;
    cout<< setw(10)<<" 4. "<<setw(10)<<"Guide Info"<<endl;
    cout<< setw(10)<<" 5. "<<setw(10)<<"Exit"<<endl;

    while (true)
    {
        cin >> choice;

        switch(choice){
        case 1:
            break;
        case 2:
            loginValidation(user);
            break;
            
        case 3:
            //HotspotInfo();
            break;

        case 4:
            //GuideInfo();
            break;
            
        case 5:
            cout<< "Exiting now..."<<endl;
            exit(1);
        
        default:
            cout<<"Please enter the valid number(1-6)"<<endl;
            break;
        }
    }
    
}

//--------------------------------------------main function--------------------------------------------//
int main(){
    
    string temp1[5];
    int temp2;
    User userArray[3];

    getUserData(userArray);

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << endl;
    //     userArray[i].print();
    //     cout << endl;
    // }

    loginReturnData loggedUser = loginValidation(userArray);


    //menu(userArray);
    
    
    
    cout << endl;

    system("PAUSE");
    return 0;
}