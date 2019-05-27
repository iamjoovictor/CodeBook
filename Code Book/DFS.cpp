#include<bits/stdc++.h>
#define N 200023
#define vi vector<int>
#define _ ios_base::sync_with_stdio(0);
#define pb push_back

using namespace std;

int n, ini;
int vis[N];
vi adj[N];

int dfs(int u){
	vis[u] = 1;
	int dist=0; //Máxima distância
	for(int v : adj[u]){
		if(!vis[v])
			dist=max(dfs(v) + 1, dis);
	}
	return dis;
}

int main(){_
	int u, v;
	cin >> n >> ini;
	for(int i = 1; i < n; ++i){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int ans = dfs(ini) + 1; //o é o ponto inicial da DFS
	cout << ans << endl;
	return 0;
}
