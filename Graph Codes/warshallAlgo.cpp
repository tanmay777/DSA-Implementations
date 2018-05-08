#include<iostream>
#include<vector>

using namespace std;

void allPairShortestPath(int graph[4][4],int distance[4][4],int path[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            distance[i][j]=graph[i][j];
            if(graph[i][j]!=INT_MAX && i!=j)
                path[i][j]=i;
            else{
                path[i][j]=-1;
            }
        }
    }

    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(distance[i][k]==INT_MAX || distance[k][j] == INT_MAX)
                    continue;
                if(distance[i][j]>(distance[i][k]+distance[k][j])){
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=path[k][j];
            }
        }
    }
}
}

void printMinDistMatrix(int distance[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<distance[i][j]<<" ";
        cout<<endl;
    }
}

void printPathMatrix(int path[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
}

void printPath(int path[][4],int start,int end){
    vector<int> stack;
    int i=0;
    stack.push_back(end);
    while(1){
        end=path[start][end];
        if(end==-1)
            break;
        stack.push_back(end);
        if(end==start)
            break;
    }
    for(i=stack.size()-1;i>=0;i--){
        cout<<stack[i];
        if(i!=0)
            cout<<"->";
    }
    cout<<endl;
}

int main(){
    int graph[][4]={0,3,6,15,INT_MAX,0,-2,INT_MAX,INT_MAX,INT_MAX,0,2,1,INT_MAX,INT_MAX,0},distance[4][4]={0},path[4][4]={0},start,end;
    allPairShortestPath(graph,distance,path);
    cout<<"Minimum Distance Matrix is\n";
    printMinDistMatrix(distance);
    cout<<"Minimum Path Matrix is\n";
    printPathMatrix(path);
    cout<<"Enter the starting and ending vertices\n";
    cin>>start>>end;
    printPath(path,start,end);
    return 0;
}
