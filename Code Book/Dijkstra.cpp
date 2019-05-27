#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define oo 10003213
#define NAME(x) cout<<#x<<" = "<<x<<endl;
#define MAXN 1123

using namespace std;

int n,m;
vii adj[MAXN];
int dist[MAXN];

int sssp(int src, int dest){
	priority_queue<int,vii,greater<ii> > pq;
	pq.push(ii(0,src));
	vi dist(n+1,oo);
	dist[src]=0;
	while(pq.size()){
		ii cur = pq.top();pq.pop();
		int d=cur.first;
		int u=cur.second;
		if(dist[u]<d) continue;
		if(u==dest) return dist[u];
		for(ii vw : adj[u]){
			int v=vw.first;int w=vw.second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				pq.push(ii(dist[v],v));
			}
		}
	}
	return oo;
}

int main(){_
	int u,v,p,s,maior=-oo,menor=oo;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>u>>v>>p;
		adj[u].push_back(make_pair(v,p));
		adj[v].push_back(make_pair(u,p));

	}
	cin>>s;
	for(int i=1;i<=n;++i){
		dist[i]=sssp(i,s);
	}
	for(int i=1;i<=n;++i){
        if(dist[i]<menor && i!=s) menor=dist[i];
        if(dist[i]>maior && i!=s) maior=dist[i];
	}
    cout<<maior-menor<<endl;

	return 0;
}
