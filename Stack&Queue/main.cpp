#include <iostream>

using namespace std;

class Aritmetic;

class Queue { //circular queque
friend class Aritmetic;
public:
    Queue (int q_capi = 30) {
        queue_cap = q_capi;
        front = rear= -1;
        queue = new char [queue_cap];
       // queue[-1] ='N';
    };

    bool isEmpty() const;

    char Front() ;

    char Rear() const;

    void Push(const char &data);

    void Pop();
    void Dequeue (int);
private:
    char* queue;
    int front, rear;
    int queue_cap;
};

bool Queue::isEmpty() const{
return front ==rear;
}

void Queue::Push(const char &d){

    rear = (rear+1)%queue_cap;
    queue[rear] = d;
   // cout<<"The rear is " <<rear<<endl;
   // cout<<"Cap "<<queue_cap<<endl;
}

void Queue::Pop(){

    if(isEmpty()){
        throw "Nothing inside Queque";
    }
    //queue[front] = 0;
    front = (front+1)%queue_cap;
   // cout<<"No cout (pop) "<<front<<endl;
    queue[front] = 0;
}

char Queue::Front(){
    return queue[front+1];
}

char Queue::Rear() const{
    return queue[rear];
}

void Queue::Dequeue(int d){
    int c=0;
    while(c<d&& !isEmpty()){
        Pop();
        c++;
    }
}
//Stack it will help us to find the postfix.
class Stack {
friend class Aritmetic;
public:
    Stack (int s_capi = 30) {
        stack_cap = s_capi;
         top = -1;
        stack = new char [stack_cap];
    };
    ~Stack (){
        delete [] stack;
    }

    bool isEmpty() const;

    char Top()const;

    void Push(const char &d);

    void Pop();

    int top;
private:
    char* stack;
   // int top;
    int stack_cap;
};
bool Stack::isEmpty() const{
return top ==-1;
}
void Stack::Push(const char &d){

    if(top>=stack_cap){
        throw "Stack is full";
    }
    // cout<<"pas"<<endl;
    stack[++top] = d;

}
void Stack::Pop(){

    if(isEmpty()){
        return;
    }else{
        stack[top] = 0;
        --top;
    }
}


char Stack::Top()const{
char c =0;
if(!isEmpty()){
c = stack[top];
}//else{cout<<"Stack EMPTY";}
//cout<<"pasa c (top) "<<c<<endl;
return c;
}

class Aritmetic{
public:
 //   string msg;
 //   string sque;
    Aritmetic(){
        q = new Queue();
        postfix = new Stack();
        Stack s;
     //   sque="";
     //   msg = "Valid";
    }
    int icp(char s);
    string FindingPostfix();
    char getNext(Queue *);
    int OperatingPostfix(string);
    void Print();
    void Insert(const string &d){
        if(!q->isEmpty())q->rear-=1;
        for(int i=0;i<=d.size();i++){
            q->Push(d[i]);
        }
    }
  /*  void Enqueue(char &c){
        if(!q->isEmpty())q->rear-=1;
        q->Push(c);
    }*/
    void Dequeque(int d){q->Dequeue(d);}
    Queue* getQueue(){return q;}
    Stack* getStack(){return postfix;}
    char getchar(int index){return q->queue[index];};
    bool isOperator(char);
    bool isOperand(char);
private:
    Queue *q;
    Stack *postfix;

};

int Aritmetic::icp(char s){ //According to figure 3.15 of the textbook.
if(s == '!'){
    return 1;
}else if(s=='*'|| s=='/'|| s=='%'){
    return 2;
}else if(s=='+'|| s=='-'){
    return 3;
}else if(s=='('){
    return 8;
}/*else if(s=='<'|| s=='<='||s=='>='||s=='>'){
    return 4;
}else if(s=='=='||s=='!='){
    return 5;
}else if(s=='&&'){
    return 6;
}else if(s=='||')
    return 7;*/
}

char Aritmetic::getNext(Queue * qp){
    char c = qp->Front();
  //  cout<<"JSdw "<<c<<endl;
    qp->Pop();
  //  cout<<"JASDF "<<c<<endl;
    return c;
}

bool Aritmetic::isOperator(char c){
    if(c == '+'||c=='-'||c=='*'||c=='/'){
        return true;
    }else{
        return false;
    }
}

