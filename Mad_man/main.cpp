#include <iostream>
#include <string>
using namespace std;

char upper_keys[]={'Q','W','E','R','T','Y','U','I','O','P','[',']'};
char middle_keys[]={'A','S','D','F','G','H','J','K','L',';','\''};
char lower_keys[]={'Z','X','C','V','B','N','M',',','.','/'};
int upper_keys_length;
int middle_keys_length;
int lower_keys_length;
char input[30];
int input_length;
void processing();
void upperInput();
void printing();

int main()
{
    upper_keys_length = sizeof(upper_keys)/sizeof(upper_keys[0]);
    middle_keys_length = sizeof(middle_keys)/sizeof(middle_keys[0]);
    lower_keys_length = sizeof(lower_keys)/sizeof(lower_keys[0]);
    input_length =sizeof(input)/sizeof(input[0]);


    cout << "DECODE THE MAD MAN" << endl;
    cout <<"Please write a statement"<<endl;
    cin.getline(input,100);
    upperInput();
    processing();
    printing();
    return 0;
}


void processing(){
    //l1 = length of input
    int j;
    char proof;
    int l1=input_length;

    for(int i =0;i<l1;i++){
        proof=input[i];
        for(j=0;j<upper_keys_length;j++){
            if(proof==upper_keys[j]){
              // cout<<"Here is"<<endl;
             //  cout<<upper_keys[j]<<endl;
               if((j-2)>=0){
               input[i] = upper_keys[j-2];
               }else{
               input[i] = upper_keys[upper_keys_length+j-2];
               }
              // cout<<"Aqui"<<input[i]<<endl;
            }
        }
        for(j=0;j<middle_keys_length;j++){
            if(proof==middle_keys[j]){
              // cout<<"Here is"<<endl;
                //cout<<middle_keys[j]<<endl;
               if((j-2)>=0){
               input[i] = middle_keys[j-2];
               }else{
               input[i] = middle_keys[middle_keys_length+j-2];
               }
              // cout<<"Aqui"<<input[i]<<endl;
            }
        }
        for(j=0;j<lower_keys_length;j++){
            if(proof==lower_keys[j]){
              // cout<<"Here is"<<endl;
              // cout<<lower_keys[j]<<endl;
               if((j-2)>=0){
               input[i] = lower_keys[j-2];
               }else{
               input[i] = lower_keys[lower_keys_length+j-2];
               }
              // cout<<"Aqui"<<input[i]<<endl;
            }
        }
    }
}

void upperInput(){
    for(int i=0;i<input_length;i++){
        input[i] = toupper(input[i]);
    }
}

void printing(){
    cout<<"The translation is: "<<endl;
for(int k = 0; k<input_length;k++){
    cout<<input[k];
}

}
