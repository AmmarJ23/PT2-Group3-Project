// Group 3
// Members: 1. Afiq Fahmi Bin Roslan    A21EC0153
//          2. Azhan Haniff Bin Azni    A21EC0017
//          3. Ryan Lim Shen            A21EC0223
//          4. Ammar bin Jamalludin     A21EC0160

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "loginInfo.hpp"
#include "hotspotInfo.hpp"
#include "healthCondition.hpp"
#include "User.hpp"
#include "admin.hpp"
using namespace std;

//global variable for number of users
int USER_NUM;

//----------------------------------------loginReturnData struct----------------------------------------//
struct loginReturnData
{
    bool valid;
    int userIndex;
};

//function prototype
void getUserData(User []);
void LoginMenu(User [], admin , hotspotInfo []);
loginReturnData userLoginMenu(User []);
void userRegister(User[]);
void userAppMenu(loginReturnData, User[], hotspotInfo[]);
bool adminLoginMenu(admin);
void adminAppMenu(hotspotInfo[], admin);
void menuPrint(int);
void guideInfo();

//----------------------------------------getUserData function------------------------------------------//
void getUserData(User user[]){

    string temp1[6];
    ifstream inputFile("User_Data.txt");

    if (inputFile.is_open() == false)
    {
        ofstream makeFile("User_Data.txt");
        makeFile << "0";
        makeFile.close();
        cout << "'User_Data.txt' File not found. Creating file..." << endl;
        system("PAUSE");
    }
    
    inputFile >> USER_NUM;

    if (USER_NUM != 0)
    {
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
        
        cout<<"Enter the number between 1-4 = ";
        cin >> choice;
        cout<<endl;

        switch(choice){
            case 1:
            {
                bool adminValid = adminLoginMenu(admin_);
                if (adminValid == true)
                {
                    adminAppMenu(hotspotArray, admin_);
                }
                break;
            }
            
            case 2:
            {

                if (USER_NUM == 0)
                {
                    cout << "No registered users found / 'User_Data.txt' file not found" << endl;
                    system("PAUSE");
                }
                else
                {
                    loginReturnData userLogData =  userLoginMenu(user);
                    if (userLogData.valid == true)
                    {
                        userAppMenu(userLogData, user, hotspotArray);
                    }
                }
                break;
                
            }
                
            case 3:

                userRegister(user);
                break;

            case 4:
                cout<< "Exiting now..."<<endl;
                goto exit_loop;
            
            default:
                cout<<"Please enter a valid number(1-4)"<<endl;
                break;
        }
    }

    exit_loop: ;
}

//----------------------------------------userLoginMenu function----------------------------------------//
loginReturnData userLoginMenu(User user[]){

    string userName, password;
    loginReturnData logReturn;

    logReturn.valid = false;

    cout << "Enter user login info" << endl;
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
        system("PAUSE");
    }
    
    return logReturn;
}

//----------------------------------------userRegister function-----------------------------------------//
void userRegister(User user[]){
    string temp1[6];
    string tempBin = "";
    int userNumTemp = USER_NUM;
    int userSkip = USER_NUM * 5;

    ofstream outputFile("User_DataTemp.txt");
    outputFile << USER_NUM + 1 << endl;

    //ofstream outputFile("User_Data.txt", std::ios_base::app);
    ifstream inputFile("User_Data.txt");

    getline(inputFile,tempBin);

    for (int i = 0; i < userSkip + 5; i++)
    {
        getline(inputFile, tempBin);
        outputFile << tempBin << endl;
    }

    cin.ignore();

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

    for (int i = 0; i < 6; i++)
    {
        outputFile << temp1[i] << endl;
    }

    inputFile.close();
    outputFile.close();
    remove("User_Data.txt");
    
    rename("User_DataTemp.txt", "User_Data.txt");

    User userTemp(temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5]);
    user[USER_NUM] = userTemp;

    USER_NUM++;

    cout << "\nRegistration successful, you may now log in using the registered account." << endl;
    system("PAUSE");
}

