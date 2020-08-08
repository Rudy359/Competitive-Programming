#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

int n;

struct trie{
    int cnt,f;
    int k[26];
} gol;

vector <trie> t;

string s;

void Add(int nod, int p){
    if(t[nod].k[s[p]-'a']==-1){
        t.push_back(gol);
        t[nod].k[s[p]-'a']=t.size()-1;
    }
    t[t[nod].k[s[p]-'a']].cnt++;
    if(p==s.lg-1){
         t[t[nod].k[s[p]-'a']].f++;
        return;
    }
    Add(t[nod].k[s[p]-'a'],p+1);
}

void Rem(int nod, int p){
    t[t[nod].k[s[p]-'a']].cnt--;
    if(p==s.lg-1){
        t[t[nod].k[s[p]-'a']].f--;
        return;
    }
    Rem(t[nod].k[s[p]-'a'],p+1);
}

int Cnt(int nod, int p){
    if(t[nod].k[s[p]-'a']==-1) return 0;
    if(p==s.lg-1) return t[t[nod].k[s[p]-'a']].f;
    return Cnt(t[nod].k[s[p]-'a'],p+1);
}

int Pre(int nod, int p){
    if(t[nod].k[s[p]-'a']==-1) return 0;
    int ret=0;
    if(t[t[nod].k[s[p]-'a']].cnt) ret=p+1;
    if(p==s.lg-1) return ret;
    return max(ret,Pre(t[nod].k[s[p]-'a'],p+1));
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    for(int i=0;i<26;i++) gol.k[i]=-1; gol.cnt=0; gol.f=0;
    t.push_back(gol);
    while(cin >> n >> s){
        if(n==0){
            Add(0,0);
        }
        else if(n==1){
            Rem(0,0);
        }
        else if(n==2){
            cout << Cnt(0,0) << '\n';
        }
        else{
            cout << Pre(0,0) << '\n';
        }
    }
}
