#include <iostream>
#define MAX 100
using namespace std;
int adj[MAX][MAX];
int pi[MAX];
int f[MAX];
int d[MAX];
int color[MAX];
int timecounter;
int n;
void dfsvisit(int u)
{
    color[u]=1;
    d[u]=++timecounter;
    for(int v=0;v<n;v++){
        if(adj[u][v]==1 && color[v]==0)
        {
            pi[v]=u;
            dfsvisit(v);
        }
    }
    color[u]=-1;
    f[u]=++timecounter;
}
void dfs()
{
    for(int i=0;i<n;i++){
        color[i] = 0;
        pi[i] = -1;
        d[i] = f[i] = 0;
    }
    timecounter = 0;
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
            dfsvisit(i);
    }
}
int connectedcomponents()
{
    for(int i=0;i<n;i++)
        color[i]=0;
        
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            count++;
            dfsvisit(i);
        }
    }
    return count;
}

int main() {
    // Write C++ code here
    int e,u,v;
    cout<< "Enter the number of vertices and edges:" << endl;
    cin >> n >> e;
    
    cout<<"Enter the vertives (u,v)\n";
    for(int i=0;i<e;i++)
    {
        cin>> u >> v;
        adj[u][v]=1;
    }
    
    cout<<"Adjacency materix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<< " ";
        }
        cout << endl;
    }
    
    dfs();
    cout<<"\nSTARTING AND FINISHING TIME OF EACH VERTEX\n";
    for(int i=0;i<n;i++)
        cout << "Vertex " << i << "started at " << d[i] << "and finished at " << f[i] << endl;
        
    int numb = connectedcomponents();
    cout << "No of connected components:" << numb << endl;

    return 0;
}