//-----------------------------------------userAppMenu function-----------------------------------------//
void userAppMenu(loginReturnData logData, User user[], hotspotInfo hotspotArray[]){

    int choice;
    int tempCollege;

    while (true)
    {
        menuPrint(2); //print userAppMenu screen
        
        cout<<"Enter a number between 1-5 = ";
        cin >> choice;
        cout << endl;

        switch(choice){
        case 1:
        {
            user[logData.userIndex].userHealth.setHealthCondition();

            for (int i = 0; i < 4; i++)
            {
                if(user[logData.userIndex].userHealth.getLocation().compare(hotspotArray[i].getHotspotArea()) == 0)
                {
                    if (user[logData.userIndex].userHealth.getTestResult() == "positive")
                    {
                        hotspotArray[i] = hotspotArray[i] + 1;
                    }
                    
                    tempCollege = i;
                }
            }

            user[logData.userIndex].setCollege(hotspotArray[tempCollege]);
            break;
        }
            
        case 2:
            for (int i = 0; i < 4; i++)
            {
                hotspotArray[i].print();
            }
            system("PAUSE");
            break;

        case 3:
            guideInfo();
            system("PAUSE");
            break;

        case 4:
            user[logData.userIndex].print();
            system("PAUSE");
            break;

        case 5:
            cout << endl;
            if (user[logData.userIndex].getCollege() != NULL)
            {
                user[logData.userIndex].getCollege()->print();
            } else {cout << "No college linked with user. \nPlease complete a health self-check to check user college information." << endl;}
            cout << endl;
            system("PAUSE");
            break;

        case 6:
            cout<< "Exiting now..."<<endl;
            system("PAUSE");
            goto exit_loop;

        default:
            cout<<"Please enter a valid number(1-4)"<<endl;
            system("PAUSE");
            break;
        }
    }

    exit_loop: ;
}

//---------------------------------------adminLoginMenu function----------------------------------------//
bool adminLoginMenu(admin admin_){

    string userName, password, adminID;
    bool valid;
    
    cout << "Enter admin login info" << endl;

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
        system("PAUSE");
    }
    
    return valid;
}

//---------------------------------------adminAppMenu function------------------------------------------//
void adminAppMenu(hotspotInfo hotspotArray[], admin admin_){

    int choice, index, num;

    while (true)
    {
        menuPrint(1); //print admin app menu screen
        
        cout<<"Enter a number between 1-2 = ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "Enter index of chosen college -> ";
            cin >> index;

            if (index < 0 || index > 3)
            {
                do 
                {
                    cout << "Please enter a valid index value -> ";
                    cin >> index;
                }while(index < 0 || index > 3);
            }
            
            cout << "Enter amount to add -> ";
            cin >> num;

            hotspotArray[index] = hotspotArray[index] + num;
        }

        else if (choice == 2)
        {
            admin_.print();
            system("PAUSE");
        }

        else if (choice == 3)
        {
            goto exit_loop;
        }

        else 
        { 
            cout << "Please enter a valid number" << endl;
            system("PAUSE");
        }
        
    }
    
    exit_loop: ;

}

//-----------------------------------------menuPrint function-------------------------------------------//
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
        cout<< setw(10)<<" 4. "<<setw(10)<<"Exit"<<endl<<endl;
    }

    if (n == 1) //print admin menu
    {
        system("CLS");
        
        cout<<"\n                  ADMIN                   "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;

        cout<<left<< setw(10)<<" 1. "<< setw(10) << "Edit number of cases" << endl;
        cout<< setw(10)<<" 2. "<< setw(10) <<"Admin Information"<< endl;
        cout<< setw(10)<<" 3. "<< setw(10) <<"Exit"<< endl << endl;
    }

    if (n == 2) // print app menu
    {   
        system("CLS");
        
        cout<<"\nWELCOME TO COV19 ASSIST AND TRACING SYSTEM"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;
    
        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Health Condition Self-Check"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"HotSpot Info"<< endl;
        cout<< setw(10)<<" 3. "<<setw(10)<<"Guide Info"<< endl;
        cout<< setw(10)<<" 4. "<<setw(10)<<"User Information"<<endl;
        cout<< setw(10)<<" 5. "<<setw(10)<<"User College Information"<<endl;
        cout<< setw(10)<<" 6. "<<setw(10)<<"Exit"<<endl << endl;
    }

    if (n == 3)
    {   
        system("CLS");

        cout<<"\n             GUIDE INFO         "<<endl;
        cout<<"   FOR COV19 ASSIST AND TRACING SYSTEM    "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"         PLEASE ENTER YOUR CHOICE         "<<endl;
        cout<<"------------------------------------------"<<endl;
        
        cout<<left<< setw(10)<<" 1. "<<setw(10)<<"Facilities"<<endl;
        cout<< setw(10)<<" 2. "<<setw(10)<<"Hotline Numbers"<<endl;
        cout<< setw(10)<<" 3. "<<setw(10)<<"Standard Operation Procedure (SOP)"<<endl;
        cout<< setw(10)<<" 4. "<<setw(10)<<"Return"<<endl<<endl;
    }
}

