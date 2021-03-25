#include <iostream>
#include <string>
using namespace std;
class LinkedList;

//3nd Version. s108006207

class ListNode{
friend class LinkedList;
public:
   ListNode(int a=0,ListNode* bef =0, ListNode*aft=0){
       data=a; prev =bef; next =aft;
    }
  //  int getData(){return data;}
private:
    int data;
    ListNode *next;
    ListNode *prev;
};

class LinkedList{
public:
    LinkedList(){
        head= new ListNode(-1);
        head->prev=head->next= head;
    }
    void InsertFront(int);
    void InsertBack(int);
    void InsertBefore(int,int);
    void InsertAfter(int,int);
    ListNode* getNode(int); //search and return the node that we are looking for.  If returns 0 then there is not node in the list.
    void DeleteFront();
    void DeleteBack();
    void Delete(int);
    bool isAfter(int, ListNode*);
    void Reverse(int,int); //if pos2>pos1 cannot reverse.
    void Clear();
    void Print();
private:
    ListNode *head; //it is a reference -> it will never be empty.
   // ListNode *first,*last; //It will help us to insertFront and insertLast.

};

void LinkedList::Print(){
    ListNode *aux = head->next;
    while(aux!=head){
        cout<<aux->data<<" ";
        aux= aux->next;
    }
    cout<<"\n";
}
void LinkedList::Delete(int a){
    ListNode *aux = getNode(a);
if(aux){
    /*ListNode *temp1 = aux->next;
    ListNode *temp2 = aux->prev;
    temp2->next = temp1;
    temp1->prev = temp2;
    delete aux;
    aux= NULL;*/

    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

    delete aux;
}
//aux = NULL;
//delete aux;
//aux = NULL;
}

 void LinkedList:: InsertFront(int a){
if(!getNode(a)){
     ListNode *aux = head->next;
     ListNode *temp= new ListNode(a,head,head->next);
     aux->prev = temp;
     head->next = temp;
   //  aux = temp = NULL;
   //  delete aux;
   //  delete temp;
    }
}

void LinkedList::InsertBack(int a){
if(!getNode(a)){
    ListNode *aux = head->prev;
     ListNode *temp= new ListNode(a,head->prev,head);
     aux->next = temp;
     head->prev = temp;
   //  aux = temp = NULL;
   //  delete aux;
    // delete temp;
    }
}
void LinkedList::InsertBefore(int a,int b){ //b is our new data
    ListNode *aux = getNode(a);
    ListNode *temp = getNode(b);
    if(aux && !temp){
        ListNode* aux2 = aux->prev;
        temp = new ListNode(b,aux2,aux);
        aux2->next = temp;
        aux->prev= temp;
     //   aux2 = NULL;
     //   delete aux2;
    }
   // aux = temp = NULL;
   // delete aux;
   // delete temp;

}

void LinkedList::InsertAfter(int a,int b){ //b is our new data
    ListNode *aux = getNode(a);
    ListNode *temp = getNode(b);
    if(aux && !temp){
        ListNode* aux2 = aux->next;
        temp = new ListNode(b,aux,aux2);
        aux2->prev = temp;
        aux->next= temp;
     //   aux2 = NULL;
      //  delete aux2;
    }
   // aux = temp = NULL;
    //delete aux;
    //delete temp;
}


void LinkedList::DeleteFront(){
     ListNode *aux = head->next;
     head->next = head->next->next;
     aux->next->prev = head;
     //aux = NULL;
     delete aux;
     aux = NULL;
}

void LinkedList::DeleteBack(){
     ListNode *aux = head->prev;
     head->prev = head->prev->prev;
     aux->prev->next = head;
    // aux = NULL;
     delete aux;
     aux = NULL;
}

void LinkedList:: Clear(){
    ListNode *aux = head->next;
    ListNode *temp =0;
    while(aux!=head){
        temp = aux;
        aux = aux->next;
        delete temp;
        temp = NULL;
    }
    //aux  = NULL;
   // cout<<"Head n"<<head->next->data<<endl;
  //  delete aux;
    //aux = NULL;
    if(temp){
        delete temp;
        temp =NULL;
    }
    //delete temp;
   // head->next= head->prev = NULL;
    head->next= head->prev = head;
  //  cout<<"Head n"<<head->data<<endl;
}

ListNode* LinkedList::getNode(int a){
    ListNode *ax = head->next;
    while(ax!=head){
        if(ax->data ==a){
            return ax;
        }
        ax= ax->next;
    }
    return 0; //no found
}

 bool LinkedList::isAfter(int b, ListNode* n){
 if(n!=head){
    if(n->data==b) return true;
    else return isAfter(b,n->next);
 }
 return false;
 }

