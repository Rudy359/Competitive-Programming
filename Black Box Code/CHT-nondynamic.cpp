#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define x1 xdddddddddddddddddd
#define y1 ydddddddddddddddddd

int n;

struct d{
    ll a,b,c;
}a[1000005];

bool comp(d a, d b){
    if(a.a!=b.a) return a.a>b.a;
    else return a.b<b.b;
}

#define eps 0.0000000000001

struct line{
    ll a,b;
    ld x;
};

ld Cross(line a, line b){
    return (ld)(a.b-b.b)/(b.a-a.a);
}

struct CHT{

    vector <line> s;

    void Insert(ll a, ll b){
        if(s.sz==0){
            s.pb({a,b,-1.0});
        }
        else if(s.sz==1){
            s.pb({a,b,-1.0});
            s[1].x=Cross(s[0],s[1]);
        }
        else{
            line nw={a,b,-1.0};
            while(s.sz>=2){
                if(Cross(s[s.sz-2],s[s.sz-1])-Cross(s[s.sz-1],nw)<eps) s.pop_back();
                // >-eps to swap
                else break;
            }
            nw.x=Cross(s[s.sz-1],nw);
            s.pb(nw);
        }
    }

    ll Qry(ll x){
        ll l=0,r=s.sz-1;
        while(l!=r){
            int mid=(l+r+1)/2;
            if(s[mid].x-x<eps) r=mid-1;
            // >-eps to swap
            else l=mid;
        }
        return s[l].a*x+s[l].b;
    }

};


CHT h;

// MAX Value, Add in decreasing order
// swap once for each change (so don't swap when changing both)

ll dp[1000005],ans;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    sort(a+1,a+n+1,comp);
    dp[1]=max(0ll,a[1].a*a[1].b-a[1].c);
    ans=dp[1];
    h.Insert(-a[1].b,dp[1]);
    for(int i=2;i<=n;i++){
        dp[i]=max(0ll, max(0ll,h.Qry(a[i].a))+a[i].a*a[i].b-a[i].c);
        ans=max(ans,dp[i]);
        h.Insert(-a[i].b,dp[i]);
    }
    cout << ans;
}