//-------------------------------------------guideInfo function-----------------------------------------//
void guideInfo()
{   
    
    int choice;

    while (true)
    {
        menuPrint(3); //print guideInfo screen


        cout<<"Enter the number between 1-4 = ";
        cin >> choice;

        switch(choice){
            case 1:
                {
                    system("CLS");
                    
                    cout<<"CARE PROVIDED IN UTM FOR COV-19 PATIENTS"<<endl;
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"COMPLIMENTARY MEALS(3 TIMES PER DAY)"<<endl;
                    cout<<"COMPLIMENTARY SELF TEST KIT(AFTER QUARANTINE IS COMPLETED)"<<endl;
                    cout<<"COMPLIMENTARY MEDICINE(FOR SYMPTOMS)"<<endl;
                    
                    cout<<"-------------------------------------------"<<endl;
                    cout<<"FREE SWAB TEST AND QUARANTINE AREA PROVIDED"<<endl;
                    cout<<"AT KOLEJ TUN RAZAK(KTR)"<<endl;
                    cout<<"-------------------------------------------"<<endl;
                    cout<<"STUDENTS MUST REGISTER FIRST IN ORDER TO ACCESS THESE PRIVILEDGES"<<endl << endl;
                    system("PAUSE");
                    break;
                }

            case 2:
                {
                    system("CLS");
                    
                    cout<<"HOTLINES NUMBERS"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"COVID-19 HOTLINE          ="<<setw(15)<<"+60133340646"<<endl;
                    cout<<"UTM AMBULANCE             ="<<setw(15)<<"+6075530999"<<endl;
                    cout<<"UTM HEALTH CENTRE         ="<<setw(15)<<"+60197756765"<<endl;
                    cout<<"STUDENT AFFAIRS HOTLINE 1 ="<<setw(15)<<"+6075530279"<<endl;
                    cout<<"STUDENT AFFAIRS HOTLINE 2 ="<<setw(15)<<"+6075530265"<<endl << endl;
                    system("PAUSE");
                    break;
                }
            
            case 3:
                {
                    system("CLS");
                    
                    cout<<"Protocol for positive cases:"<<endl;

                    cout<<"The isolation order for patients infected with ALL variants are as follows:"<<endl;
                    cout<<"1. Seven days for individuals who are fully vaccinated and have no symptoms."<<endl;
                    cout<<"2. 10 days for individuals who have incomplete vaccinations, or are symptomatic cases."<<endl<<endl;

                    cout<<"A health assessment will be made before discharge can be granted."<<endl<<endl;

                    cout<<"Protocol for close contacts:"<<endl;

                    cout<<"Isolation orders for close contacts of positive cases, including Omicron cases, are as follows:"<<endl;

                    cout<<"1. Five days for individuals who have already received the booster dose."<<endl;
                    cout<<"2. Seven days for individuals who are fully vaccinated, and those who are partially or are not vaccinated."<<endl;
                    cout<<"3. If symptomatic, take the RTK-Ag test, either on your own or at a nearby health facility for further treatment."<<endl;
                    cout<<"4. Results of the self-test must be submitted in the Mysejahtera application. "<<endl;
                    cout<<"5. Perform the RTK-Ag test, either at a government or private facility, on the fifth day and the seventh day (for those undergoing seven days of isolation)."<<endl;
                    cout<<"6. If the test results are negative and the individual is asymptomatic, a quarantine release will be given on the same day the test is performed."<<endl << endl;
                    system("PAUSE");
                    break;
                }

            case 4:
                cout<< "Returning to AppMenu..."<<endl;
                goto exit_loop;
                break;     
        
            default:
                cout<<"Please enter the valid number(1-4)"<<endl;
                system("PAUSE");
                break;
        }
    }

    exit_loop: ;
};

//--------------------------------------------main function---------------------------------------------//
int main(){
    system("Color 0E");
    ifstream inFile("User_Data.txt");
    inFile >> USER_NUM;
    inFile.close();

    User userArray[100];
    admin admin_("Admin", "Admin123", "001122");
    hotspotInfo hotspotArray[4] = {hotspotInfo("KTHO",0), hotspotInfo("KTDI",2), hotspotInfo("KTC",6), hotspotInfo("KTF",9)};
    getUserData(userArray);

    LoginMenu(userArray, admin_, hotspotArray);
    

    system("PAUSE");
    return 0;
}