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



int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int n, m, k;

    n = 10;
    m = 20;
    k = 1;
    cout << n << ' ' << m << ' ' << k << '\n';
    
    map<pair<int,int>, bool> g;
    int p[n+5],q[n+5];
    for(int i=1;i<=n;i++){
        q[i] = i;
        if(i > 1) p[i] = rand(1, i-1);
    }
    shuffle(q+1,q+n+1,rng);
    for(int i=2;i<=n;i++){
        cout << q[i] << ' ' << q[p[i]] << ' ' << rand(0, 100000) << '\n';
        g[{q[i], q[p[i]]}] = 1;
    }
    for(int i=n;i<=m;i++){
        int x,y;
        do{
            x = rand(1,n);
            y = rand(1,n);
        }while(x == y || g[{x,y}] || g[{y,x}]);
        cout << x << ' ' << y << ' ' << rand(0, 100000) << '\n';
        g[{x,y}] = 1;
    }
    for(int i=1;i<=k;i++){
        int x,y;
        do{
            x = rand(1,n);
            y = rand(1,n);
        }while(x == y);
        cout << x << ' ' << y << '\n';
    }

}