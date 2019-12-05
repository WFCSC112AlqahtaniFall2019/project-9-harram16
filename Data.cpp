//
// Created by Addie Harrison on 11/13/19.
//

#include "Data.h"
#include<iostream>
#include<fstream>
using namespace std;
#include<string>
//constructors
Data::Data(){
    int caseID=0;
    int activity=0;
    int duration24Hours=0;
    int codeP=0;

}
Data::Data(int id, int act,int dur, int code){
    caseID=id;
    activity=act;
    duration24Hours=dur;
    codeP=code;
}
bool Data::operator>( Data& d1){
    return duration24Hours > d1.getDuration();

}
bool Data::operator<( Data& d1){

    return duration24Hours<d1.getDuration();

}
bool Data::operator<=( Data& d1){
    return duration24Hours<=d1.getDuration();

}

bool Data:: operator>=( Data& d1){
    return duration24Hours>=d1.getDuration();

}
Data& Data::operator=( Data& c){

    Data temp(c);
    swap(temp.caseID,caseID);
    swap(temp.activity,activity);
    swap(temp.duration24Hours,duration24Hours);
    swap(temp.codeP,codeP);

    return *this;
}

ostream& operator<<(ostream& os, const Data data){
    os<< "24 Hour Durationon Computer: "<< data.duration24Hours<<"  Case Id: "<<data.caseID<<"  Code: "<<data.codeP<<"  Computer Activity: "<<data.activity<<endl;
    return os;
}