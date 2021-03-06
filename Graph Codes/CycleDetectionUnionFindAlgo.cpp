/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // An array of vectors to represent adjacency list
    vector<int> *adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<int>[N];

        // add edges to the directed graph
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
        }
    }
    
    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;
public:
    // perform MakeSet operation
    void makeSet(int N)
    {
        // create N disjoint sets (one for each vertex)
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }

    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if (parent[k] == k)
            return k;

        // recurse for parent until we find root
        return Find(parent[k]);
    }

    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

// Returns true if graph has cycle
bool findCycle(Graph const &graph,int N){
    DisjointSet disjointSet;
    disjointSet.makeSet(N);
    for(int i=0;i<N;i++)
    {
        for(int u:graph.adjList[i])
        {
            int x=disjointSet.Find(i);
            int y=disjointSet.Find(u);
            
            if(x==y)
                return true;
            else
                disjointSet.Union(i,u);
            
        }
    }
    return false;
}



// Union-Find Algorithm for Cycle Detection in graph
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
        // edge (11->12) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 13;

    // create a graph from edges
    Graph graph(edges, N);

    if (findCycle(graph, N))
        cout << "Cycle Found";
    else
        cout << "No Cycle Found";

    return 0;
}
 


