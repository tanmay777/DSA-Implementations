/**
 * Author: Tanmay Jha
 * Date: 29/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;
#define N 100

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// class to represent a graph object
class Graph 
{
public:
    // An array of vectors to represent adjacency list
    vector<int> adjList[N + 1];

    // Constructor
    Graph(vector<Edge> const &edges)
    {
        // add edges to the graph
        for (int i = 0; i < edges.size(); i++) 
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // Please note that directed is directed
            adjList[src].push_back(dest);
        }
    }
};

struct Node{
    int ver;
    int minDist;
};

void BFS(Graph const &graph,int source){
    queue<Node> q;
    vector<bool> discovered(N+1);//This is because we will start our bfs from 1 instead of 0.
    discovered[source]=true;
    Node node={source,0};
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(node.ver==N)
        {
            cout<<node.minDist<<" ";
            break;
        }
        for(int u:graph.adjList[node.ver])
        {
            if(!discovered[u]){
                discovered[u]=true;
                Node n={u,node.minDist+1};
                q.push(n);
            }
        }
    }
}


void findSolution(unordered_map<int,int> &ladder,unordered_map<int,int> &snake){
    vector<Edge> edges;
    for(int i=0;i<N;i++){
        for(int j=1;j<=6&&i+j<=N;j++)
        {
            int dest=((ladder.find(i+j)!=ladder.end())?ladder[i+j]:0+((snake.find(i+j)!=snake.end())?snake[i+j]:0));
            if(dest==0)
                dest=i+j;
            edges.push_back({i,dest});
        }
    }
    Graph gr(edges);
    BFS(gr,1);
}

int main()
{
    // snakes and ladders are represented using a map
    unordered_map<int, int> ladder, snake;

    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;
    
    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;

    findSolution(ladder, snake);

    return 0;
} 


