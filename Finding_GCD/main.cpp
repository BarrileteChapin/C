#include <iostream>
#include <windows.h>

using namespace std;


int gcd (int a, int b){

    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int finding_gcd_array(int[], int);

int main()
{
    int a,b,c,d,e;
    cout<<"Hello, please insert 5 values"<<endl;
    cin>>a>>b>>c>>d>>e;
    int numbers [] ={a,b,c,d,e};
    int size_arr = sizeof(numbers) / sizeof(numbers[0]);
    system("cls");
    cout<<"\t---THANK YOU----"<<endl;
    cout<<"The GCD of:"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" is :" <<endl;
    cout<<finding_gcd_array(numbers,size_arr);
    return 0;
}


int finding_gcd_array(int arr[],int s){
  int aux = arr[0];
    for(int i=0; i<s; i++){
        aux = gcd(arr[i], aux);
    }

    return aux;
}

