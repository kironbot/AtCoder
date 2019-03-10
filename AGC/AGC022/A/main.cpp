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
    if (s.size() == 26u) {
        string t(s);
        if (!next_permutation(t.begin(), t.end())) {
            cout << -1 << endl;
            return 0;
        }
        while (t.substr(0, t.size()-1) > s) t.pop_back();
        cout << t << endl;
    } else {
        for (char nc = 'a'; nc <= 'z'; nc++) {
            bool used = false;
            for (char c : s) if (c == nc) used = true;
            if (used) continue;
            cout << s << nc << endl;
            return 0;
        }
    }
}
