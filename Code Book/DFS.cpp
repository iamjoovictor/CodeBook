#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1123
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

vi adj[MAXN];
int seen[MAXN];

void DFS(int u){
    seen[u]=1;
    for(int v : adj[u]){
        if(!seen[v]) dfs(v);
    }
}

int main(){_
    //Códigos;
    
    return 0;
}
