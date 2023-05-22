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
#include "parks.h"


int construct_roads(vector<int> x, vector<int> y) {
    int n = sz(x);
    vector<int> u, v, a, b;
    vector<int> p[3];
    p[0].resize(200005);
    p[1].resize(200005);
    p[2].resize(200005);
    int L=INF,R=0;
    for(int i=0;i<n;i++){
        p[x[i]/2 - 1][y[i]] = i + 1;
        L = min(L, y[i]);
        R = max(R, y[i]);
    }
    int last = 0;
    for(int i=L;i<=R;i+=2){
        int cnt = 0, f = 0;
        if(p[0][i] && p[1][i] && p[2][i]){
            if
        }
        if(p[0][i] && p[1][i]) u.pb(p[0][i] - 1), v.pb(p[1][i] - 1), a.pb(3), b.pb(i+1), f++;
        if(p[1][i] && p[2][i]) u.pb(p[1][i] - 1), v.pb(p[2][i] - 1), a.pb(5), b.pb(i-1), f++;
        if(p[0][i] && p[0][i-2]) u.pb(p[0][i] - 1), v.pb(p[0][i-2] - 1), a.pb(1), b.pb(i-1), cnt++;
        if(p[2][i] && p[2][i-2]) u.pb(p[2][i] - 1), v.pb(p[2][i-2] - 1), a.pb(7), b.pb(i-1), cnt++;
        if(i>L && p[0][i] && p[2][i] && !p[1][i] && cnt != 2) return 0;
        if(p[1][i] && p[1][i-2] && cnt == 0 && f == 0) u.pb(p[1][i] - 1), v.pb(p[1][i-2] - 1), a.pb(5), b.pb(i-1), cnt++;
        if(p[1][i] && p[1][i-2] && cnt == 0 && f == 2) u.pb(p[1][i] - 1), v.pb(p[1][i-2] - 1), a.pb(3), b.pb(i-1), cnt++;
        if(i>L && !cnt) return 0;
    }
    build(u, v, a, b);
    return 1;

}
