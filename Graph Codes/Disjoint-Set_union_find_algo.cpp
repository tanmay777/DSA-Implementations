/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

class DisjointSet{
    unordered_map<int,int> parent;

    public:
        void makeSet(vector<int> const &universe){
            for(int i:universe)
                parent[i]=i;
        }

        int Find(int k)
        {
            if(parent[k]==k)
                return k;
            else
                return Find(parent[k]);
        }

        void Union(int a,int b){
            parent[Find(a)]=Find(b);
        }
};

void printSets(vector<int> const &universe,DisjointSet &ds){
    for(int i:universe)
        cout<<ds.Find(i)<<" ";

    cout<<endl;
}

int main()
{
    int arr[]={1,2,3,4,5};
    vector<int> universe(arr,arr+sizeof(arr)/sizeof(arr[0]));

    DisjointSet ds;
    ds.makeSet(universe);
    printSets(universe,ds);

    ds.Union(4,3);
    printSets(universe,ds);

    ds.Union(2,1);
    printSets(universe,ds);

    ds.Union(1,3);
    printSets(universe,ds);

    cout<<endl;
    return 0;
} 


