#include <bits/stdc++.h>
using namespace std;

char genchar(){
    char c;
    do{
        if(rand()%2) c = rand() % 10 + '0';
        else c = rand() % ('z'-'a'+1) + 'a';
    }while(c == '1' || c == 'l' || c == 'o' || c == '0');
    return c;
}

string genpass(){
    string pass = "";
    for(int i=1;i<=6;i++){
        pass += genchar();
    }
    return pass;
}

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    srand(time(0));
    for(int i=1;i<=60;i++){
        string a,b;
        cin >> a >> b;
        string username = "";
        username += b[0] + 'a' - 'A';
        username += a;
        username[1] += 'a' - 'A';
        cout << username << '\t' << genpass() << '\n';
    }
}
