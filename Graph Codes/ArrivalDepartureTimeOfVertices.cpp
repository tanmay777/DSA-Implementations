/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int src,dest;
};

class Graph{
    public:
        vector<int> *adjList;
        
        Graph(vector<Edge> edges,int N){
       
            adjList=new vector<int>[N];
            
            for(int i=0;i<edges.size();i++)
            {
                adjList[edges[i].src].push_back(edges[i].dest);
            }
        }
        
        ~Graph(){
            delete[] adjList;
        }
};

void DFS(Graph const &graph,vector<bool> &discovered,vector<int> &arrival,vector<int> &departure,int i,int &time){
    arrival[i]=++time;
    discovered[i]=true;
    for(int u:graph.adjList[i])
        if(!discovered[u])
            DFS(graph,discovered,arrival,departure,u,time);
    departure[i]=++time;
}


int main()
{
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
        {4, 5}, {6, 7}
    };

    // Number of nodes in the graph
    int N = 8;

    Graph graph(edges,N);
    vector<int> arrival(N);
    vector<int> departure(N);
    vector<bool> discovered(N);

    int time=-1;
    for(int i=0;i<N;i++)
        if(!discovered[i])
            DFS(graph,discovered,arrival,departure,i,time);

    for(int j=0;j<N;j++)
        cout<<"Vertex: "<<j<<" ("<<arrival[j]<<","<<departure[j]<<")"<<endl;
    
    cout<<endl;
    return 0;
} 


