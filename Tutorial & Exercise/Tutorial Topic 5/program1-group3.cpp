#include<iostream>
#include<string>
using namespace std;

int main()
{
    string p("Welcome to");
    string q("UTM Skudai", 3);

    string s = "100";
    string t = "1";
    string u = "";
    
    cout << p << endl;  // (i). Welcome To
    cout << q << endl;  // (ii). UTM
    cout << p.length() << endl; // (iii). 10
    u = s + t;
    cout << u << endl;  // (iv). 1001
    cout << p.compare(q) << endl;  // (v). 1
    cout << p.substr(0, 3) << endl;  // (vi). Wel
    p.insert(0, "Hello ");
    cout << p << endl;  // (vii). Hello Welcome to
    s.replace(0,2,"99");
    cout << s << endl;  // (viii). 990

    system("pause"); //! remove this line if you are using Dev C++
     
    return 0;
}

