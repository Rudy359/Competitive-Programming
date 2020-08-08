#pragma GCC optimize ("O3")
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

unordered_map <int,bool> m;

struct nod{
    nod *l, *r;
    int v,p,cnt;
    nod(int vt){
        l=r=0;
        v=vt;
        cnt=1;
        do{
            p=rand()*1000+rand();
        }while(m[p]);
        m[p]=1;
    }
};
nod *t = 0;

int get_cnt(nod* t){
    if(t==0) return 0;
    else return t->cnt;
}

void upd_cnt(nod* t){
    if(t) t->cnt=1+get_cnt(t->l)+get_cnt(t->r);
}

void Split(nod* t, nod* &l, nod* &r, int v){
    if(t==0){
        l=r=0;
        return;
    }
    if(t->v > v) Split(t->l,l,t->l,v),r=t;
    else Split(t->r,t->r,r,v),l=t;
    upd_cnt(t);
}

void Merge(nod* &t, nod* l, nod* r){
    if(l==0 || r==0) t=(l==0?r:l);
    else if(l->p > r->p)  Merge(l->r,l->r,r), t=l;
    else Merge(r->l,l,r->l), t=r;
    upd_cnt(t);
}

void Insert(nod* &t, nod* nw){
    if(t==0) t=nw;
    else if(t->p < nw->p) Split(t,nw->l,nw->r,nw->v),t=nw;
    else if(t->v < nw->v) Insert(t->r,nw);
    else Insert(t->l,nw);
    upd_cnt(t);
}

void Erase(nod* &t, int v){
    if(t==0) return;
    if(t->v == v) Merge(t,t->l,t->r);
    else if(t->v > v) Erase(t->l,v);
    else Erase(t->r,v);
    upd_cnt(t);
}

int Qry(nod* t, int k){
    if(t==0) return -1;
    if(get_cnt(t->l)+1==k) return t->v;
    else if(get_cnt(t->l)>=k) return Qry(t->l,k);
    else return Qry(t->r,k-get_cnt(t->l)-1);
}

int main(){

}
