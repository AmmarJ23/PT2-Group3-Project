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
            cout<<"health condition menu"<<endl;
            cout<<"Please enter the informations about your health conditions"<<endl;
            cout<<"Are you having any Covid-19 symptoms?(yes/no)"<<endl;
            getline(cin, symptoms);

            cout<<"Have you had close contact?(yes/no)"<<endl;
            getline(cin, closeContact);

            cout<<"What is your test result?(positive/negative)"<<endl;
            getline(cin, testResult);

            cout<<"Have you travelled outside of campus in the last 14 day?(yes/no)"<<endl;
            getline(cin, travelStatus);

            cout<<"Where are you currently residing?(KTHO/KTDI/KTC/KTF)"<<endl;
            getline(cin, location);
        }
};

//----------------------------------------------User class---------------------------------------------//
class User: public loginInfo{ 
    private:
        string name, address, vaccine, phoneNumber;
        
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
};

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

};

//-------------------------------------------hotspotInfo class-----------------------------------------//
class hotspotInfo{
    private:
        string hotspotArea, areaStatus;
        int infectedNum;
    public:
        hotspotInfo(){}

        hotspotInfo(string ha, int infNum)
        {
            hotspotArea = ha;
            infectedNum = infNum;

            areaStatusCalc();
        }

        void areaStatusCalc(){
            if(infectedNum <=3){areaStatus = "Safe";}
            else {areaStatus = "Not safe";}
        }

        hotspotInfo operator+(int i){
            hotspotInfo obj;
            obj.hotspotArea = hotspotArea;
            obj.infectedNum = infectedNum + i;

            if(obj.infectedNum <=3){obj.areaStatus = "Safe";}
            else {obj.areaStatus = "Not safe";}

            return obj;
        }

};

//function prototype
loginReturnData userLoginMenu(User []);
bool adminLoginMenu(admin);
void appMenu(loginReturnData, User[]);
void adminAppMenu(hotspotInfo[]);

//-------------------------------------------LoginMenu function-----------------------------------------//
void LoginMenu(User user[], admin admin_, hotspotInfo hotspotArray[])
{
    int choice;

    cout<<"          LOGIN AND REGISTERATION         "<<endl;
    cout<<"   FOR COV19 ASSIST AND TRACING SYSTEM    "<<endl;
  	cout<<"------------------------------------------"<<endl;
    cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
    cout<<"------------------------------------------"<<endl;
    
    cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Admin Login"<<endl;
    cout<< setw(10)<<" 2. "<<setw(10)<<"User Login"<<endl;
    cout<< setw(10)<<" 3. "<<setw(10)<<"Register"<<endl;
    cout<< setw(10)<<" 4. "<<setw(10)<<"Exit"<<endl;

    while (true)
    {
        cin >> choice;

        switch(choice){
            case 1:
            {
                bool adminValid = adminLoginMenu(admin_);
                if (adminValid == true)
                {
                    adminAppMenu(hotspotArray);
                }
                break;
            }
            
            case 2:
            {
                loginReturnData userLogData =  userLoginMenu(user);
                appMenu(userLogData, user);
                break;
            }
                
                
            case 3:
                //UserRegister();
                break;

            case 4:
                cout<< "Exiting now..."<<endl;
                //exit(1);
                goto stop_loop;
            
            default:
                cout<<"Please enter the valid number(1-3)"<<endl;
                break;
        }
    }

    stop_loop: ;
}

//----------------------------------------userLoginMenu function---------------------------------------//
loginReturnData userLoginMenu(User user[]){

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

//---------------------------------------adminLoginMenu function---------------------------------------//
bool adminLoginMenu(admin admin_){

    string userName, password, adminID;
    bool valid;
    
    cout << "Enter username: ";
    cin >> userName;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter adminID : ";
    cin >> adminID;
    
    bool userValid = userName.compare(admin_.getUsername());
    bool passValid = password.compare(admin_.getPassword());
    bool IDValid = adminID.compare(admin_.getAdminID());

    if (userValid == 0 && passValid == 0 && IDValid == 0)
    {
        valid = true;
    }

    if (valid == false)
    {
        cout << "Incorrect username, password, or adminID" << endl;
    }
    
    return valid;
}

//---------------------------------------adminAppMenu function---------------------------------------//
void adminAppMenu(hotspotInfo hotspotArray[]){

    int choice, index, num;

    cout<<"                  ADMIN                   "<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
    cout<<"------------------------------------------"<<endl;

    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter index of chosen college";
        cin >> index;

        cout << "Enter amount to add";
        cin >> num;

        hotspotArray[index] = hotspotArray[index] + num;
 
    }

}

//----------------------------------------getUserData function-----------------------------------------//
void getUserData(User user[]){

    string temp1[6];
    ifstream inputFile("User_Data.txt");

    inputFile >> USER_NUM;
    inputFile.ignore();

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
void appMenu(loginReturnData logData, User user[]){
    int choice;
    
 	cout<<"WELCOME TO COV19 ASSIST AND TRACING SYSTEM"<<endl;
  	cout<<"------------------------------------------"<<endl;
    cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
    cout<<"------------------------------------------"<<endl;
  
    cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Donno"<<endl;
    cout<< setw(10)<<" 2. "<<setw(10)<<"Health Condition"<<endl;
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
            user[logData.userIndex].userHealth.setHealthCondition();
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
    admin admin_("Admin", "Admin123", "001122");
    hotspotInfo hotspotArray[4] = {hotspotInfo("KTHO",0), hotspotInfo("KTDI",2), hotspotInfo("KTC",6), hotspotInfo("KTF",9)};

    getUserData(userArray);

    LoginMenu(userArray, admin_, hotspotArray);
    
    cout << endl;

    system("PAUSE");
    return 0;
}