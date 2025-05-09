#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];  
int visited[MAX];
int queue[MAX];
int front=0,rear=0;

void enqueue(int node) {
    queue[rear++]=node;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front==rear;
}

void bfs(int start,int nodes) {
    for (int i=0;i<nodes;i++)
        visited[i]=0;

    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
        int current = dequeue();
        cout<<"Visited: "<<current<<endl;

        for (int i = 0; i < nodes; i++) {
            if (adj[current][i]==1 && visited[i]==0) {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; 
    }

    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    cout<<"\nBFS Traversal:\n";
    bfs(start, nodes);

    return 0;
}
