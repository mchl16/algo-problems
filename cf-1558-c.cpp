//Michal Ochenduszkiewicz
//https://codeforces.com/problemset/problem/1558/C
//26.09.2021

#include <bits/stdc++.h>
using namespace std;

int q;
vector<int> v;
struct tc{
	int n,res;
	int t[2022],pos[2022];
	void rev(const int& k){ //reverse the prefix of length k
		v.push_back(k);
		reverse(t,t+k);
		for (int i=0;i<k;++i) pos[t[i]]=i;
		++res;
	}
	tc()=default; //first constructor for struct initialization
	tc(int a){ //second constructor - this one is used for each new test case
		v.clear();
		res=0;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> t[i];
			pos[t[i]]=i;
			if(!((i^t[i])&1)) a=1; //odd numbers must be at odd positions, even numbers at even positions
		}
		if(a) cout << "-1\n";
		else{
			for(int i=n;i>1;i-=2){ //move 2 largest unmoved numbers to the back of the array using 5 prefix reversals
				rev(pos[i]+1);
				rev(pos[i-1]);
				rev(pos[i-1]+2);
				rev(3);
				rev(i);
			}
			cout << res << "\n";
			for (const auto& j:v) cout << j << " "; cout << "\n";
		}
	}
} T;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> q;
	while(q--) T=tc(0);
}
