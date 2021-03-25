#include <iostream>

using namespace std;

#define u_size 100
#define v_size 100
#define airlines_size 10
#define INT_MAX 10000000
class airport{
public:

    airport(){
        cost = 0;
        Fill();
    }
    void Add(int start, int destination, int cost,int air);
    void Delete(int u, int v, int airline);
    void Request(int start, int destination, int constraint);
    void Fill(){
        for(int i =0; i<u_size;i++){
            for(int j=0; j<v_size; j++)
                for (int k =0; k<airlines_size; k++)
                    flights[i][j][k] = 0;
        }
    }

    int MinCost(int dist[],bool visited[]);
    int dijkstra(int flights[u_size][v_size][airlines_size],int start,int destination);
  //  void cal(int s);

private:
    int flights[100][100][10]; //[destination][Airlines]
    int cost;
};


void airport::Add(int s, int d,int p,int air){
    //check if it is a cheaper path
    if(flights[s][d][air]){
        if(flights[s][d][air] > p){
            flights[s][d][air] = p;
            flights[d][s][air] = p;
        }
    }else{
        flights[s][d][air] = p;
        flights[d][s][air] = p;
    }
}

void airport::Request(int start, int destination, int constraint){
int price = dijkstra(flights,start,destination);

if(price<= constraint){
    cout<<price<<endl;
}else{
    cout<<-1<<endl;
}
}

void airport::Delete(int u, int v, int airline){
  //  for(int i=0; i<u_size;i++)
       // for(int j = 0; i<u_size; j++)
            flights[u][v][airline]=0;
}

int airport::MinCost(int dist[],bool visited[]){
    int min = INT_MAX; //infinite
    int index= 0;

    for(int i =0; i<u_size; i++){
        if(visited[i]==false && dist[i]<=min){
            min = dist[i];
            index = i;
        }
    }

    return index; //vertex with minimum cost
}

/*void airport::cal(int start){
    dijkstra(flights,start,2);
}*/

int airport::dijkstra(int flights[u_size][v_size][airlines_size],int start,int destination){
    int dist[u_size];
    bool visited[u_size];

    for(int i=0; i<u_size;i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] =0; //this is the starting point

    int transfer = -1; //it help us to know the last state of airline
    for(int k=0; k<u_size-1; k++){
        int u = MinCost(dist,visited);
        visited [u] = true; // for first case
      //  cout<<"-----------------------"<<endl;
        for(int v = 0; v<v_size;v++){
            for(int ar = 0; ar<airlines_size;ar++){
                if((!visited[v]&&flights[u][v][ar]&&dist[u] != INT_MAX)){
                    if(dist[u]+flights[u][v][ar]<dist[v]&& transfer==ar){ //same airline
                        dist[v]=dist[u]+flights[u][v][ar];
                //        cout<<"ar "<<ar<<endl;
                        //transfer = ar;
               //         cout<<"U2 "<<dist[u]<<" flight "<<flights[u][v][ar]<<"V"<<v<<endl;
                    }if((transfer!=ar &&transfer!=-1)&&(dist[u]+flights[u][v][ar]+5 < dist[u]+flights[u][v][transfer]) && dist[u]+flights[u][v][ar]+5<dist[v]){ //transferring
                        dist[v]=dist[u]+flights[u][v][ar];
              //          cout<<"ar "<<ar<<endl;
                        transfer = ar;
            /*           cout<<"U "<<dist[u]<<" flight "<<flights[u][v][ar]<<"V"<<v<<endl;
                       cout<<"DV "<<dist[v]<<endl;*/
                    }else if(dist[u]+flights[u][v][ar]<dist[v]&& transfer==-1){ //first case
                        dist[v]=dist[u]+flights[u][v][ar];
                //        cout<<"ar "<<ar<<endl;
                        transfer = ar;
                   //     cout<<"UT "<<dist[u]<<" flight "<<flights[u][v][ar]<<"V"<<v<<endl;
                 //       cout<<"DV "<<dist[v]<<endl;
                    }else if((transfer!=ar &&transfer!=-1)&&(dist[u]+flights[u][v][ar]+5<dist[v])){ //when there is no other alternative
                        dist[v]=dist[u]+flights[u][v][ar]+5;
                 //       cout<<"ar "<<ar<<endl;
                        transfer = ar;
                 //      cout<<"U3 "<<dist[u]<<" flight "<<flights[u][v][ar]<<"V"<<v<<endl;
                 //       cout<<"DV "<<dist[v]<<endl;
                    }
              }
              /*else if((!visited[v]&&flights[u][v][ar]&&dist[u] != INT_MAX)&& (dist[u]+flights[u][v][ar]+5<dist[v])){ //What if we want to transfer?
                    dist[v]=dist[u]+flights[u][v][ar]+ 5;
                    transfer = ar;
                    cout<<"U3 "<<dist[u]<<" flight "<<flights[u][v][transfer]<<endl;
                    cout<<"DV "<<dist[v]<<endl;
              }*/

            }
        }
    }

   return dist[destination];

}

int main()
{
    airport a;

 /* a.Add(0,1,4,1);
    a.Add(1,2,8,0);
    a.Add(1,2,5,1);
    a.Add(3,2,45,0);
    a.Add(0,1,4,0);
    a.Add(1,2,8,0);
    a.Add(1,2,5,1);
    a.Add(3,2,45,0);*/
    /*a.Add(0,1,4,0);
    a.Add(1,2,15,1);
    a.Add(1,2,10,2);*/
   // a.cal(0);

   string input;
   while(cin>>input){

    if(input=="Add"){
        int st,dest,p,ar;
        cin>>st>>dest>>p>>ar;
        a.Add(st,dest,p,ar);
    }else if(input == "Request"){
        int st,dest,p;
        cin>>st>>dest>>p;
        a.Request(st,dest,p);
    }else if(input == "Delete"){
        int u,v,ar;
        cin>>u>>v>>ar;
        a.Delete(u,v,ar);
    }else{
     continue;
    }
   }
    return 0;
}
