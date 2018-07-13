/**
 * Author: Tanmay Jha
 * Date: 28/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int src,dest, weight;
};

class Graph{
    public:
        vector<pair<int,int>> *adjList;

        Graph(vector<Edge> const &edges,int N){
            adjList=new vector<pair<int,int>>[N];

            for(unsigned i=0;i<edges.size();i++)
            {
                int src=edges[i].src;
                int dest=edges[i].dest;
                int weight=edges[i].weight;

                adjList[src].push_back(make_pair(dest,weight));
                //adjList[dest].push_back(make_pair(src,weight) for undirected graph
            }
        }

        ~Graph(){
            delete[] adjList;
        }
};

void printGraph(Graph const &graph,int N){
    for(int i=0;i<N;i++)
    {
        for(pair<int,int> v:graph.adjList[i]){
            cout<<"("<<i<<","<<v.first<<","<<v.second<<")";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<endl;
    vector<Edge> edges =
    {
        // (x, y, w) -> edge from x to y having weight w
        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
    };
    
    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    return 0;
} 