bool Aritmetic::isOperand(char c){
    if(c>='a' && c<='z'){
        return true;
    }else if(c>='A' && c<='Z'){
        return true;
    }else if(c >= '0' && c<='9'){
        return true;
    }else{
        return false;
    }
}

string Aritmetic::FindingPostfix(){
    Queue *aux = new Queue();
    int pl,pr; //parenthesis on the left & right.
    pl=pr=0;
    for(int i =q->front+1; i<q->rear;i++){ //copy queue
        char c = getchar(i);
        if(c=='(') pl++;
        else if(c==')') pr++;
        cout<<c;
        aux->queue[i] =c;
    }
    cout<<"\n";
    int lima = q->front;
    int limb = q->rear;
    aux->rear = limb;
    aux->front = lima;

    if(pl!=pr){
      return "Invalid"; //Parenthesis error
    }

    string s ="";
    Stack Spost;
    aux->Push('#');
    for(char x = getNext(aux); x!='#';x=getNext(aux)){
        if(isOperand(x)) s+=x;
        else if(x==')'){
            for(;Spost.Top()!='(' &&!Spost.isEmpty();Spost.Pop()){
                s+=Spost.Top();
                 //cout<<"Here_"<<s<<endl;
            }
         //   if(Spost.isEmpty() && Spost.Top()!='(')cout<<"NO FODA "<<endl;
            Spost.Pop(); //when '(' is found,pop it.
        }
        else{

            for(;icp(Spost.Top())<= icp(x) && !Spost.isEmpty() && x!='(';Spost.Pop())
                s+=Spost.Top();
               // cout<<"Quiza s_"<<s<<endl;

            Spost.Push(x);
        }

    }


    delete aux;
    Spost.Pop();     //Because there is a blank space, I am not sure where is coming from but it solves the problem. :)
    for(;!Spost.isEmpty();s+=Spost.Top(),Spost.Pop());

return s;
}

int Aritmetic::OperatingPostfix(string txt){
int siz = txt.size();
int result=0;
int term =0;
int a,b;
char in;
Stack all;
all.Push('#');
    for (int j =0; j<=siz; j++){
        in = txt[j];
        if(isOperand(in)){
          all.Push(in-48);
 //        cout<<"in "<<in<<endl;
        }else if(in=='+'){
            a = all.Top(); all.Pop();
            b = all.Top(); all.Pop();
 //          cout<<"a "<<a<<endl;
 //          cout<<"b "<<b<<endl;
            if(b=='#')return -1;
            else{
            term = a+b;
            all.Push(term);
            }
//          cout<<"S "<<term<<endl;
        }else if(in=='-'){
            a = (int)all.Top(); all.Pop();
            b = (int)all.Top(); all.Pop();
            if(b=='#')return -1;
            else{
                term = b - a;
                all.Push(term);
            }
//          cout<<"S2 "<<term<<endl;
        }else if(in=='/'){
            a = (int)all.Top(); all.Pop();
            b = (int)all.Top(); all.Pop();
            if(b=='#')return -1;
            else{
                term = b/a;
                all.Push(term);}
  //      cout<<"S3 "<<term<<endl;
        }else if(in=='*'){
            a = (int)all.Top(); all.Pop();
            b = (int)all.Top(); all.Pop();
            if(b=='#')return -1;
            else{
            term = a*b;
            all.Push(term);
            }
   //        cout<<"S4 "<<term<<endl;
        }else{
           // cout<<"result "<<(all.Top()-'0')%47<<endl;
            return result = all.Top();
        }
    }

//    value.Push('#');
   // for()
}

int main()
{
  Aritmetic a;
  string input;
    int lin =2;
  while(cin>>input){
    //cout<<input<<endl;
    if(lin==2){a.Insert(input); lin--;}
    else if(input=="Dequeue"){
        int n;
        cin>>n;
        a.Dequeque(n);
    }else if(input=="Enqueue"){
        string ch;
        cin>>ch;
     //   cout<<"C is "<<ch<<endl;
        a.Insert(ch);
    }else if(input=="Print"){
        if(lin!=1){
               cout<<"\n";
         }
        string post = a.FindingPostfix();
        int op = a.OperatingPostfix(post);
        if(post !="Invalid" && op!=-1 ){//&& op!=35){ //op!=35 because is empty
            cout<<post<<endl;
            cout<<op;
        }else{
            cout<<"Invalid";
        }
         lin--;
    }else{
        continue;
    }

  }
    return 0;
}
