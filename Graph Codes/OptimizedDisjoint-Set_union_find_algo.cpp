/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
    public:
    void makeSet(vector<int> const &universe){
        for(int i:universe)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int Find(int k){
        if(parent[k]!=k)
            parent[k]=Find(parent[k]);
        return parent[k];
    }

    //See, more the rank means more the height of the tree.
    //Remember, that parent of (larger tree) root node become parent of (smaller tree) root node.
    //When two unequal tree combine, then the ranks doesn't changes because smaller one gets parallel to the larger one.
    //Thereby getting is height hidden in the presence of height of bigger tree. 
    /*
       Set1:     a
                /
               b
              /
             c 

       Set2: d
              \
               e

       On union
                 a
                / \
               b   d
              /     \
             c       e 
             
       See, this is because rank doesn't changes.
*/

    void Union(int x,int y)
    {
        int a=Find(x);
        int b=Find(y);
        if(a==b)
            return;
        if(rank[a]>rank[b])
            parent[b]=a;
        else if(rank[a]<rank[b])
            parent[a]=b;
        else{
            parent[a]=parent[b];
            rank[b]++;
        }
    }
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i : universe)
        cout << ds.Find(i) << ' ';

    cout << '\n';
}

// Disjoint-Set Data Structure (Union Find Algorithm)
int main()
{
    int arr[]={1,2,3,4,5};
    // universe of items
    vector<int> universe(arr,arr+5);

    // initialize DisjointSet class
    DisjointSet ds;

    // create singleton set for each element of universe
    ds.makeSet(universe);
    printSets(universe, ds);

    ds.Union(4, 3); // 4 and 3 are in same set
    printSets(universe, ds);

    ds.Union(2, 1); // 1 and 2 are in same set
    printSets(universe, ds);

    ds.Union(1, 3); // 1, 2, 3, 4 are in same set
    printSets(universe, ds);

    return 0;
}

