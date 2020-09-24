//
// Created by Chen Gutman id:205616147 and Yarin Mizrahi id:205663917 on 14/11/2019.
//
#include "Calendar.h"
using namespace std;

Calendar::Calendar() {
    for(int i=0;i<30;i++)
    {
        cal[i]=NULL;
    }
}

int Calendar:: setDate(const MyDate& newDate, int num)
{
        if(num>30 || num<1) return -1;
        MyDate* date = new MyDate;
        *date= newDate;
        cal[num-1] = date; // the array is between 0 to 29, so we will enter the date to place num-1.
        return 0;
}

bool Calendar:: isFree(int num){
    if(num>30 || num<1) return false;
    if(cal[num]== nullptr) return true;
}

int Calendar::firstFree()
{
    for(int i=0;i<30;i++)
    {
        if(cal[i]== nullptr)return i+1; //the array is between 0 to 29.
    }
    return -1;
}
int Calendar:: insert(const MyDate& newDate){
    int free;
    free=firstFree();
    if (free ==-1)return -1;
    setDate(newDate,free);
    return 0;
}
int Calendar:: oldest(){
    int index=0;
    bool flag=false;
    MyDate* t_temp;
    for(int i=0;i<30;i++){
        if(cal[i]!= nullptr){
            if(cal[i]->getDay()!=0&&cal[i]->getMonth()!=0&&cal[i]->getYear()!=0){
                if(flag==false ){
                    flag=true;
                    t_temp=cal[i];
                    index=i;
                }
                else{
                    if(t_temp->isBefore(*cal[i])==false)
                    {
                        t_temp=cal[i];
                        index=i;
                    }
                }
            }
        }

    }
    if(flag==false) return -1;
    return index;
}


int Calendar::datesNum(const MyDate& newDate){
    int count=0;
    for(int i=0;i<30;i++) {
        if(cal[i]!= nullptr){
            if (cal[i]->isEquale(newDate)==true) {
                count++;
            }
        }
    }
    return count;

}
void Calendar:: deleteAll(){
    for(int i=0;i<30;i++){
        if(cal[i]!= nullptr){
            cal[i]= new MyDate();
        }
    }
}

int Calendar::deleteDate(int num){
    if(num>30 || num<0) return -1;
    cal[num]= new MyDate();
    return 0;
}

void Calendar:: sortDates(){
    Calendar cal_temp;
    int index,i=0;
    while(i>=0 && i<30){
        index=oldest();
        cal_temp.cal[i]=cal[index];
        deleteDate(index);
        i++;
    }
    for(i=0;i<30;i++){
        cal[i]=cal_temp.cal[i];
    }
}

char* Calendar::print(){
    int count=0,index=0,size;
    char* arr;
    arr=new char;
    for(int i=0;i<30;i++){

        if(cal[i]!= nullptr) {
            char* date;
            date = new char;
            date = cal[i]->print();
            size=strlen(date);
           for(int i = 0;i<size;i++){
               arr[index] = date[i];
               index++;
           }
           delete date;
           arr[index] = ' ';
           index++;
        }
        else{
            count++;
        }
    }
    if(count==30){
       return "Empty Calendar";
    }
    arr[index]={'\0'};
    return arr;
}
