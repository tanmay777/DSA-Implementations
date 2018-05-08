#include<iostream>
#include<vector>

using namespace std;

struct Map{
    int dist;
    int parent;
};

struct Edge{
    int src,dest,weight;
};

struct Graph{
    int V,E;
    Edge *edge;
};

Graph* createGraph(int V,int E){
    Graph *graph=new Graph; //We are dynamically creating a graph
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}

void print_map(Map *map,int V){
    cout<<"Vertex "<<"Dist "<<"Parent\n";
    for(int i=0;i<V;i++)
    {
        cout<<"   "<<i<<"     "<<map[i].dist<<"   "<<map[i].parent<<endl;
    }
}

//The following code finds shortest path from origin as well as detects negative cycle in graph
void BellmanFord(Graph *graph,int src,Map *map){
    
    int V=graph->V;
    int E=graph->E;
    int u,v,weight;
    
    //Initializing from src to all other nodes as infinite
    for(int i=0;i<V;i++){
        map[i].dist=INT_MAX;
        map[i].parent=-1;
    }
    
    map[src].parent=0;
    map[src].dist=0;

    //Relaxing all the edges V-1 times
    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            u=graph->edge[j].src;
            v=graph->edge[j].dest;
            weight=graph->edge[j].weight;
            if(map[v].dist>(map[u].dist+weight)&&map[u].dist!=INT_MAX){
                map[v].dist=(map[u].dist+weight);
                map[v].parent=u;
            }
        }
    }
    
    //To check for negative cycles
    for(int i=0;i<E;i++){
        u=graph->edge[i].src;
        v=graph->edge[i].dest;
        weight=graph->edge[i].weight;
        if(map[v].dist>(map[u].dist+weight)&&map[u].dist!=INT_MAX){
            cout<<"Graph contains negative weight Cycles";
        }
    }

    print_map(map,V);
}

void find_path(int src,int dest, Map *map){
    vector<int> stack;
    stack.push_back(dest);
    while(1)
    {
        dest=map[dest].parent;
        stack.push_back(dest);
        if(dest==0)
            break;
     }
     for(int i=stack.size()-1;i>=0;i--){
         cout<<stack[i];
         if(i!=0)
             cout<<"->";
     }
     cout<<endl;
}



int main(){

    int V=5;
    int E=8;
    int src,dest; 
    Map *map=new Map[V];

    Graph* graph=createGraph(V,E);

    // add edge 0-1 (or A-B )
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C )
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C )
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D )
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or A-E )
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C )
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B )
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D )
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    BellmanFord(graph, 0,map);

    cout<<"Enter the node to which path has to be found\n";
    cin>>dest;
    src=0;
    find_path(src,dest,map);
    return 0;
}
