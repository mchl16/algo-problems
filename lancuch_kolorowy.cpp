#include <bits/stdc++.h>
#define ST first
#define ND second
using namespace std;
map<int,int> m;
int n,k,a,w;
bool f;
int c[1000000],l[1000000],t[1000000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0;i<k;++i) cin >> l[i];
	for (int i=0;i<k;++i){
		cin >> c[i];
		a+=l[i];
		if(a>n) f=1;
		m[c[i]]-=l[i];
	}
	for (int i=0;i<n;++i) cin >> t[i];
	if(f){
		cout << 0;
		return 0;
	}
	for (int i=0;i<a;++i){
		++m[t[i]];
		if(!m[t[i]]) m.erase(t[i]);
	}
	if(m.empty()) ++w;
//	for(auto i:m) cout << i.ST << " " << i.ND << "\n"; cout << "\n";
	for (int i=a;i<n;++i){
		--m[t[i-a]];
		++m[t[i]];
		if(!m[t[i-a]]) m.erase(t[i-a]);
		if(!m[t[i]]) m.erase(t[i]);
		if(m.empty()) ++w;
	}
	cout << w;
}
