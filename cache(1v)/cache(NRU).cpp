#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


struct block{
    int data ; //this will be the whole data. .
    bool NRU ; //1-> initialize. 0 -> hit/filled  [choose the first one with NRU =1 to write data] // if all sets are 0, put them all equal to 1
};

class Cset{
    public:
        int s_size;
        int tag;
        vector <block> ways; //array of blocks.

        Cset(int s,int t){
            struct block a;
            a.data = -1; //default value
            a.NRU = 1;
            tag = t;
            s_size = s;
            //ways(s,a); //initialize sets
            fill_n(back_inserter(ways),s, a);
        }

        void adding(int d){ //adding a new element
            bool there = false; //for hit
            bool here = false; //for miss
            //check if the data already exists, if so it is a hit
            for (auto& item : ways){

                if(item.data == d){
                    cout<<d<<" hit"<<endl;
                    item.NRU = 0; //just making sure
                    there = true;
                    break;
                }
            }

            //otherwise, write it (it is a miss)
            if(!there){
                //check first available (the one with NRU = 1)
                for (auto& item : ways){
                    if(item.NRU == 1){ //first element
                        cout<<d<<" miss"<<endl;
                        item.data = d;
                        item.NRU = 0; //just making sure
                        here = true;
                        break;
                    }
                }
                //if there is no available -> put all of them (NRU =1) and rewrite first element/block
                if(!here){
                    for (auto& item : ways){
                        item.NRU = 1;
                    }

                    cout<<"miss  + writing"<<endl;
                    ways[0].data = d;
                    ways[0].NRU = 0;
                }
            }
        }

        void printing(){
            for (auto& item : ways){
                cout<<item.data<<" NRU: "<<item.NRU<<endl;
            }
        }

};

class Cache{
public:
    int n_sets;
    vector<Cset> sets;

    Cache(int n_sets,int n_ways,int tag=-1){  //tag:-1 -> it's available to be written.
        Cset first(n_ways,tag);
        n_sets = n_sets;
        fill_n(back_inserter(sets),n_sets,first); //initialize the cache structure.
    }

    void inserting(int tag, int data){
        bool t_there = false;
        //check whether the tag exists in cache.
        //if so, write data
        for (auto& item : sets){
            if(item.tag == tag){
                t_there = true;
                item.adding(data);
                cout<<"tag found"<<endl;
                break;
            }
        }
       //otherwise, find a set with default tag and write it.
        if(!t_there){
            for (auto& item : sets){
                if(item.tag == -1){
                    item.adding(data);
                    cout<<"tag created"<<endl;
                    item.tag = tag;
                    break;
                }
            }
        }
    }

    void printing_set(){
        for (auto& item : sets){
                cout<<item.tag<<"-- tag"<<endl;
                item.printing();
        }
    }
};

int getTag(int n_bits, int data,int position){
    //cout<<"    s "<<(1<<n_bits)<<endl;
    //cout<<"    sa "<<(data>>(position))<<endl;
    return (((1<<n_bits)-1) & (data>>(position-1)));//((1<<left bound) & (value >>(right bound-1))

}

int main()
{
    /* first testing... works
    int tg = 001;
    Cset set1(5,tg);

    set1.adding(00100);
    set1.adding(00101);
    set1.adding(00110);

    set1.printing();
    set1.adding(00100);

    set1.adding(00111);
    set1.adding(01110);
    set1.adding(10101);

    set1.printing();

    cout << "Hello world!" << endl;
    */
        //configuration
    int address_bits = 8;
    int block_size = 4;
    int cache_sets = 4; //#sets
    int associativity = 2; //n-ways

    //calculating offset
    int offset = log2(block_size); //those are the bits we cannot select as tag.
    cout<<"offseet is: "<<offset<<endl;
    //calculating number of LSB bits need
    int n_lsb = log2(cache_sets);
    cout<<"#LSB bits: "<<offset<<endl;
    //get left bound for getting tag:
    int lb = offset + n_lsb;
        //data
    int dat[7] = {0b00000000,0b00010000,0b00100000,0b00000000,0b00101100,0b00000000,0b00101100};
    /*
    cout<<"tag "<<getTag(n_lsb,dat[0],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[1],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[2],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[3],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[4],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[5],(offset+1))<<endl;
    cout<<"tag "<<getTag(n_lsb,dat[6],(offset+1))<<endl;

    cout<<"data "<<dat[4]<<endl;
    */
    Cache cach(cache_sets,associativity);

    cach.inserting(getTag(n_lsb,dat[0],(offset+1)),dat[0]);
   // cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[1],(offset+1)),dat[1]);
   // cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[2],(offset+1)),dat[2]);
   // cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[3],(offset+1)),dat[3]);
   // cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[4],(offset+1)),dat[4]);
    //cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[5],(offset+1)),dat[5]);
   // cach.printing_set();
    cach.inserting(getTag(n_lsb,dat[6],(offset+1)),dat[6]);
    cach.printing_set();



    return 0;
}
