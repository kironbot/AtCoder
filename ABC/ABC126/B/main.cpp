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

    if (s.substr(0, 2) <= "12" && s.substr(0, 2) >= "01" && s.substr(2, 2) <= "12" && s.substr(2, 2) >= "01") cout << "AMBIGUOUS" << endl;
    else if (s.substr(2, 2) <= "12" && s.substr(2, 2) >= "01") cout << "YYMM" << endl;
    else if (s.substr(0, 2) <= "12" && s.substr(0, 2) >= "01") cout << "MMYY" << endl;
    else cout << "NA" << endl;
}
