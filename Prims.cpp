#include<iostream>
using namespace std;
#define V 5

void prims(int graph[V][V])
{
    int selected[V];
    for(int i=0;i<V;i++)
    {
        selected[i]=0;
    }
    selected[0]=1;

    int edgeCount=0;
    cout<<"Edges in the minimum spanning Tree:\n";
    while(edgeCount<V-1)
    {
        int min=9999;
        int x=0,y=0;
        for(int i=0;i<V;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<V;j++)
                {
                    if(!selected[j] && graph[i][j])
                    {
                        if(min>graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" "<<y<<":"<<graph[x][y]<<endl;
        selected[y]=1;
        edgeCount++;
    }
}
 int main()
 {
     int graph[V][V]={
     {0,2,0,6,0},
     {2,0,3,8,5},
     {0,3,0,0,7},
     {6,8,0,0,9},
     {0,5,7,9,0},

     };
     prims(graph);
     return 0;
}
