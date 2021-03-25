#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long d_i,d_o;
int s;
int s_total; //Total guests stayed in the hotel.
int input;
bool running;
bool running_booking;


void booking()
{
 int aux = (d_i + (s-1)); //It will help us to get an approximate of d_o;
 if(d_o<aux){          //compare d_o (day out)
    d_o +=1;
 }else if(d_o<input){   //if d_o compare to the input value
    s +=1;
    s_total+=s;
    d_i = d_o + 1;
 }else{
    running_booking = false;
 }
}

int main()
{
    running =true;
    char option;
    while(running){
    cout << "||Welcome to the HulaRuti Hotel||" << endl;
    cout<<"Options: \n 1) Press any key to know how many guest are in day D\n 2)Press E to exit"<<endl;
    cin>>option;

    switch(option){
    case 'e':
            running =false;
            break;
    default:
            d_i=1;
            d_o =1;
            running_booking = true;
            cout<<"Please enter two values"<<endl;
            cin>>s>>input;
            s_total =s;
            if((s>0)&&(s<10000)){ //First condition
            while(running_booking){
            booking();
            }
            system("cls");
            printf("The No. of Guest in day %d are %d || The total of Guest hosted are: %d \n \n ",input,s,s_total);
            }else{
            system("cls");
            cout<<"I am sorry the input is incorrect"<<endl;
            }

            break;
     }
    }

    return 0;
}
