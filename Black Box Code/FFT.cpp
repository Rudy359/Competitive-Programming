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
#define double long double

vector <complex<double>> RecFFT(vector <double> a){
    int n=a.size();
    if(n==1) return {{a[0],0}};
    vector <double> a1,a2;
    for(int i=0;i<n;i+=2) a1.push_back(a[i]);
    for(int i=1;i<n;i+=2) a2.push_back(a[i]);
    vector <complex<double>> x,y,ans;
    x=RecFFT(a1);
    y=RecFFT(a2);
    //a(x)=a1(x^2)+x*a2(x^2)
    for(int i=0;i<n;i++) ans.push_back({0,0});
    complex <double> t={0,2*acos(-1)/n},w={1,0};
    t=exp(t);
    for(int i=0;i<n/2;i++){
        ans[i]=x[i]+w*y[i];
        ans[i+n/2]=x[i]-w*y[i];
        w*=t;
    }
    return ans;
}

vector <complex <double>> InvFFT(vector <complex <double>> a){
    int n=a.size();
    if(n==1) return {{a[0],0}};
    vector <complex<double>> x,y,ans;
    for(int i=0;i<n;i+=2) x.push_back(a[i]);
    for(int i=1;i<n;i+=2) y.push_back(a[i]);
    x=InvFFT(x);
    y=InvFFT(y);
    for(int i=0;i<n;i++) ans.push_back({0,0});
    complex <double> t={0,-2*acos(-1)/n},w={1,0};
    t=exp(t);
    for(int i=0;i<n/2;i++){
        ans[i]=x[i]+w*y[i];
        ans[i+n/2]=x[i]-w*y[i];
        w*=t;
    }
    return ans;
}


vector <double> DoubFFT(vector <double> a, vector <double> b){
    int sa=a.size(),sb=b.size(),n=sa+sb-1;
    int k=1;
    while(k<n) k*=2;
    for(int i=sa;i<k;i++) a.push_back(0);
    for(int i=sb;i<k;i++) b.push_back(0);
    vector <complex<double>> x=RecFFT(a);
    vector <complex<double>> y=RecFFT(b);
    for(int i=0;i<k;i++){
        x[i]*=y[i];
    }
    x=InvFFT(x); a.clear();
    for(int i=0;i<sa+sb-1;i++) a.push_back(real(x[i])/k);
    return a;
}

vector <int> IntFFT(vector <int> a, vector <int> b){
    int sa=a.size(),sb=b.size(),n=sa+sb-1;
    int k=1;
    while(k<n) k*=2;
    vector <double> p,q;
    for(int i=0;i<sa;i++) p.push_back(a[i]);
    for(int i=0;i<sb;i++) q.push_back(b[i]);
    for(int i=sa;i<k;i++) p.push_back(0);
    for(int i=sb;i<k;i++) q.push_back(0);
    vector <complex<double>> x=RecFFT(p);
    vector <complex<double>> y=RecFFT(q);
    for(int i=0;i<k;i++){
        x[i]*=y[i];
    }
    x=InvFFT(x); a.clear();
    for(int i=0;i<sa+sb-1;i++){
        if(real(x[i])>0) a.push_back((int)(real(x[i])/k+0.5));
        else a.push_back((int)(real(x[i])/k-0.5));
    }
    return a;
}

vector <long long> LongFFT(vector <long long> a, vector <long long> b){
    int sa=a.size(),sb=b.size(),n=sa+sb-1;
    int k=1;
    while(k<n) k*=2;
    vector <double> p,q;
    for(int i=0;i<sa;i++) p.push_back(a[i]);
    for(int i=0;i<sb;i++) q.push_back(b[i]);
    for(int i=sa;i<k;i++) p.push_back(0);
    for(int i=sb;i<k;i++) q.push_back(0);
    vector <complex<double>> x=RecFFT(p);
    vector <complex<double>> y=RecFFT(q);
    for(int i=0;i<k;i++){
        x[i]*=y[i];
    }
    x=InvFFT(x); a.clear();
    for(int i=0;i<sa+sb-1;i++){
        if(real(x[i])>0) a.push_back((long long)(real(x[i])/k+0.5));
        else a.push_back((long long)(real(x[i])/k-0.5));
    }
    return a;
}

vector <int> p1,p2,p3;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    p1={5,3,9,2,4,5};
    p2={1,5,3};
    p3=IntFFT(p1,p2);
    for(int i : p3) cout << i << ' ';
    //#define double long double PENTRU LONG LONG
}
