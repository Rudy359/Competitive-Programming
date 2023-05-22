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

int n,m,q,a,b,x,y,z,tp[20][400005],tsz[400005],tw[400005],th[400005],p[200005],s[200005],id[200005],uid[200005],newid,newidlimit;
pair<int,pii> e[200005];
vector<int> changed;

int par(int x){
    if(p[x] == p[p[x]]) return p[x];
    else return p[x] = par(p[x]);
}

void unite(int x, int y, int w){
    x = par(x);
    y = par(y);
    if(x == y) return;
    if(s[x] < s[y]) swap(x,y);
    newid++;
    changed.push_back(x);
    changed.push_back(y);
    p[y] = x;
    s[x] += s[y];
    uid[x] = newid;
    tsz[newid] = s[x];
    tw[newid] = w;
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        cin >> x >> y >> z;
        e[i] = {z,{x,y}};
    }
    for(int i=1;i<=n;i++){
        p[i] = i;
        s[i] = 1;
        tsz[i] = 1;
        tw[i] = 0;
        id[i] = i;
    }
    sort(e+1,e+m+1);
    newid = n;
    for(int i=1;i<=m;i++){
        if(i != 1 && e[i].x != e[i-1].x){
            for(int i : changed){
                tp[0][id[i]] = uid[par(i)];
            }
            for(int i : changed){
                id[par(i)] = uid[par(i)];
            }
            changed.clear();
        }
        unite(e[i].y.x, e[i].y.y, e[i].x);
    }
    for(int i : changed){
        tp[0][id[i]] = uid[par(i)];
    }
    for(int i : changed){
        id[par(i)] = uid[par(i)];
    }

    for(int i=newid;i>=1;i--){
        if(tp[0][i] == 0) th[i] = 1;
        else th[i] = th[tp[0][i]] + 1;
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=newid;i++){
            tp[j][i] = tp[j-1][tp[j-1][i]];
        }
    }

    for(int i=1;i<=q;i++){
        cin >> x >> y;
        if(th[x] < th[y]) swap(x,y);
        for(int j=19;j>=0;j--){
            if(th[tp[j][x]] >= th[y]) x = tp[j][x];
        }
        for(int j=19;j>=0;j--){
            if(tp[j][x] != tp[j][y]) x = tp[j][x], y = tp[j][y];
        }
        if(x != y) x = tp[0][x], y = tp[0][y];
        cout << tw[x] << ' ' << tsz[x] << '\n';
    }


}