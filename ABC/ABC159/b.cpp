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
    int n = s.size();
    string t = "";
    t += s;
    reverse(t.begin(), t.end());
    if(s.substr(0, (n-1)/2) == s.substr((n+1)/2, (n-1)/2) && s.substr(0, (n-1)/2) == t.substr(0, (n-1)/2) && s.substr(0, (n-1)/2) == t.substr((n+1)/2, (n-1)/2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
