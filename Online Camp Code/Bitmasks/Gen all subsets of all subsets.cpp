#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout << 1;
            else cout << 0;
        }
        cout << ":\n";
        for(int j=i;;j=(j-1)&i){
            cout << '\t';
            for(int k=0;k<n;k++){
                if(j&(1<<k)) cout << 1;
                else cout << 0;
            }
            cout << '\n';
            if(!j) break;
        }
    }
}
