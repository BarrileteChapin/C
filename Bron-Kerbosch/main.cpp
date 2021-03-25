#include <bits/stdc++.h>

// reference to the code: Miguel Diaz in https://stackoverflow.com/questions/43759341/bron-kerbosch-algorithm-in-c
// https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
//https://www.researchgate.net/publication/318799595_Adapting_the_Bron-Kerbosch_algorithm_for_enumerating_maximal_cliques_in_temporal_graphs
//time complexity's analysis: https://snap.stanford.edu/class/cs224w-readings/tomita06cliques.pdf
using namespace std;

bool sortBySize(pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second ;
}



class UndirectedGraph {
    map<int, vector<int>> vertices;
    int totalNodes = 0;
public:
    int pivotC=0;
    vector<int>best_clique;
    //vector<int>maxDegv;
    UndirectedGraph();
    void addVertice(const int& A, const int& B);
    void find(const int& u);
    void clique(vector<int> R, vector<int> P, vector<int> X);
    int clique2(vector<int> R, vector<int> P, vector<int> X);
   // void compact();
    void findMaxDeg();
    int pivot(vector<int>&);
    int pivotModified(vector<int>&);
    vector<int>possiblePivots;

   // queue<int>possiblePivots;
};


UndirectedGraph::UndirectedGraph() = default;


void UndirectedGraph::addVertice(const int& A, const int& B) {
    vertices[A].push_back(B);
    vertices[B].push_back(A);
    totalNodes++;
}


void UndirectedGraph::clique(vector<int> R, vector<int> P, vector<int> X) {
    // Revisa si están vacíos, lo que implicaría que hay un clique
    if (P.empty() && X.empty()){
        //cout << "Clique found!" << endl;
        if(R.size()>best_clique.size()){
            best_clique = R;
            cout<<"R "<<R.size()<<"\n";
       //  for (const auto& it: R)
         //   cout << it << " " << endl;
        }
        return;
    }
    // Miguel recommended to copy P in order to avoid problems with iterator.
  //  vector<int> pCopy(P);
    for (const auto& v: P){
        vector<int> unionSet;
        vector<int> intersectionSetPNv;
        vector<int> intersectionSetXNv;
        vector<int> neighborsP;
        vector<int> vVector = {v};
        // neighbors of P
        for (const auto& neighbors: vertices[v]) neighborsP.push_back(neighbors);
        // R Union {v}
        set_union(R.begin(), R.end(), vVector.begin(), vVector.end(), back_inserter(unionSet));
        // Intersection between P and N(v)
        set_intersection(P.begin(), P.end(), neighborsP.begin(), neighborsP.end(), back_inserter(intersectionSetPNv));
        set_intersection(X.begin(), X.end(), neighborsP.begin(), neighborsP.end(), back_inserter(intersectionSetXNv));
        clique(unionSet, intersectionSetPNv, intersectionSetXNv);
        vector<int> PminusV;
        vector<int> XunionV;
        // Obtains P - {v} y X Union {v}
        set_difference(P.begin(), P.end(), vVector.begin(), vVector.end(), inserter(PminusV, PminusV.begin()));
        set_union(X.begin(), X.end(), vVector.begin(), vVector.end(), back_inserter(XunionV));

        P = vector<int> (PminusV);
        X = vector<int> (XunionV);
    }


}


