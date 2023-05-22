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

struct Node{
    Node *l, *r;
    int cnt;

    Node(int cnt) : l(NULL), r(NULL), cnt(cnt) {}
    Node(Node *l, Node *r): l(l), r(r) {
        cnt = l->cnt + r->cnt;
    }
};

Node* roots[30005];

int n,a[30005],q,i,j,k,revm[30005];
map<int,int> m;
set<int> sm;

Node* build(int l = 1, int r = n){
    Node* node = new Node(0);
    if(l == r) return node;
    int mid = (l+r)/2;
    node->l = build(l, mid);
    node->r = build(mid + 1, r);
    return node;
}

Node* upd(Node* node, int p, int l = 1, int r = n){
    if(l > p || r < p) return node;
    if(l == r){
        Node* newNode = new Node(node->cnt+1);
        return newNode;
    }
    int mid = (l+r)/2;
    Node* newNode = new Node(
        upd(node->l, p, l, mid),
        upd(node->r, p, mid+1, r));
    return newNode;
}

int qry(Node* nodeL, Node* nodeR, int k, int l = 1, int r = n){
    if(k <= l) return nodeR->cnt - nodeL->cnt;
    if(k > r) return 0;
    int mid = (l+r)/2;
    return qry(nodeL->r, nodeR->r, k, mid+1, r) +
        qry(nodeL->l, nodeR->l, k, l, mid);
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sm.insert(a[i]);
    }
    int t = 1;
    for(int i : sm){
        m[i] = t;
        revm[t] = i;
        t++;
    }
    roots[0] = build();
    for(int i=1;i<=n;i++){
        roots[i] = upd(roots[i-1], m[a[i]]);
    }

    cin >> q;
    while(q--){
        cin >> i >> j >> k;
        auto it = sm.upper_bound(k);
        if(it == sm.end()) cout << 0 << '\n';
        else cout << (*it) << ' ' << qry(roots[i - 1], roots[j], *it) << '\n';
    }
}