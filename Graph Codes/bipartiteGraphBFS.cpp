/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge{
    int src,dest;
};

class Graph{
    public:
        vector<int> *adjList;

        Graph(vector<Edge> const &edges,int N)
        {
            adjList=new vector<int>[N]; //Check
            for(int i=0;i<edges.size();i++)
            {
                adjList[edges[i].src]=adjList[edges[i].dest];
                adjList[edges[i].dest]=adjList[edges[i].src];
            }
        }

        ~Graph()
        {
            delete[] adjList; 
        }
};

bool BFS(Graph const &graph,int src,int N){
    vector<int> level(N);
    queue<int> q; 
    vector<bool> discovered(N);
    q.push(src);
    level[src]=0;
    discovered[src]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i:graph.adjList[v]){
            if(!discovered[i])
            {
                q.push(i);
                discovered[i]=true;
                level[i]=level[v]+1;
            }
            else if(level[i]==level[v])
                return false;
        }
    }
    return true;
}


int main()
{
     // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
        {5, 9}, {8, 9}
        // if we add 2->4 edge, graph is becomes non-Bipartite
    };
    int N=10;
    Graph graph(edges,N);
    if(BFS(graph,1,N))
        cout<<"Bipartite";
    else
        cout<<"Not Bipartite";
    cout<<endl;
    return 0;
} 


