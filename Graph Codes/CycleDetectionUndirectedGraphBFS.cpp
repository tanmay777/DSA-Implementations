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
        Graph(vector<Edge> const &edges,int N){
            adjList=new vector<int>[N];
            for(int i=0;i<N;i++)    
            {
                adjList[edges[i].src].push_back(edges[i].dest);
                adjList[edges[i].dest].push_back(edges[i].src);
            }
        }
};

struct Node{
    int v,parent;
};

bool BFS(Graph const &graph,int src,int N){
    queue<Node> q;
    q.push({src,-1});

    vector<bool> discovered(N);

    while(!q.empty()){
        Node node=q.front();
        q.pop();
        for(int u:graph.adjList[node.v]){
            if(!discovered[u])
            {
                q.push({u,node.v});
                discovered[u]=true;
            }
            else if(u!=node.parent){
                //As this is an undirected graph, there will be one arrow towards the parent also. Therefore, we have
                //verify that the discovered node isn't the parent itself.
                return true;
            }
        }
    }
    return false;
}



int main()
{
    vector<Edge> edges =
    {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
        // edge (6->10) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

    if(BFS(graph,1,N))
        cout<<"Graph contains Cycle";
    else
        cout<<"Graph doesn't contains Cycle";

    cout<<endl;
    return 0;
} 


