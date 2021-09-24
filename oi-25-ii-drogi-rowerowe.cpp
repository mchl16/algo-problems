//Michal Ochenduszkiewicz
//https://szkopul.edu.pl/problemset/problem/aKKSmtjWTtDOEHDqnmQ3-eAA/site/?key=statement
//23.01.2020

#include <bits/stdc++.h>
using namespace std;
int V,E,a,b;
vector<int> v[50000],v2[50000];
set<int> v3[50000];
bitset<50000> vis,vis2,vis3;
int t[50000],d[50000],father[50001];
vector<int> w;
vector<vector<int>> ssc;
void dfs(int a){
	vis[a]=1;
	for(int i=0;i<v[a].size();++i) if(!vis[v[a][i]]) dfs(v[a][i]);
	w.push_back(a);
}
void dfs2(int a){
	vis2[a]=1;
	for (int i=0;i<v2[a].size();++i){
		if(!vis2[v2[a][i]]){
			ssc.back().push_back(v2[a][i]);
			dfs2(v2[a][i]);
		}
	}
}
void dfs3(int a){
	vis3[a]=1;
	for(auto i:v3[a]){
		if(!vis3[i]){
			father[i]=a;
			dfs3(i);
		}
		else d[a]+=d[i];
	}
	if(father[a]!=a) d[father[a]]+=d[a];
}
int main(){
	cin >> V >> E;
	for (int i=0;i<E;++i){
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v2[b-1].push_back(a-1);
	}
	for (int i=0;i<V;++i) if(!vis[i]) dfs(i);
	while(!w.empty()){
		if(!vis2[w.back()]){
			ssc.push_back({w.back()});
			dfs2(w.back());
		}
		w.pop_back();
	}
	for (int i=0;i<ssc.size();++i) for (int j=0;j<ssc[i].size();++j) t[ssc[i][j]]=i;
	for (int i=0;i<V;++i) for (int j=0;j<v[i].size();++j) if(t[i]!=t[v[i][j]]) v3[t[i]].insert(t[v[i][j]]);
	for (int i=0;i<V;++i){
		d[t[i]]=ssc[t[i]].size();
		father[i]=i;
	}
	for (int i=0;i<ssc.size();++i) if(!vis3[i]) dfs3(i);
	for (int i=0;i<V;++i) cout << d[t[i]]-1 << "\n";
}
