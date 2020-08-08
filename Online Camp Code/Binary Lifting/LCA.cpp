#include <bits/stdc++.h>
using namespace std;

int n,logn=19;
vector <int> g[100005]; ///Matricea de adiacenta a grafului
int p[20][100005]; /// p[i][j] = al 2^i-lea parinte al lui j
int h[100005]; /// h[i] = inaltimea lui i (radacina are inaltimea 1)

int BuildSparseTable(int nod, int par){ ///Folosim un DFS pentru a construi matricea p in O(nlogn)
    h[nod]=h[par]+1;
    p[0][nod]=par;
    for(int i=1;i<=logn;i++){
        p[i][nod]=p[i-1][p[i-1][nod]];
    }
    for(int i : g[nod]){
        if(h[i]==0){
            BuildSparseTable(i, nod);
        }
    }
}

int LCA(int x, int y){ ///Returneaza LCA-ul a doua noduri in o(logn)
    if(h[x]<h[y]) swap(x,y);
    for(int i=logn;i>=0;i--){
        if(h[p[i][x]]>=h[y]) x=p[i][x];
    }
    if(x==y) return x;
    for(int i=logn;i>=0;i--){
        if(p[i][x]!=p[i][y]) x=p[i][x], y=p[i][y];
    }
    return p[0][x];
}

int main(){
    cin >> n;
    int x,y;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BuildSparseTable(1,0);
    while(1){
        cin >> x >> y;
        cout << LCA(x,y) << '\n';
    }
}
