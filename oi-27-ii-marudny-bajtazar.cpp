//Michal Ochenduszkiewicz
//https://szkopul.edu.pl/problemset/problem/kvwWom2nxVBqipEfeiMtidn5/site/?key=statement
//13.02.2021

#include <bits/stdc++.h>
#define ST first
#define ND second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int pot2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152};
int n,q;
string s,s2;
int t[10000];
unordered_map<string,int> m[18];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    for (int i=0;i<q;++i){
        cin >> t[i];
        --t[i];
    }
    for (int i=0;i<17;++i){
        for (int j=0;j+i<n;++j){
            s2=s.substr(j,i+1);
            ++m[i+1][s2];
        }
    }
    for (int i=1;i<18;++i) if(m[i].size()!=pot2[i]){
        cout << i << "\n";
        break;
    }
    for (int i=0;i<q;++i){
        for (int j=1;j<17;++j){
            for (int k=t[i]-j+1;k<t[i]+1;++k){
                if(k<0||k+j>n) continue;
                s2=s.substr(k,j);
                --m[j][s2];
                if(m[j][s2]==0) m[j].erase(s2);
            }
        }
        if (s[t[i]]=='1') s[t[i]]='0'; else s[t[i]]='1';
        for (int j=1;j<17;++j){
            for (int k=t[i]-j+1;k<t[i]+1;++k){
                if(k<0||k+j>n) continue;
                s2=s.substr(k,j);
                ++m[j][s2];
            }
        }
        for (int j=1;j<18;++j) if(m[j].size()!=pot2[j]){
            cout << j << "\n";
            break;
        }
    }
    return 0;
}
