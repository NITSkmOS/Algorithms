#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXL 30

int parent[MAXN][MAXL]; // MAXL = log(N) + k
int level[MAXN];
vector<vector<int>> g;

void dfs(int u){

	for(auto &v: g[u]){
		if(level[v] == -1){
			level[v] = level[u] + 1;
			parent[v][0] = u;
			dfs(v);
		}
	}
}

void init(int root,int n){

	for(int i=0;i<n;i++){
		parent[i][0] = -1;
		level[i] = -1;
	}

	level[root] = 0;
	dfs(root);
	// set dp 
	for(int j=1;j<MAXL;j++){
		for(int i=0;i<n;i++){
			parent[i][j] = parent[parent[i][j-1]][j-1]; // meu avo eh pai do meu pai
		}
	}
}

int LCA(int u,int v){

	if(level[u] < level[v]) swap(u,v);

	for(int i=MAXL-1;i>=0;i--){
		if(level[u] - (1<<i) >= level[v]){
			u = parent[u][i];
		}
	}

	if(u == v) return u;

	for(int i=MAXL-1;i>=0;i--){
		if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}
