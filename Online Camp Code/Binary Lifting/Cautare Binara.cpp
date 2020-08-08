#include <bits/stdc++.h>
using namespace std;

/// Arrayul a e indexat de la 0, cu n elemente (0..n-1)
/// Daca v exista in a, returneaza pozitia lui (ultima in caz de raspunsuri multiple)
/// Daca nu, returneaza -1

int binary_search1(int n, int a[], int v){
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r+1)/2;
        if(a[mid]<=v) l=mid;
        else r=mid-1;
    }
    if(a[l]==v) return l;
    else return -1;
}

int binary_search2(int n, int a[], int v){
    int pos=0,k=0;
    while((1<<k)<n) k++;
    for(int i=k;i>=0;i--){
        if(pos+(1<<i)<n && a[pos+(1<<i)]<=v) pos+=(1<<i);
    }
    if(a[pos]==v) return pos;
    else return -1;
}

int main(){
    int n=6,a[n]={1,2,3,4,4,5};
    cout << binary_search1(n,a,5) << ' ' << binary_search2(n,a,5) << '\n';
}
