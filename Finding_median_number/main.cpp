#include <iostream>
#include <algorithm> //this is for sorting;
#include <math.h>
#include <stdlib.h>
using namespace std;

class Complex{

private:
    double real,imaginary;
public:
    Complex(double,double);
    friend Complex operator+(Complex const &,Complex const &);
    friend Complex operator-(Complex const &, Complex const &) ;
    friend Complex operator/(Complex const &,Complex const &);
    double getreal();
    double getimaginary();
    double setreal(double);
    double setimaginary(double);
    double getMagnitude();
    friend ostream& operator<<(ostream&,Complex);
};

Complex::Complex(double r =0, double i=0){
    real = r;
    imaginary = i;
}

//overloading

Complex operator+(Complex const &c1,Complex const &c2){
    Complex result (c1.real+c2.real, c1.imaginary+c2.imaginary);
    return result;
}


Complex operator-(Complex const &c1, Complex const &c2){
   Complex result (c1.real-c2.real, c1.imaginary-c2.imaginary);
    return result;
}


Complex operator/(Complex const &c1,Complex const &c2){
    Complex result (c1.real/c2.real, c1.imaginary/c2.imaginary);
    return result;
}


//printing (overloading)

ostream& operator<<(ostream& out, Complex c){
    out<<c.getreal()<<"+"<<c.getimaginary()<<"i"<<"\n";
    return out;
}

//Setters and getters

double Complex::getreal(){
    return real;
}

double Complex::getimaginary(){
    return imaginary;
}

double Complex::setreal(double r){
    real = r;
}

double Complex::setimaginary(double i){
    imaginary = i;
}

//get Vector magnitude

double Complex:: getMagnitude(){
    double x = sqrt(pow(real,2)+pow(imaginary,2));
    return x;
}


Complex a,b,c,d,e,f,g;
Complex numbers[]={a,b,c,d,e,f,g};
int length_array = sizeof(numbers)/sizeof(numbers[0]);
void assigning_values();
bool comparison(Complex,Complex);
void sorting();
void showing();
Complex getMedian();
Complex getMean();

int main()
{
    cout<<"FINDING THE MEDIAN"<<endl;
    assigning_values();
    showing();
    cout<<"\-----\\ Input values"<<endl;
    sorting();
    showing();
    cout<<"\-----\\ Sorted"<<endl;
    cout<<"The median is\t"<<endl;
    cout<<getMedian();
    cout<<"The mean is\t"<<endl;
    cout<<getMean();
    cout<<"\-----\\"<<endl;

    return 0;
}

void assigning_values(){
    double re;
    double im;
    cout<<"Please input 5 complex numbers"<<endl;
    cout<<"1) Real" <<endl;
    cin>>re;
    numbers[0].setreal(re);
    cout<<"1) Complex" <<endl;
    cin>>im;
    numbers[0].setimaginary(im);
    system("cls");
    cout<<"2) Real" <<endl;
    cin>>re;
    numbers[1].setreal(re);
    cout<<"2) Complex" <<endl;
    cin>>im;
    numbers[1].setimaginary(im);
    system("cls");
    cout<<"3) Real" <<endl;
    cin>>re;
    numbers[2].setreal(re);
    cout<<"3) Complex" <<endl;
    cin>>im;
    numbers[2].setimaginary(im);
    system("cls");
    cout<<"4) Real" <<endl;
    cin>>re;
    numbers[3].setreal(re);
    cout<<"4) Complex" <<endl;
    cin>>im;
    numbers[3].setimaginary(im);
    system("cls");
     cout<<"5) Real" <<endl;
    cin>>re;
    numbers[4].setreal(re);
    cout<<"5) Complex" <<endl;
    cin>>im;
    numbers[4].setimaginary(im);
    system("cls");
     cout<<"6) Real" <<endl;
    cin>>re;
    numbers[5].setreal(re);
    cout<<"6) Complex" <<endl;
    cin>>im;
    numbers[5].setimaginary(im);
    system("cls");
     cout<<"7) Real" <<endl;
    cin>>re;
    numbers[6].setreal(re);
    cout<<"7) Complex" <<endl;
    cin>>im;
    numbers[6].setimaginary(im);
    system("cls");

}

bool comparison(Complex co1,Complex co2){
    return(co1.getMagnitude()<co2.getMagnitude());
}

void sorting(){
    //use function sort
    sort(numbers,numbers+length_array,comparison);
}

void showing(){
    for(int i=0; i<length_array;i++){
        cout<<numbers[i];
    }
}

Complex getMedian(){
    int median = (length_array/2);
   // cout<<median<<endl;
    return numbers[median];
}

Complex getMean(){
    Complex mean;
    for (int i=0;i<length_array;i++){
        mean= mean+numbers[i];
    }
    mean.setimaginary(mean.getimaginary()/(length_array+1));
    mean.setreal(mean.getreal()/(length_array+1));

    return mean;
}
