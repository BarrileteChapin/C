#include <iostream>
#include <stdio.h>
using namespace std;




int main()
{

    cout << "Hello, please choose an option"<<endl;

    cout << "1) convert C to F \ 2) convert F to C \ 3) exit"<<endl;
    int a;
    cin >> a;

    float i,r;


    switch(a){
     case 1:
         cout<<"please, input a value"<<endl;
         cin >>i;
         r = (((1.8)*(i))+32);
         printf ("The result if C: %.1f",r);
         break;
     case 2:
         float i;
         cout<<"please, input a value"<<endl;
         cin >>i;
         r = ((i-32)/1.8);
         printf ("The result if F: %.1f",r);
         break;
 default:
        break;

    }

    return 0;
}
