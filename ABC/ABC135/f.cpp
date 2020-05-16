#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

//
// ローリングハッシュ
//
// verified:
//   ABC 141 E - Who Says a Pun?
//     https://atcoder.jp/contests/abc141/tasks/abc141_e
//

struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<long long> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }

    // get hash of S[left:right]
    inline pair<long long, long long> get(int l, int r) const {
        long long res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        long long res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }

    // get lcp of S[a:] and S[b:]
    inline int getLCP(int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }

    // get lcp of S[a:] and T[b:]
    inline int getLCP(const RollingHash &T, int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != T.get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};


string s, t, s1;
ll n, m;
bool ok[550000];
ll longest[550000];

ll calc_longest(ll i, ll dep = 0) {
    if(dep > n) return -1;
    if(longest[i] != -1) return longest[i];
    if(!ok[i]) return longest[i] = 0;

    longest[i] = calc_longest((i + m) % n, dep+1);
    if(longest[i] == -1) return -1;
    return longest[i] += 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> s >> t;
    n = s.size(), m = t.size();
    while(s1.size() < 2 * max(n, m)) s1 += s;

    fill(longest, longest+550000, -1);
    RollingHash rh1(s1), rh2(t);
    rep(i, n) if(rh1.get(i, i+m) == rh2.get(0, m)) ok[i] = true;

    ll ans = 0;
    rep(i, n) {
        longest[i] = calc_longest(i);
        if(longest[i] == -1) {
            cout << -1 << endl;
            return 0;
        }
        chmax(ans, longest[i]);
    }
    cout << ans << endl;
}