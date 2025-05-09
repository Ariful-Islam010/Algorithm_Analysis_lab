#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int node,int nodes) {
    visited[node]=1;
    cout<< "Visited: "<<node<<endl;

    for (int i=0;i<nodes;i++) {
        if (adj[node][i]==1 && visited[i]==0) {
            dfs(i,nodes);
        }
    }
}

int main() {
    int nodes, edges;
    cout<<"Enter number of nodes: ";
    cin>>nodes;

    cout<<"Enter number of edges: ";
    cin>>edges;

    for (int i=0;i<edges;i++) {
        int u,v;
        cout<< "Enter edge (u v): ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; 
    }
    for (int i=0;i<nodes;i++) {
        visited[i]=0;
    }

    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    cout<< "\nDFS Traversal:\n";
    dfs(start,nodes);

    return 0;
}
