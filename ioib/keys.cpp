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

vector<vector<int>> g;
vector<vector<pii>> G;
vector<vector<int>> scc;
vector<int> id,lv,ons,sid,gd,p,sp;
int n,m,k = 0;
stack<int> s;

int Par(int nod){
    if(p[p[nod]] == p[nod]) return p[nod];
    else return p[nod] = Par(p[nod]);
}

void Unite(int x, int y){
    x = Par(x); y = Par(y);
    if(x == y) return;
    if(sp[x] < sp[y]) swap(x, y);
    sp[x] += sp[y];
    p[y] = x;
}

void DFS(int nod){
	id[nod] = lv[nod] = k;
	k++;
	s.push(nod);
	ons[nod] = 1;
	for(int i : g[nod]){
		if(ons[i]) lv[nod] = min(lv[nod], id[i]);
		else if(id[i] == -1){
			DFS(i);
			lv[nod] = min(lv[nod], lv[i]);
		}
	}
	if(lv[nod] == id[nod]){
		scc.pb({});
		while(s.top() != nod){
			sid[s.top()] = id[nod];
			scc[sz(scc)-1].pb(s.top());
			ons[s.top()] = 0;
			s.pop();
		}
		sid[nod] = id[nod];
		scc[sz(scc)-1].pb(nod);
		ons[nod] = 0;
		s.pop();
	}
}

vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c) {
	
	n = sz(r), m = sz(u);

	g.resize(n);
	G.resize(n);
	for(int i=0;i<m;i++){
		if(c[i] == r[u[i]]) g[u[i]].pb(v[i]); //cout << u[i] << ' ' << v[i] << '\n';
		if(c[i] == r[v[i]]) g[v[i]].pb(u[i]); //cout << v[i] << ' ' << u[i] << '\n';
		G[u[i]].pb({v[i], c[i]});
		G[v[i]].pb({u[i], c[i]});
	}
	id.resize(n, -1);
	lv.resize(n, -1);
	ons.resize(n, 0);
	sid.resize(n, -1);
	gd.resize(n, 1);
	p.resize(n, 0);
	sp.resize(n, 1);
	for(int i=0;i<n;i++) p[i] = i;
	for(int i=0;i<n;i++){
		if(id[i] == -1) DFS(i);
	}

	vector<int> hk(n, 0);
	for(int i=0;i<sz(scc);i++){
		for(int j : scc[i]){
			hk[r[j]] = 1;
		}
		for(int j : scc[i]){
			for(pii k : G[j]){
				if(hk[k.y] && sid[j] != sid[k.x]) gd[i] = 0;
			}
		}
		for(int j : scc[i]){
			hk[r[j]] = 0;
		}
	}

	int mn = INF;
	for(int i=0;i<sz(scc);i++) if(gd[i]) mn = min(mn, sz(scc[i]));
	vector<int> ans(n, 0);
	for(int i=0;i<sz(scc);i++){
		//cout << gd[i] << ": ";
		//for(int j : scc[i]) cout << j << ' ';
		//cout << '\n';
		if(gd[i] && sz(scc[i]) == mn){
			for(int j : scc[i]) ans[j] = 1;
		}
	}

	return ans;
}
