/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int src;
    int dest;
};

class Graph{
    public:
    vector<int> *adjList;
    Graph(vector<Edge> const &edge,int N){
        adjList=new vector<int>[N];
        for(int i=0;i<edge.size();i++)
        {
            adjList[edge[i].src].push_back(edge[i].dest);
        }
    }
    ~Graph(){
        delete[] adjList;
    }    
};

void DFS(Graph const &graph,int u,vector<bool> &visited){
    visited[u]=true;
    for(int v:graph.adjList[u]){
        if(!visited[v])
            DFS(graph,v,visited);
    }
}

bool check(Graph const &graph,int N){
    vector<bool> visited(N);
    DFS(graph,0,visited);
    if(find(visited.begin(),visited.end(),false)!=visited.end())
        return false;
    vector<Edge> edges;
    for(int i=0;i<N;i++)
    {
        for(int u:graph.adjList[i])
            edges.push_back({u,i});
    }
    Graph gr(edges,N);
    fill(visited.begin(),visited.end(),false);
    DFS(gr,0,visited);
    if(find(visited.begin(),visited.end(),false)!=visited.end())
        return false;
    return true;
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };

    // Number of nodes in the graph
    int N = 5;

    // create a graph from given edges
    Graph graph(edges, N);

    // check if graph is not strongly connected or not
    if (check(graph, N))
        cout << "Graph is Strongly Connected";
    else
        cout << "Graph is not Strongly Connected";

    cout<<endl;
    return 0;
} 


