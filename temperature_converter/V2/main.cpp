#include <iostream>
#include <cstdio>
using namespace std;

float convertion_fahrenheit (float c){
   float f = (((1.8)*c) +32);

   return f;
}

float convertion_celcius (float f){
   float c = ((f-32)/1.8);

   return c;
}



int main()
{
    float celcius,fahrenheit;


   /* cout << "Hello, How are you? \n  Please enter a temperature  degree (celcius) " << endl;
    cin >>celcius;
    cout << "Thank you, we are converting celcius  into Fahrenheit " << endl;
    //fahrenheit = (((1.8)*celcius) +32);;
    fahrenheit = convertion_fahrenheit(celcius);
    printf("The result is F = %.1f", fahrenheit);
*/

    string name;
    int option;
    bool exit = false;
    cout<< "Hello, What is your name? (please enter your name)" <<endl;
    cin >> name;

    cout << "What do you want to convert? \n 1) Celcius to Fahrenheit \n 2) Fahrenheit to Celcius \n 3) Exit " << endl;
    cin >> option;
    while (!exit){
     switch(option){
      case 1:
        cout << "Please enter a temperature  degree (celcius) " << endl;
        cin >>celcius;
        cout << "Thank you, we are converting celcius  into Fahrenheit " << endl;
        fahrenheit = convertion_fahrenheit(celcius);
        printf("The result is T = %.1f F\n", fahrenheit);
        break;
      case 2 :
         cout << "Please enter a temperature  degree (fahrenheit) " << endl;
        cin >>fahrenheit;
        cout << "Thank you, we are converting Fahrenheit into celcius " << endl;
        celcius = convertion_celcius(fahrenheit);
        printf("The result is T = %.1f C\n", celcius);

        break;
      case 3 :
         exit = true;
         break;
      default:
        cout << "We do not have this option \n" <<endl;
        break;
     }
    }
    cout<< "Bye, Have a nice day " << name;

    return 0;
}



