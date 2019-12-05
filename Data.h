#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H
#include "Data.h"
#include<iostream>
#include<fstream>
using namespace std;
#include<string>
class Data {
public:
    Data();
    Data(int id, int act,int dur, int code);
    int caseID;
    int activity;
    int duration24Hours;
    int codeP;
    friend ostream& operator<<(ostream& os, const Data& data);
    bool operator>( Data& d1);
    bool operator<( Data& d1);
    bool operator<=( Data& d1);
    bool operator>=( Data& d1);
    Data& operator=( Data& c);
    void setCaseID(int c){caseID=c;};
    void setActivity(int a){activity=a;};
    void setDuration(int d){duration24Hours=d;};
    void setCodeP(int cp){codeP=cp;};
    int getCaseID(){return caseID;};
    int getActivity(){return activity;};
    int getDuration(){return duration24Hours;};
    int getCodeP(){return codeP;};

private:

};


#endif //PROJECT7_DATA_H
