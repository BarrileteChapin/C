#include <iostream>
#include <stdio.h>

using namespace std;

 const float gRays= 1E-11;
 const float xRays =1E-8;
 const float ultraViolet= 4E-7;
 const float visibleLight= 7E-7;
 const float infrared= 1E-3;
 const float microWaves= 1E-2;

 string g_Rays = "Gamma Rays";
 string x_Rays = "X Rays";
 string ultra_Violet = "Ultraviolet";
 string visible_Light = "Visible Light";
 string infrared_ = "Infrared";
 string microwaves_ = "Microwaves";
 string radioWaves_ = "Radio waves";


string categorize(float f){
 string name;
if (f<gRays ){
    name = gRays;
}else if ((f > gRays)&&(f<xRays)){
    name = x_Rays;
}else if( (f>xRays)&&(f<ultraViolet )){
    name = ultra_Violet;
}else if((f>ultraViolet) && (f<visibleLight)){
    name = visible_Light;
}else if ( (f>visibleLight)&& (f<infrared)){
    name = infrared_;
}else if ((f>infrared)&&(f<microWaves)){
    name = microwaves_;
}else if (f>microWaves){
    name = radioWaves_;
}

return name;
}


int main()
{
    float a,b,c;

    int option;
    bool running = true;
    cout << "Hello, please choose an option"<<endl;

    while(running){
        cout << "1) show table of values \n 2) Find where is the magnitude from \n 3) exit"<<endl;
        cin >> option;
        switch(option){
        case 1 :
            cout <<"Please the page attached"<<endl;
            break;
        case 2:
            cout<<"please, insert three values" <<endl;
            cin>>a;
            cin>>b;
            cin>>c;
            cout<<"The results are: " <<endl;
            cout<<"Scientific notation"<<endl;
            printf("A) %.1e is ",a);
            cout<<categorize(a)<<endl;
            printf("B) %.1e is ",b);
            cout<<categorize(b)<<endl;
            printf("C) %.1e is ",c);
            cout<<categorize(c)<<endl;
            cout<<"Fixed-point notation"<<endl;
            printf("A) %.3f is ",a);
            cout<<categorize(a)<<endl;
            printf("B) %.3f is ",b);
            cout<<categorize(b)<<endl;
            printf("C) %.3f is ",c);
            cout<<categorize(c)<<endl;
            cout<<"thanks"<<endl;

            break;
        default:
            running = false;
            break;
        }
    }




    return 0;
}
