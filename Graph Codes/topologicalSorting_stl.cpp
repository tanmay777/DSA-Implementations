/**
 * Author: Tanmay Jha
 * Date: 03/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

struct Edge{
    int src,dest;
};

class Graph{
    public:
        vector<int> *adjList;
        Graph(vector<Edge> edge,int N){
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

int inDegVal(int v,Graph &g,int N){
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int u:g.adjList[i]){
            if(u==v)
                count++;
        }
    }
    return count;
}


void topological_sort(Graph &g,int N){
    vector<int> inDeg(N,-1);
    queue<int> q;
    int i=0;
    for(i=0;i<N;i++){
            inDeg[i]=inDegVal(i,g,N);
            //cout<<inDeg[i];
            if(inDeg[i]==0){
                q.push(i);
            }
    }
    while(!q.empty()){
        int v=q.front();
        cout<<v;
        q.pop();
        g.adjList[v].clear();
        for(i=0;i<N;i++)
            inDeg[i]=inDegVal(i,g,N);
            if(inDeg[i]==0){
                q.push(i);
            }
        if(q.size()==N){
            return;
        }
    }
}
 
int main()
{
    vector<Edge> edge={{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
        {5, 1}, {7, 0}, {7, 1}};
    Graph g(edge,8);    
    int N=8;
    topological_sort(g,N);
    cout<<endl;
    return 0;
} 


