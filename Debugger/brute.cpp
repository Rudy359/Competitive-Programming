#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define lg length()
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#ifdef LOCAL_DEFINE
#define debug(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << to_string(x) << endl
mt19937 rng(0);
#else
#define debug(x) 0
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
int rand(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}

int n,m,q,x,y,z,v[100005],mxz;
vector<pii> g[100005];
set<int> w;

int DFS(int nod, int val){
    if(v[nod]) return 0;
    v[nod]=1;
    int ret = 1;
    for(pii i : g[nod]){
        if(i.y <= val) ret += DFS(i.x, val);
    }
    return ret;
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        cin >> x >> y >> z;
        w.insert(z);
        g[x].pb({y,z});
        g[y].pb({x,z});
    }
    for(int i=1;i<=q;i++){
        cin >> x >> y;
        for(int j : w){
            for(int i=1;i<=n;i++) v[i] = 0;
            int t = DFS(x,j);
            if(v[y]){
                cout << j << ' ' << t << '\n';
                break;
            }
        }
    }
    
}