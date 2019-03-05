#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n;
    cin >> n;
    set<int> s;
    int pool = 0;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if (a <= 399) s.insert(1); 
        else if (a <= 799) s.insert(2);
        else if (a <= 1199) s.insert(3);
        else if (a <= 1599) s.insert(4);
        else if (a <= 1999) s.insert(5);
        else if (a <= 2399) s.insert(6);
        else if (a <= 2799) s.insert(7);
        else if (a <= 3199) s.insert(8);
        else pool++;
    }
    cout << max((int)s.size(), 1) << " " << (int)s.size() + pool << endl;    
}
