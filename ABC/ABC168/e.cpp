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

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n;
    cin >> n;
    vll a(n), b(n);
    map<pll, ll> mp;
    ll zeroab, zeroa, zerob;
    zeroab = zeroa = zerob = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
        if(a[i] == 0 && b[i] == 0) zeroab++;
        else if (a[i] == 0) zeroa++;
        else if (b[i] == 0) zerob++;
        else {
            ll g = gcd(abs(a[i]), abs(b[i]));
            ll x = a[i] / g, y = b[i] / g;
            if(x > 0 && y > 0) mp[pll(x, y)]++;
            else if(x > 0) mp[pll(-x, -y)]++;
            else if(y > 0) mp[pll(x, y)]++;
            else mp[pll(abs(x), abs(y))]++;
        }
    }

    mint ans = modpow((mint)2, zeroa) + modpow((mint)2, zerob) - 1;
    set<pll> used;
    for(auto x : mp) {
        if(!used.count(x.first)) {
            auto p1 = x.first;
            auto p2 = pll(p1.second, -p1.first);
            if(p1.first > 0) p2 = pll(-p1.second, p1.first);

            ans *= modpow((mint)2, mp[p1]) + modpow((mint)2, mp[p2]) - 1;
            used.insert(p2);
        }
    }
    ans += zeroab;
    ans -= 1;
    cout << ans << endl;
}
