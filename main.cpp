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
            cin.ignore();
            cout<<"Health condition menu"<< endl;
            cout<<"Please enter the informations about your health conditions"<< endl;
            cout<<"Are you having any Covid-19 symptoms?(yes/no)"<< endl;
            getline(cin, symptoms);

            cout<<"Have you had close contact?(yes/no)"<<endl;
            getline(cin, closeContact);

            cout<<"What is your test result?(positive/negative)"<<endl;
            getline(cin, testResult);

            cout<<"Have you travelled outside of campus in the last 14 day?(yes/no)"<<endl;
            getline(cin, travelStatus);

            cout<<"Where are you currently residing?(KTHO/KTDI/KTC/KTF)"<<endl;
            getline(cin, location);

        }// location == ktdi/ktho && TR == positive{+1 dekat infectednummber dalam hotspotinfo}

        string getTestResult(){return testResult;}
        string getLocation(){return location;}
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

        string getHotspotArea(){return hotspotArea;}
};

//--------------------------------------------guideInfo class------------------------------------------//
class guideInfo()
{   
    
    private:
    
    public:
    int choice;

    while (true)
    {
        menuPrint(3); //print guideInfo screen

        cin >> choice;

        switch(choice){
            case 1:
                {
                    cout<<"CARE PROVIDED IN UTM FOR COV-19 PATIENTS"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"COMPLIMENTARY MEALS(3 TIMES PER DAY)"<<endl;
                    cout<<"COMPLIMENTARY SELF TEST KIT(AFTER QUARANTINE IS COMPLETED)"<<endl;
                    cout<<"COMPLIMENTARY MEDICINE(FOR SYMPTOMS)"<<endl;
                    
                    cout<<"-------------------------------------------"<<endl;
                    cout<<"FREE SWAB TEST AND QUARANTINE AREA PROVIDED"<<endl;
                    cout<<"AT KOLEJ TUN RAZAK(KTR)"<<endl;
                    cout<<"-------------------------------------------"<<endl;
                    cout<<"STUDENTS MUST REGISTER FIRST IN ORDER TO ACCESS THESE PRIVILEDGES"<<endl;
                    
                    
                    
                    break;
                }

            case 2:
                {
                    cout<<"HOTLINES NUMBERS"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"COVID-19 HOTLINE          ="<<setw(15)<<"+60133340646"<<endl;
                    cout<<"UTM AMBULANCE             ="<<setw(15)<<"+6075530999"<<endl;
                    cout<<"UTM HEALTH CENTRE         ="<<setw(15)<<"+60197756765"<<endl;
                    cout<<"STUDENT AFFAIRS HOTLINE 1 ="<<setw(15)<<"+6075530279"<<endl;
                    cout<<"STUDENT AFFAIRS HOTLINE 2 ="<<setw(15)<<"+6075530265"<<endl;

                    break;
                }
            
            case 3:
                {
                    cout<<"Protocol for positive cases:"<<endl;

                    cout<<"The isolation order for patients infected with ALL variants are as follows:"<<endl;
                    cout<<"1. Seven days for individuals who are fully vaccinated and have no symptoms."<<endl;
                    cout<<"2. 10 days for individuals who have incomplete vaccinations, or are symptomatic cases."<<endl<<endl;

                    cout<<"A health assessment will be made before discharge can be granted."<<endl<<endl;

                    cout<<"Protocol for close contacts:"<<endl;

                    cout<<"Isolation orders for close contacts of positive cases, including Omicron cases, are as follows:"<<endl;

                    cout<<"1. Five days for individuals who have already received the booster dose."<<endl;
                    cout<<"2. Seven days for individuals who are fully vaccinated, and those who are partially or are not vaccinated."<<endl;
                    cout<<"3. If symptomatic, take the RTK-Ag test, either on your own or at a nearby health facility for further treatment."<<endl:
                    cout<<"4. Results of the self-test must be submitted in the Mysejahtera application. "<<endl;
                    cout<<"5. Perform the RTK-Ag test, either at a government or private facility, on the fifth day and the seventh day (for those undergoing seven days of isolation)."<<endl;
                    cout<<"6. If the test results are negative and the individual is asymptomatic, a quarantine release will be given on the same day the test is performed."<<endl;
                    break;
                }

            case 4:
                cout<< "Returning to AppMenu..."<<endl;
                userAppMenu();
                break;     
        
            default:
                cout<<"Please enter the valid number(1-4)"<<endl;
                break;
        }
    }
};

//function prototype
void getUserData(User []);
void LoginMenu(User [], admin , hotspotInfo []);
loginReturnData userLoginMenu(User []);
void userRegister(User user[]);
void userAppMenu(loginReturnData, User[], hotspotInfo[]);
bool adminLoginMenu(admin);
void adminAppMenu(hotspotInfo[]);
void menuPrint(int);

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

