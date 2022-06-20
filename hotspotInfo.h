#include <iostream>
#include <string>
using namespace std;


#ifndef HOTSPOTINFO_H
#define HOTSPOTINFO_H

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

        void areaStatusCalc()
        {
            if(infectedNum <=3){areaStatus = "Safe";}
            else {areaStatus = "Not safe";}
        }

        void print()
        {   
            cout << "COVID-19 INFO FOR :" << hotspotArea << endl;
            cout << "Area Status: " << areaStatus << endl;
            cout << "Number of Infected People : " << infectedNum << endl << endl;

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

#endif