#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

double pitch[]={0,523.3,587.3,659.3,698.5,784.0,880.0,932.3,987.8,1000};
int readingNote();
void playingNotes(int note);

int main()
{
   /* double pitch[]={0,523.3,587.3,659.3,698.5,784.0,880.0,932.3,987.8,1000};
    int music[]={5,3,3,0,0,0,4,2,2,0,0,0,1,2,3,4,5,5,5,0,0,0,5,3,3,0,0,0,4,2,2,0,0,0,1,3,5,5,1};
    for (int i =0; i<39;i++){
        if(music[i]==0)usleep(150000);
        else Beep(pitch[music[i]],400);
    }*/
    cout <<"Please, choose an :\n a. Play default song\n b.playing piano\nc. exit\n" <<endl;
    char option;
    bool running = true;
    while(running){
    cout << "Enter a option" << endl;
    cin>>option;
    switch(option){
        case 'a':
        {
         int music[]={5,3,3,0,0,0,4,2,2,0,0,0,1,2,3,4,5,5,5,0,0,0,5,3,3,0,0,0,4,2,2,0,0,0,1,3,5,5,1};
         for(int j =0; j<=sizeof(music[0]);j++){
          playingNotes(music[j]);
         }
        }
         break;
        case 'b':
            {
            while(1){
                int note = readingNote();
                system("cls");
                playingNotes(note);
            }
        }
        case 'c':
                running = false;
                break;
    }
    cout<<readingNote()<<endl;
    }
    return 0;
}

int readingNote(){
    int a;
    a = _getch();
    if((a>47)&&(a<=58)){
        a %=48;
    }
    return a;
}

void playingNotes(int note){
int sleeping_time = 150000;
int rate = 400;
    if(note==0){
        usleep(sleeping_time);
    }else if(note>sizeof(pitch[0])){
        cout<<"I am sorry, this is not a key"<<endl;
    }else{
        Beep(pitch[note],rate);
    }
}
