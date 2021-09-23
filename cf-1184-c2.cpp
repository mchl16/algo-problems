//Michal Ochenduszkiewicz
//https://codeforces.com/contest/1184/problem/C2
//22.09.2021

#include <bits/stdc++.h>
#define ST first
#define ND second
using namespace std;
     
class Tree{
    static constexpr int MAX_L=1e9+7;
    static constexpr int size=(1<<22);
    long long drzewo[2*size];
    long long add[2*size];
    public:
        void dodaj(const int& gdzie,const int& co){
            add[gdzie]+=co;
            drzewo[gdzie]+=co;
        }
	void push(const int& gdzie){
		dodaj(2*gdzie,add[gdzie]);
		dodaj(2*gdzie+1,add[gdzie]);
		add[gdzie]=0;
	}
	void insert(const int& a,const int& b,const int& co,const int& gdzie=1,const int& lewo=1,const int& prawo=size){
		if(lewo>=a&&prawo<=b){
			dodaj(gdzie,co);
			return;
		}
		push(gdzie);
		int srodek=(lewo+prawo)/2;
		if (a<=srodek) insert(a,b,co,2*gdzie,lewo,srodek);
		if (b>srodek) insert(a,b,co,2*gdzie+1,srodek+1,prawo);
		drzewo[gdzie]=max(drzewo[2*gdzie],drzewo[2*gdzie+1])+add[gdzie];
	}
	long long query(const int& a,const int& b,const int& gdzie=1,const int& lewo=1,const int& prawo=size){
		if(lewo>=a&&prawo<=b) return drzewo[gdzie];
		push(gdzie);
		int srodek=(lewo+prawo)/2;
		long long res=-MAX_L;
		if (a<=srodek) res=max(res,query(a,b,2*gdzie,lewo,srodek));
		if (b>srodek) res=max(res,query(a,b,2*gdzie+1,srodek+1,prawo));
		return res;
	}
} tree;
     
int n,r,a,b;
long long res;
constexpr int XD=2e6+1;
map<int,vector<int>> M;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        M[a-b].push_back(a+b+XD);
    }
    auto it=M.begin();
    while(it!=M.end()){
        auto jt=M.lower_bound(it->ST-2*r);
        for (auto i=M.begin();i!=jt;){
            for (const auto& j:i->ND) tree.insert(j-r,j+r,-1);
            i=M.erase(i);
        }
        for (const auto& j:it->ND) tree.insert(j-r,j+r,1);
        res=max(res,tree.query(1,1<<22));
        ++it;
    }
    cout << res << "\n";
}
