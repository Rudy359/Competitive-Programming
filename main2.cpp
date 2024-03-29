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
#ifdef LOCAL_DEFINED
#define debug(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << to_string(x) << endl
mt19937 rng(0);
#else
#define debug(x) 0
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
int rand(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}

ll pwr(ll a, ll p, ll mod){
    if(p==0) return 1;
    ll t = pwr(a, p/2, mod);
    t = (t*t) % mod;
    if(p%2) t = (t*a) % mod;
    return t;
}

int32_t main(){
    ios_base :: sync_with_stdio(); cin.tie(); cout.tie();

    ll x = rand(0, 1000000);
    ll p = 666013;
    ll g = rand(0, 1000000);
    ll y = pwr(g,x,p);
    ll r = rand(2, p-1);
    ll c = pwr(g,r,p);
    ll h = pwr(g,c,p);
    ll q = ((r - x * h) % (p-1) + p - 1 ) % (p - 1);
    cout << p << ' ' << g << ' ' << y << ' ' << c << ' ' << q << '\n';

    
}