int UndirectedGraph::clique2(vector<int>R,vector<int>P,vector<int>X){
//with pivoting
int a =0;
    if(P.empty()&&X.empty()){
        if(R.size()>best_clique.size()){
           best_clique.clear();
            best_clique =R;
            cout<<"R "<<R.size()<<"\n";
        }
        return R.size();
    }
    vector<int>unionSetPXv;
    vector<int>neighborsU;
    vector<int>PminusN;
    set_union(P.begin(),P.end(),X.begin(),X.end(),back_inserter(unionSetPXv));
    int p = pivotModified(unionSetPXv); //p is u "pivot"

    if(!p) return 0;
   /* if(p!=-1){
        cout<<"NONONO"<<endl;
    }else{
        cout<<"FInish"<<endl;
    }*/

  //  cout<<"Pivot : "<<p<<"\n";
    for(const auto& neighbors: vertices[p]) neighborsU.push_back(neighbors); //N(u)
    set_difference(P.begin(),P.end(),neighborsU.begin(),neighborsU.end(),back_inserter(PminusN)); //P / N(u)
    //vector<int>copyPminusN (PminusN);
    for(const auto& v: PminusN){
        vector<int>unionSet; //R u {v}
        vector<int>intersectionPNv; //P intersect Neighbors.
        vector<int>intersectionXNv;
        vector<int>neighborsP; // N(v)
        vector<int>vVector ={v}; //{v}
        vector<int>PminusV; //P\v
        vector<int>XunionV; //X U v

        set_union(R.begin(),R.end(),vVector.begin(),vVector.end(),back_inserter(unionSet));
        for(const auto& neigh : vertices[v]) neighborsP.push_back(neigh); //N(v)
        set_intersection(P.begin(), P.end(), neighborsP.begin(), neighborsP.end(), back_inserter(intersectionPNv));
        set_intersection(X.begin(), X.end(), neighborsP.begin(), neighborsP.end(), back_inserter(intersectionXNv));
        clique2(unionSet,intersectionPNv,intersectionXNv);
        set_difference(P.begin(),P.end(),vVector.begin(),vVector.end(),inserter(PminusV, PminusV.begin()));
        set_union(X.begin(),X.end(),vVector.begin(),vVector.end(),back_inserter(XunionV));

        P = vector<int>(PminusN);
        X = vector<int>(XunionV);
    }

   // cout<<"A "<< a<<endl;
}



/*void UndirectedGraph::compact() {
    cout << "Compact" << endl;
}

*/

void UndirectedGraph::findMaxDeg(){

    vector<pair<int,int>>temp;
    int n =0;
   for(map<int,vector<int>>::iterator it =vertices.begin(); it!=vertices.end();++it){
        temp.push_back(make_pair(it->first,it->second.size()));
        //cout<<"Fir :"<<it->first<<" Sec : "<<it->second.size()<<endl;
        n++;
  }
  sort(temp.begin(),temp.end(),sortBySize);

    for(int i=0; i<n ; i++){
      // possiblePivots.push(temp[i].first);
        possiblePivots.push_back(temp[i].first);
      //  cout<<temp[i].first<<endl;
    }
}

/*

int UndirectedGraph::pivot(vector<int>unionPXv){
    int aux, maxi;
    aux = maxi = 0;
        for(int i=0; i<possiblePivots.size();i++){
            aux = possiblePivots.front();
            possiblePivots.pop();
         for(const auto&it: unionPXv){
                if(it == aux)
                    return aux;
        }
        }

        return 0;
}
*/
/*
int UndirectedGraph::pivot(vector<int>&unionPXv){


        for(auto&it : possiblePivots){
            for(const auto&ite: unionPXv){
                if(ite == it){
                    //unionPXv.erase(unionPXv.begin()+ite);
                    possiblePivots.erase(possiblePivots.begin()+it);
                 //   cout<<"ITE "<<ite<<endl;
                    return ite;
                }
            }

        }
    //pivotC =0;
    int h = 0;
   // cout<<"Return "<<h<<endl;
   // if(!possiblePivots.empty()) possiblePivots.erase(possiblePivots.begin());
    //unionPXv.erase(unionPXv.begin());
    return h;
}
*/

int UndirectedGraph::pivotModified(vector<int>&unionPXv){
    int p,nMax;
    p = nMax = 0;

    for(const auto&it : unionPXv){
        if(vertices[it].size()>nMax){
          //  cout<<"found"<<endl;
            p = it;
            nMax = vertices[it].size();
            //cout<<"P "<<p<<" Size "<<nMax<<endl;
        }

    }

    if(p)
        return p;

    /*}else{
        if(!unionPXv.empty())
            p = unionPXv[0];
       // else p= pivotC++;
    //    unionPXv.erase(unionPXv.begin());
        return p;
    }*/
}


ifstream infile("same_input.txt");
ofstream outfile("cliques.txt");
int main(int argc , char *argv[])
{
 UndirectedGraph ug;
    int n,A,B,v;
    vector<int>P;
    //cin>>v;
    infile>>v;

    for(int i=0;i<v;i++)
        P.push_back(i);


    //cin>>n;
    infile>>n;
    while (n--){
        infile>>A>>B;
        if(A!=B)
            ug.addVertice(A,B);
    }


    cout<<"Read"<<endl;
    vector<int> R = {};
    vector<int> X = {};



  // ug.findMaxDeg();
    //sorting


    int u = ug.clique2(R, P , X);
    for(const auto&it: ug.best_clique)
        outfile<<it<<"\n";

    return 0;
}
