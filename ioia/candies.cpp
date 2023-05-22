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
#include "candies.h"


vector<int> distribute_candies(vector<int> c, vector<int> l, vector<int> r, vector<int> v) {
    
    int n = sz(c), q = sz(l);
    vector<int> a(n, 0);
    vector<ll> b(n, 0);
    for(int i=0;i<q;i++){
        b[l[i]] += v[i];
        if(r[i] != n) b[r[i]+1] -= v[i];
    }
    for(int i=1;i<n;i++){
        b[i] += b[i-1];
    }
    for(int i=0;i<n;i++){
        a[i] = min(b[i], (ll)c[i]);
    }

    return a;

}
