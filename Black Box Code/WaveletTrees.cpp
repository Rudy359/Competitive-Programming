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

struct nodwav{
    int l,r,hi,lo;
    vector <int> a,b;
} gol={-1,-1,0,INF,{},{}};

vector <nodwav> wav;

void GenWav(int nod){
    int l=INF,r=0;
    for(int i : wav[nod].a){
        l=min(l,i);
        r=max(r,i);
    }
    wav[nod].hi=r; wav[nod].lo=l;
    if(l>=r) return;
    int mid=(l+r)/2;
    wav.push_back(gol);
    wav[nod].l=wav.size()-1;
    wav.push_back(gol);
    wav[nod].r=wav.size()-1;
    int cnt=0;
    for(int i : wav[nod].a){
        if(i<=mid) wav[wav[nod].l].a.push_back(i),wav[nod].b.push_back(++cnt);
        else wav[wav[nod].r].a.push_back(i),wav[nod].b.push_back(cnt);
    }
    GenWav(wav[nod].l);
    GenWav(wav[nod].r);
}

int QryWavS(int nod, int lt, int rt, int k){
    if(lt>=rt) return 0;
    int l=wav[nod].lo,r=wav[nod].hi;
    if(l==r && l<=k) return rt-lt;
    else if(l>=r) return 0;
    int mid=(l+r)/2;
    int x,y;
    if(lt>=0) x=wav[nod].b[lt];
    else x=0;
    if(rt>=0) y=wav[nod].b[rt];
    else y=0;
    if(mid>=k)
        return QryWavS(wav[nod].l,x-1,y-1,k);
    else
        return y-x+QryWavS(wav[nod].r,lt-x,rt-y,k);
}

int QryWavK(int nod, int lt, int rt, int p){
    int l=wav[nod].lo,r=wav[nod].hi;
    if(l==r) return l;
    int x,y;
    if(lt>=0) x=wav[nod].b[lt];
    else x=0;
    if(rt>=0) y=wav[nod].b[rt];
    else y=0;
    if(y-x>=p){
        return QryWavK(wav[nod].l,x-1,y-1,p);
    }
    else{
        return QryWavK(wav[nod].r,lt-x,rt-y,p-y+x);
    }
}

int QryWavB(int nod, int lt, int rt, int p, int q){
    if(lt>=rt) return 0;
    int l=wav[nod].lo,r=wav[nod].hi;
    if(l>r) return 0;
    else if(l>=p && r<=q) return rt-lt;
    else if(l>q || r<p) return 0;
    else if(l==r) return 0;
    int mid=(l+r)/2;
    int x,y;
    if(lt>=0) x=wav[nod].b[lt];
    else x=0;
    if(rt>=0) y=wav[nod].b[rt];
    else y=0;
    return QryWavB(wav[nod].l,x-1,y-1,p,q)+QryWavB(wav[nod].r,lt-x,rt-y,p,q);
}

int QWS(int l, int r, int v){
    return QryWavS(0,l-2,r-1,v);
}

int QWK(int l, int r, int p){
    return QryWavK(0,l-2,r-1,p);
}

int QWC(int l, int r, int p){
    return QryWavS(0,l-2,r-1,p)-QryWavS(0,l-2,r-1,p-1);
}

int QWB(int l, int r, int p, int q){
    return QryWavB(0,l-2,r-1,p,q);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie();
    wav.push_back(gol);
    wav[0].a={1,9,5,7,6,5,4,5,7};
    GenWav(0);
    cout << QWB(2,8,4,6) << '\n';
}
