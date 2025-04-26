#include <iostream>
using namespace std;

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int inDegree[MAX_NODES];
int queue[MAX_NODES];
int result[MAX_NODES];

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    inDegree[dest]++;
}

void topologicalSort(int vertices) {
    int front = 0, rear = 0, index = 0;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    while (front < rear) {
        int current = queue[front++];
        result[index++] = current;
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    if (index != vertices) {
        cout << "The graph contains a cycle, so topological sorting is not possible.\n";
        return;
    }
    cout << "Topological Sort Order: ";
    for (int i = 0; i < index; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    cout<<"Enter number of vertices and edges:";
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        inDegree[i] = 0;
    }
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        addEdge(src, dest);
    }
    topologicalSort(vertices);
    return 0;
}

