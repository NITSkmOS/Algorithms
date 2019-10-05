#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7 + 7;
#define source 18
#define sink 19
typedef struct{

	int v;
	int flow;
	int cap;

}Edge;

vector<vector<Edge>> g;
vector<vector<Edge>> aux;
int level[50];


void residual(){

	int n = g.size();	
	aux.clear();
	aux.resize(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<g[i].size();j++){
			Edge atual = g[i][j];
			int v;
			if(atual.flow < atual.cap){
				aux[i].push_back(atual);
			}
			
			if(atual.flow > 0){
				v = atual.v;
				atual.v = i;
				atual.cap = atual.flow;
				atual.flow = 0;
				aux[v].push_back(atual);
			}	
		}
	}


	// passando para g;

	g.clear();
	g.resize(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<aux[i].size();j++){
			g[i].push_back(aux[i][j]);
		}
	}
	aux.clear();
}

bool BFS(){

	int n = g.size();

	for(int i=0;i<n;i++){
		level[i] = -1;
	}
	queue<int> q;
	level[source] = 0;
	q.push(source);

	while(!q.empty()){
			
		int u = q.front();
		q.pop();
		//cout << u << endl;
		if(u == sink) return true;

		for(int i=0;i<g[u].size();i++){
			int v = g[u][i].v;

			if(level[v] == -1){
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}

	return false;
}

int maxflow(int u,int flow){

	int ret = 0;
	int f;
	if(u == sink) return flow;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i].v;
		int resto = g[u][i].cap - g[u][i].flow;
		if(level[v] == level[u] + 1){
			f = maxflow(v,min(flow,resto));
			ret += f;
			flow -= f;
			g[u][i].flow += f;
		}
	}

	return ret;
}

int dinic(){

	int flow = 0;

	residual();
	while(BFS()){
		flow += maxflow(source,INF);
		residual();
	}		

	return flow;
}

int main(){

	int n;
	cin >> n;
	g.clear();
	g.resize(30);
	for(int i=0;i<n;i++){
		char u, v;
		int cap;
		cin >> u >> v >> cap;
		Edge atual;
		atual.v = v - 'A';
		atual.flow = 0;
		atual.cap = cap;

		g[u-'A'].push_back(atual);
	}

	cout << dinic() << endl;	
}
