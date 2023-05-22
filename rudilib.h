using namespace std;

void exitWA(){
    cout << "0.0\n";
    cerr << "translate:wrong\n";
    exit(0);
}

void exitAC(){
    cout << "1.0\n";
    cerr << "translate:success\n";
    exit(0);
}

void exitPA(double p){
    cout << p << "\n";
    cerr << "translate:partial\n";
    exit(0);
}

string readString(ifstream &stream){
    if(stream.eof()) exitWA();
    string s = "";
    if(!(stream >> s)) exitWA();
    return s;
}

int readInt(ifstream &stream){
    string s = readString(stream);
    int ans;
    try{
        ans = stoi(s);
    } catch(...) { exitWA(); }
    return ans;
}

int readInt(ifstream &stream, int l, int r){
    int ans = readInt(stream);
    if(ans < l || ans > r) exitWA();
    return ans;
}

long long readLL(ifstream &stream){
    string s = readString(stream);
    long long ans;
    try{
        ans = stoll(s);
    } catch(...) { exitWA(); }
    return ans;
}

long long readLL(ifstream &stream, long long l, long long r){
    long long ans = readLL(stream);
    if(ans < l || ans > r) exitWA();
    return ans;
}
