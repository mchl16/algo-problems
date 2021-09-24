//Michal Ochenduszkiewicz
//https://szkopul.edu.pl/problemset/problem/Ak4wWPkNtHpF-OiulN1gixfW/site/?key=statement
//6.02.2021

#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,q;
int t[1000000],u[1000000];
vector<int> v[1000001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=0;i<n;++i) cin >> t[i];
	for (int i=0;i<n;++i) v[t[i]].push_back(i);
	cin >> q;
	while(q--){
		a=-1;
		cin >> m;
		for (int i=0;i<m;++i) cin >> u[i];
		for (int i=0;i<m;++i){
			auto it=lower_bound(v[u[i]].begin(),v[u[i]].end(),a);
			if(it==v[u[i]].end()){
				cout << "NIE\n";
				break;
			}
			else{
				a=*it+1;
				if(i==m-1) cout << "TAK\n";
			}
		}
	}
}
