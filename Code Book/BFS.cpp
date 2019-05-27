#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define INF 0x3f3f3f3f
#define UNVISITED 0
#define VISITED 1
#define NAME(x) cerr << #x << " = "<< x <<endl;

using namespace std;

vvi adj;
vi vis, dist;
int m, u, v, s, ans;

void bfs(int s){
    queue<int> fila;
    vis = vi(m+1,UNVISITED);
    dist = vi(m+1,INF);
    fila.push(s), vis[s] = 1, dist[s] = 0;
    while (!fila.empty()){
        int u = fila.front(); fila.pop();
        for (int v : adj[u])
            if (vis[v]==UNVISITED){
                fila.push(v);
                vis[v]=VISITED;
                dist[v]=dist[u]+1;
                ans = dist[v];
            }
    }
    cout<<++ans<<endl;
}

int main(){_
    cin>>m>>s;
    adj = vvi(m+1);
    for(int i=0; i<m-1; i++){
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    bfs(s);
    return 0;
}
