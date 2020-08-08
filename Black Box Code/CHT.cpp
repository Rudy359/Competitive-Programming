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

#define eps 0.0000000000001

struct line{
    ll a,b;
    double x;
};

double Cross(line a, line b){
    return (double)(a.b-b.b)/(b.a-a.a);
}

struct CHT{
    struct comp1{
        bool operator()(line a, line b){
            if(a.a!=b.a) return a.a>b.a;
            else return a.b<b.b;
        }
    };
    struct comp2{
        bool operator()(line a, line b){
            if(a.x!=b.x) return a.x<b.x;
            else if(a.a!=b.a) return a.a>b.a;
            else return a.b<b.b;
        }
    };
    set <line,comp1> s1;
    set <line,comp2> s2;

    void Insert(ll a, ll b){
        line p={a,b,0};
        pair<set<line,comp1>::iterator,bool> f=s1.insert(p);
        if(!f.y) return;
        auto it=f.x;

        //Remove Parallels
        auto it1=it; it1++;
        if(it1!=s1.end() && (*it1).a==(*it).a){
            s2.erase(*it1); s1.erase(it1++);
        }
        auto it2=it; it2--;
        if(it!=s1.begin() && (*it2).a==(*it).a){
            s1.erase(it);
            return;
        }

        //Check if good
        if(it!=s1.begin() && it1!=s1.end() && Cross(*it2,*it)-Cross(*it,*it1)>-eps){
            s1.erase(it);
            return;
        }
        while(1){
            if(it==s1.begin()) break;
            it1=it; it1--;
            if(it1==s1.begin()) break;
            it2=it1; it2--;
            if(Cross(*it2,*it1)-Cross(*it1,*it)>-eps){
                s2.erase(*it1); s1.erase(it1);
            }
            else break;
        }
        while(1){
            it1=it; it1++;
            if(it1==s1.end()) break;
            it2=it1; it2++;
            if(it2==s1.end()) break;
            if(Cross(*it,*it1)-Cross(*it1,*it2)>-eps){
                s2.erase(*it1); s1.erase(it1);
            }
            else break;
        }

        //Insert properly
        it1=it; it1++; it2=it; it2--;
        line temp=*it;
        if(it==s1.begin()) temp.x=-LINF;
        else temp.x=Cross(*it2,temp);
        s1.erase(it); s1.insert(temp); s2.insert(temp);
        if(it1!=s1.end()){
            line temp2=*it1;
            temp2.x=Cross(temp,temp2);
            s2.erase(*it1); s1.erase(it1); s1.insert(temp2); s2.insert(temp2);
        }
    }

    ll Qry(ll x){
        auto it=s2.upper_bound({0,0,(double)x}); it--;
        return (*it).a*x+(*it).b;
    }

};


CHT h;

//MIN Val

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    h.Insert(1,10);
    h.Insert(2,8);
    h.Insert(3,7);
    h.Insert(4,7);
    cout << h.Qry(-1);
}
