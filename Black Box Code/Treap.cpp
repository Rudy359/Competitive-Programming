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


struct treap{
    int v,k,cnt,h,l,r,p;
};

vector <treap> t;

void Init(){
    t.push_back({1000000007,0,0,0,-1,-1,-1});
    srand(time(NULL));
}

void RotL(int nod){
    int p=t[nod].p,k=t[nod].l,d=t[k].r;
    if(t[p].l==nod)
        t[p].l=k;
    else
        t[p].r=k;
    t[k].p=p;
    t[nod].p=k;
    t[k].r=nod;
    t[nod].l=d;
    if(d!=-1) t[d].p=nod;
    if(t[k].l!=-1) t[nod].h-=t[t[k].l].h;
    t[nod].h--;
    if(t[nod].r!=-1) t[k].h+=t[t[nod].r].h;
    t[k].h++;
}

void RotR(int nod){
    int p=t[nod].p,k=t[nod].r,d=t[k].l;
    if(t[p].l==nod)
        t[p].l=k;
    else
        t[p].r=k;
    t[k].p=p;
    t[nod].p=k;
    t[k].l=nod;
    t[nod].r=d;
    if(d!=-1) t[d].p=nod;
    if(t[k].r!=-1) t[nod].h-=t[t[k].r].h;
    t[nod].h--;
    if(t[nod].l!=-1) t[k].h+=t[t[nod].l].h;
    t[k].h++;
}

void Balance(int nod){
    if(t[nod].l!=-1 && t[t[nod].l].k<t[nod].k) RotL(nod);
    else if(t[nod].r!=-1 && t[t[nod].r].k<t[nod].k) RotR(nod);
}

void Insert(int nod, int v, int k){
    t[nod].h++;
    if(v==t[nod].v){
        t[nod].cnt++;
        return;
    }
    if(v<t[nod].v){
        if(t[nod].l==-1){
            t.push_back({v,k,1,1,-1,-1,nod});
            t[nod].l=t.size()-1;
        }
        else Insert(t[nod].l,v,k);
    }
    if(v>t[nod].v){
        if(t[nod].r==-1){
            t.push_back({v,k,1,1,-1,-1,nod});
            t[nod].r=t.size()-1;
        }
        else Insert(t[nod].r,v,k);
    }
    Balance(nod);
}

bool Erase(int nod, int v){
    if(v==t[nod].v){
        if(t[nod].cnt>1){
            t[nod].cnt--;
            t[nod].h--;
            return 1;
        }
        if(t[nod].l==-1 && t[nod].r==-1){
            if(t[t[nod].p].l==nod) t[t[nod].p].l=-1;
            else t[t[nod].p].r=-1;
            return 1;
        }
        if(t[nod].l==-1) RotR(nod);
        else if(t[nod].r==-1) RotL(nod);
        else if(t[t[nod].l].k<t[t[nod].r].k) RotL(nod);
        else RotR(nod);
        t[t[nod].p].h--;
        return Erase(nod,v);
    }
    else{
        if(v>t[nod].v){
            if(t[nod].r!=-1){
                bool ret=Erase(t[nod].r,v);
                if(ret) t[nod].h--;
                return ret;
            }
            else return 0;
        }
        else{
            if(t[nod].l!=-1){
                bool ret=Erase(t[nod].l,v);
                if(ret) t[nod].h--;
                return ret;
            }
            else return 0;
        }
    }
}

bool Find(int nod, int v){
    if(t[nod].v==v) return 1;
    if(v>t[nod].v){
        if(t[nod].r==-1) return 0;
        else return Find(t[nod].r,v);
    }
    else{
        if(t[nod].l==-1) return 0;
        else return Find(t[nod].l,v);
    }
}

int Kth(int nod, int k){
    int x=0;
    if(t[nod].l!=-1) x=t[t[nod].l].h;
    if(x+1<=k && x+t[nod].cnt>=k) return t[nod].v;
    else{
        if(x+1>k) return Kth(t[nod].l,k);
        else if(t[nod].r!=-1) return Kth(t[nod].r,k-x-t[nod].cnt);
        else return -1;
    }
}

void QryI(int v){
    int p=rand()*1000+rand()+1;
    Insert(0,v,p);
}

void QryE(int v){
    if(Erase(0,v)) t[0].h--;
}

bool QryF(int v){
    return Find(0,v);
}

int QryK(int v){
    return Kth(0,v);
}


int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    Init();

}
