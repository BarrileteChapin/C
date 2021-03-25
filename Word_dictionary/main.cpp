#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <string> //npos

using namespace std;


ifstream inputFile;

map<string,int>mapWords; //word, times repeated.


void readingFile();
string modifyingString(string);
void printing();
bool word_is_repeated(string);
bool sort_condition(pair<string,int>p1, pair<string,int>p2){
    return (p2.second<p1.second);
}

int main()
{
    cout << "Hello world!" << endl;
    readingFile();
    printing();
    inputFile.close();
    return 0;
}

string modifyingString(string s){
char symbols[] = {'(',')','[',']','-','_','!','/',',','.','?','*','"',':',';','\\'};

for(int i =0; i<(sizeof(symbols)/sizeof(symbols[0]));i++){
    size_t positionS = s.find(symbols[i]);
    if(positionS != string::npos)
        s.erase(positionS,1);
}

for(int i =0; i<(sizeof(symbols)/sizeof(symbols[0]));i++){
    size_t positionS = s.find(symbols[i]);
    if(positionS != string::npos)
        s.erase(positionS,1);
}

return s;
}

void readingFile(){
string nameFile;
string temp;

cout<<"Please,write the name of the file (.txt)"<<endl;
cin>>nameFile;
nameFile="C:\\"+nameFile+".txt";

inputFile.open(nameFile.c_str());
cout<<nameFile<<endl;
if(inputFile.is_open()){
    while(!inputFile.eof()){
        inputFile>>temp; //only reads strings.
        temp=modifyingString(temp);
        cout<<temp<<" ";
        //transform(temp.begin(),temp.end(),temp.begin(),::toupper);
            if(!word_is_repeated(temp)){
                mapWords.insert(make_pair(temp,1));
            }else{
                mapWords[temp]++;
            }
    }
    cout<<"\n";
}else{
    cout<<nameFile<<" Cannot be open"<<endl;
}

}

bool word_is_repeated(string w){
bool state = false;

map<string,int> ::iterator it = mapWords.begin(); //iterator

while (it!= mapWords.end()){
    if(it->first.compare(w)){
     state =true;
     break;
    }
    it++;
}

return state;
}

void printing(){
map<string,int> ::iterator it= mapWords.begin();
vector<pair<string,int> > v_aux;

while ( it!= mapWords.end()){
    v_aux.push_back(make_pair(it->first,it->second));
    it++;
}

sort(v_aux.begin(),v_aux.end(),sort_condition);

cout<<"\n"<<"Numbers of Words: "<<v_aux.size()<<endl;
for(int i=0;i<10;i++){
    cout<<i<<"-th frequent word: "<<setw(20)<<v_aux[i].first<<setw(5)<<"\t appeared: "<<v_aux[i].second<<" times"<<endl;
}
}
