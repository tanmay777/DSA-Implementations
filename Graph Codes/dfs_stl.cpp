/**
 * Author: Tanmay Jha
 * Date: 28/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Edge{
    int src;
    int dest;
};

class Graph{
    public:
        vector<int> *adjList;

        Graph(vector<Edge> const &edges,int N){
            adjList=new vector<int>[N];

            for(int i=0;i<edges.size();i++)
            {
                int src=edges[i].src;
                int dest=edges[i].dest;

                adjList[src].push_back(dest);
                adjList[dest].push_back(src);
            }
        }

        ~Graph(){
            delete[] adjList;
        }
};

void iterativeDFS(Graph const &graph,int v,vector<bool> &discovered){
    stack<int> stack;
    stack.push(v);
    while(!stack.empty()){
        v=stack.top();
        stack.pop();

        discovered[v]=true;
        cout<<v<<" ";
        for(auto it=graph.adjList[v].rbegin();it!=graph.adjList[v].rend();++it){
            int u=*it;
            if(!discovered[u])
                stack.push(u);
        }
    }
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        // Notice that node 0 is unconnected node
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };

    // Number of nodes in the graph (0-12)
    int N = 13;

    Graph(edges,N);

    vector<bool> discovered(N);


    for(int i=0;i<N;i++)
        if(discovered[i]==false)
            iterativeDFS(graph,i,discovered);
    
    cout<<endl;
    return 0;
} 


