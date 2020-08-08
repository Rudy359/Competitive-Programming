#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

struct Treap{
    Treap *l,*r;
    int v,k,cnt;
    Treap(){
        v=0; k=0; l=0; r=0;
    }
    Treap(int v1, int k1, int cnt, Treap *l1, Treap *r1){
        v=v1; k=k1;
        l=l1; r=r1;
    }
} *T=new Treap();

void RotL(Treap *&nod){
    Treap *kid=nod->l;
    nod->l=kid->r;
    kid->r=nod;
    nod=kid;
}

void RotR(Treap *&nod){
    Treap *kid=nod->r;
    nod->r=kid->l;
    kid->l=nod;
    nod=kid;
}

void Balance(Treap *&nod){
    if(nod->l && nod->l->k<nod->k) RotL(nod);
    else if(nod->r && nod->r->k<nod->k) RotR(nod);
}

void Insert(Treap *&nod, int v, int p){
    if(nod->v>v){
        if(nod->l) Insert(nod->l,v,p);
        else nod->l=new Treap(v,p,1,0,0);
    }
    else if(nod->v<v){
        if(nod->r) Insert(nod->r,v,p);
        else nod->r=new Treap(v,p,1,0,0);
    }
    else nod->k=p, nod->cnt++;
    Balance(nod);
}

void QryE(Treap *&nod, int v){
    if(nod->v==v){
        if(nod->cnt>1){
            nod->cnt--;
            return;
        }
        if(nod->)
        if(nod->l){
            RotL(nod);
            QryE(nod,v);
        }
        else if(nod->r){
            RotR(nod);
            QryE(nod,v);
        }
        else{
            nod=0;
        }
    }
    else if(nod->v>v){
        if(nod->l) QryE(nod->l,v);
    }
    else{
        if(nod->r) QryE(nod->r,v);
    }
}


void QryI(Treap *&t, int v, int cnt=1){
    int p=rand()*30000+rand()+1;
    if(t->k){
        Insert(t,v,p);
    }
    else{
        t=new Treap(v,p,cnt,0,0);
    }
}

void Split(Treap *&t, Treap *&l, Treap *&r, int v){
    Insert(t,v,0);
    l=t->l;
    r=t->r;
    if(t->cnt>1){
        QryI(r,v,t->cnt-1);
    }
}

void Join(Treap *&t, Treap *&l, Treap *&r, int v){
    t=new Treap(v,0,1,l,r);
    QryE(t,v);
}

void Print(Treap *nod,int n){
    string s="";
    for(int i=1;i<=n;i++) s+=' ';
    cout << s;
    cout << nod->v << '\n';
    if(nod->l) cout << s << "L:", Print(nod->l,n+1);
    if(nod->r) cout << s << "R:", Print(nod->r,n+1);
}

int32_t main(){
    //ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    srand(time(0));
    QryI(T,1);
    QryI(T,2);
    QryI(T,3);
    QryI(T,4);
    QryI(T,6);
    QryI(T,7);
    QryI(T,8);
    QryI(T,9);
    Treap *t1,*t2;
    Split(T,t1,t2,5);
    Print(t1,0);
    Print(t2,0);
    Join(T,t1,t2,5);
    Print(T,0);
    while(T) QryE(T,T->v),Print(T,0);
}
