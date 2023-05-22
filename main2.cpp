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

int n,x,k;

double p[1000005], s[1000005], q[1000005], a[1000005], j[1000005], b[1000005], c[1000005];

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    
    cin >> n >> x >> k;
    p[x] = 1;
    for(int i=n;i>=1;i--){
        a[i] = a[i+1] + (1.0 / n) * (1.0 / i);
        j[i] = (double)(i - 1) / n;
    }
    /*
    for(int t=0;(1<<t)<=k;t++){
        for(int i=1;i<=n;i++){
            b[i] = b[i - 1] + a[i];
        }    
        for(int i=n;i>=1;i--){
            c[i] = c[i + 1] + a[i] * a[i];
        }
        for(int i=1;i<=n;i++){
            a[i] = a[i] * b[i] + c[i + 1];
            cout << a[i] << ' ';
        }
        cout << "\n\n";
    }*/
    int c = 10 * n;
    for(int i=1;i<=k;i++){
        int t = max(1, n - c / i);
        for(int j=1;j<=n;j++) s[j] = s[j-1] + p[j];
        for(int j=n;j>=1;j--) q[j] = q[j+1] + s[j] / j;
        for(int i=1;i<=n;i++) p[i] = (p[i] * (i - 1) + q[i]) / n;
    }
    double ans = 0;
    for(int i=1;i<=n;i++){
        ans += p[i] * i;
    }
    cout << fixed << setprecision(7) << ans << '\n';

}