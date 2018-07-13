/**
 * Author: Tanmay Jha
 * Date: 28/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int src, dest;
};
class Graph{
    public:
        vector<int> *adjList;

        Graph(vector<Edge> const &edges,int N){
            adjList=new vector<int>[N];
            for(unsigned i=0;i<edges.size();i++){
                int src=edges[i].src;
                int dest=edges[i].dest;
                adjList[src].push_back(dest);
                //adjList[dest].push_back(src) for undirected graph
            }
        }
        ~Graph(){
            delete[] adjList;
        }
};

void printGraph(Graph const &graph,int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<i<<"->";
        for(int v:graph.adjList[i])
            cout<<v<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<Edge> edges={{0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}};
    int N=6;
    Graph graph(edges,N);
    printGraph(graph,N);
    cout<<endl;
    return 0;
} 