void LinkedList::Reverse(int a,int b){
ListNode *aux= getNode(a);
ListNode *aux2= getNode(b);

if(aux&&isAfter(b,aux->next)){
    ListNode* limN = aux2->next; //right limit
    ListNode* limP = aux->prev;  //left limit
    ListNode* t = 0; //reference
   // ListNode* previous =0; //
   /* while(previous!=LimP){
        t= previous;
        previous = aux2;
        aux2 = aux2->prev;
        previous->prev = t;
        t->next = previous;
        previous->next = aux2;
    }*/
    aux->prev=limN;
  //  limN->prev = aux;
    while(aux!=limP){
        t = aux->prev;
          //cout<<"t "<<t->data<<endl;
     if(aux->prev==limN){limN->prev = aux;}
     if(aux->next!=limN){
        aux->prev = aux->next;
     }else {
        aux->prev = limP;
        limP->next=aux;
    }
     aux->next = t;
     aux = aux->prev;
    }
/*
    cout<<"First n"<<head->next->data<<endl;
    cout<<"First n n "<<head->next->next->data<<endl;
    cout<<"First n n n "<<head->next->next->next->data<<endl;
    cout<<"First n n n n "<<head->next->next->next->next->data<<endl;
*/
   // cout<<"T "<<t->data<<endl;
//    cout<<"t"<<t->data<<endl;
  //  limP->next = aux->prev;
   // aux->next =
   // aux->prev = LimP;

    //limN=t=limP=NULL;
    //delete t;
    //delete limN;
    //delete limP;
    //limN = limP = t= NULL;
}
   /* cout<<"First n"<<head->next->data<<endl;
    cout<<"First n n "<<head->next->next->data<<endl;
    cout<<"First n n n "<<head->next->next->next->data<<endl;
    cout<<"First n n n n "<<head->next->next->next->next->data<<endl;
*/
//aux=aux2=NULL;
//delete aux;
//delete aux2;
//aux = aux2 = NULL; //unused
}





int main(){
    LinkedList li;
    int a,b; //In the 1st version we (I) assign d,e but this is the 2nd :)
    int inLim = 200000;
    string input;
    while(cin>>input && inLim--){
            if(input =="InsertFront"){
                cin>>a;
                    if(a>=0 && a<=500000)li.InsertFront(a);
                    else continue;
            }else if(input=="InsertBack"){
                cin>>a;
                    if(a>=0 && a<=500000)li.InsertBack(a);
                    else continue;
            }else if(input=="InsertBefore"){
                 cin>>a>>b;
                   if(b>=0 && b<=500000) li.InsertBefore(a,b);
                   else continue;
            }else if(input=="InsertAfter"){
                 cin>>a>>b;
                   if(b>=0 && b<=500000) li.InsertAfter(a,b);
                   else continue;
            }else if(input== "DeleteFront"){
                li.DeleteFront();
            }else if(input=="DeleteBack"){
                li.DeleteBack();
            }else if(input=="Delete"){
                cin>>a;
                    li.Delete(a);
            }else if(input=="Reverse"){
                cin>>a>>b;
                    li.Reverse(a,b);
            }else if(input=="Clear"){
                li.Clear();
            }else if(input=="Print"){
                li.Print();
            }else{
                continue;
            }
    }

   /* test cases
   li.InsertFront(5);
    li.InsertFront(25);
    li.InsertFront(50);
    li.Print();
    cout<<"\n";
    li.InsertBack(75);
    li.InsertBack(100);
    li.Print();
      cout<<"\n";
    li.DeleteFront();
    li.Print();
      cout<<"\n";
      li.Clear();
      cout<<"\n";
    li.InsertBack(75);
    li.InsertBack(100);
    li.Print();
      cout<<"\n";
      li.Delete(75);
      li.Print();
      cout<<"\n";
      li.Delete(75);
      li.Print();
      cout<<"\n";
      li.Delete(25);
      li.Print();
      cout<<"\n";
      li.InsertBefore(5,105);
      li.Print();
      cout<<"before 5 \n";
      li.InsertAfter(5,205);
      li.Print();
      cout<<"after 5 \n";
      li.InsertFront(1);
        li.InsertFront(2);
        li.InsertFront(3);
        li.Print();
        cout<<"\n";
      cout<<"Try reverse"<<endl;
      li.Reverse(3,100);
      li.Print();
      cout<<"Try reverse"<<endl;
      li.Reverse(5,2);
      li.Print();

    li.DeleteFront();
    li.Print();
    cout<<"\n";
    li.DeleteBack();
    li.Print();
    cout<<""<<endl;
    li.DeleteBack();
    li.Print();
    cout<<""<<endl;
    li.Clear();
    */
    return 0;
}
