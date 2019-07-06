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
    string s;
    cin >> s;
    if(s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) cout << "Yes" << endl;
    else if(s[0] == s[2] && s[1] == s[3] && s[0] != s[1]) cout << "Yes" << endl;
    else if(s[0] == s[3] && s[1] == s[2] && s[0] != s[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