//-------------------------------------------LoginMenu function-----------------------------------------//
void LoginMenu(User user[], admin admin_, hotspotInfo hotspotArray[])
{
    int choice;

    while (true)
    {
        menuPrint(0); //print loginMenu screen

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
                if (userLogData.valid == true)
                {
                    userAppMenu(userLogData, user, hotspotArray);
                }
                break;
            }
                
            case 3:
                //UserRegister();
                break;

            case 4:
                cout<< "Exiting now..."<<endl;
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

    logReturn.valid = false;

    cout << "\nEnter user login info" << endl;
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

//----------------------------------------userRegister function----------------------------------------//
void userRegister(User user[]){
    string temp1[6];
    int userNumTemp = USER_NUM;
    ofstream outputFile("User_Data.txt");
    
    outputFile <<  USER_NUM + 1;

    for (int i = 0; i < USER_NUM*5; i++)
    {
        outputFile << ;
    }

    cout << "Enter username     : ";
    getline(cin, temp1[0]);
    cout << "Enter password     : ";
    getline(cin, temp1[1]);
    cout << "Enter full name    : ";
    getline(cin, temp1[2]);
    cout << "Enter address      : ";
    getline(cin, temp1[3]);
    cout << "Enter vaccine type : ";
    getline(cin, temp1[4]);
    cout << "Enter phone number : ";
    getline(cin, temp1[5]);

    for (int i = 0; i < 5; i++)
    {
        outputFile << temp1[i] << endl;
    }
    
    outputFile.close();
}

//-----------------------------------------userAppMenu function----------------------------------------//
void userAppMenu(loginReturnData logData, User user[], hotspotInfo hotspotArray[]){

    int choice;

    while (true)
    {
        menuPrint(2); //print userAppMenu screen

        cin >> choice;

        switch(choice){
        case 1:
            break;
        case 2:
        {
            user[logData.userIndex].userHealth.setHealthCondition();

            if (user[logData.userIndex].userHealth.getTestResult() == "positive")
            {
                for (int i = 0; i < 4; i++)
                {
                    if(user[logData.userIndex].userHealth.getLocation().compare(hotspotArray[i].getHotspotArea()) == 0)
                    {
                        hotspotArray[i] + 1;
                    }
                }
            }

            break;
        }
            
        case 3:
            //HotspotInfo();
            break;

        case 4:
            //GuideInfo();
            break;
            
        case 5:
            cout<< "Exiting now..."<<endl;
            goto exit_loop;
        
        default:
            cout<<"Please enter the valid number(1-6)"<<endl;
            break;
        }
    }

    exit_loop: ;
}

//---------------------------------------adminLoginMenu function---------------------------------------//
bool adminLoginMenu(admin admin_){

    string userName, password, adminID;
    bool valid;
    
    cout << "\nEnter admin login info" << endl;

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

    while (true)
    {
        menuPrint(1); //print admin app menu screen

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter index of chosen college -> ";
            cin >> index;

            do 
            {
                cout << "Please enter a valid index value - >";
                cin >> index;
            }while(index < 0 || index > 3);
            

            cout << "Enter amount to add -> ";
            cin >> num;

            hotspotArray[index] = hotspotArray[index] + num;
        }

        if (choice == 2)
        {
            goto exit_loop;
        }
        
    }
    
    exit_loop: ;

}

//-----------------------------------------menuPrint function------------------------------------------//
void menuPrint(int n){
    
    if (n == 0) // print login menu
    {
        system("CLS");

        cout<<"\n          LOGIN AND REGISTERATION         "<<endl;
        cout<<"   FOR COV19 ASSIST AND TRACING SYSTEM    "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;
        
        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Admin Login"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"User Login"<<endl;
        cout<< setw(10)<<" 3. "<<setw(10)<<"Register"<<endl;
        cout<< setw(10)<<" 4. "<<setw(10)<<"Exit"<<endl;
    }

    if (n == 1) //print admin menu
    {
        cout<<"\n                  ADMIN                   "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;

        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Edit number of cases"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"Exit"<<endl;
    }

    if (n == 2) // print app menu
    {
        cout<<"\nWELCOME TO COV19 ASSIST AND TRACING SYSTEM"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;
    
        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Donno"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"Health Condition"<<endl;
        cout<< setw(10)<<" 3. "<<setw(10)<<"HotSpot Info"<<endl;
        cout<< setw(10)<<" 4. "<<setw(10)<<"Guide Info"<<endl;
        cout<< setw(10)<<" 5. "<<setw(10)<<"Exit"<<endl;
    }

    if (n == 3)
    {
        cout<<"\n          GUIDE INFO         "<<endl;
        cout<<"   FOR COV19 ASSIST AND TRACING SYSTEM    "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;
        
        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Facilities"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"Hotline Numbers"<<endl;
        cout<< setw(10)<<" 3. "<<setw(10)<<"Standard Operation Procedure (SOP)"<<endl;
        cout<< setw(10)<<" 4. "<<setw(10)<<"Return"<<endl;
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

    system("PAUSE");
    return 0;
}