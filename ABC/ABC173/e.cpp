#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
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
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vll A(N);
    vpll B(N);
    ll cntp = 0, cntz = 0, cntn = 0;
    rep(i,N) {
        cin >> A[i];
        B.emplace_back(-abs(A[i]), A[i]);
        if(A[i] > 0) cntp++;
        if(A[i] < 0) cntn++;
        if(A[i] == 0) cntz++;
    }

    bool is_pos = true;
    if(K % 2 && cntp == 0) is_pos = false;
    if(K == N && cntn % 2) is_pos = false;


    mint ans = 1;
    if(is_pos) {
        sort(B.begin(), B.end());

        ll sign = 1;
        ll last_pos = 0, last_neg = 0;
        rep(i,K) {
            ans *= B[i].second;
            if(B[i].second < 0) {
                last_neg = B[i].second;
                sign *= -1;
            }
            if(B[i].second > 0) {
                last_pos = B[i].second;
            }
        }

        // 絶対値上位K個に0があったらans=0
        if(B[K-1].second == 0) {
            cout << 0 << endl;
            return 0;
        }

        // 符号が負のとき入れ替える
        if(sign < 0) {
            // 使ってないもののうち、絶対値最大のもの
            ll next_pos = 0, next_neg = 0;
            for(ll i = K; i < N; i++) {
                if(B[i].second > 0) {
                    chmax(next_pos, B[i].second);
                }
                if(B[i].second < 0) {
                    chmin(next_neg, B[i].second);
                }
            }

            if(next_pos == 0 && next_neg == 0) ans = 0;
            else if (last_pos != 0 && next_pos == 0) {
                ans /= last_pos;
                ans *= next_neg;
            }
            else if (last_neg != 0 && next_neg == 0) {
                ans /= last_neg;
                ans *= next_pos;
            }
            else {
                if(last_pos == 0) {
                    ans /= last_neg;
                    ans *= next_pos;
                }
                else if(last_neg == 0) {
                    ans /= last_pos;
                    ans *= next_neg;
                }
                else if(abs(next_neg) * abs(last_neg) >= last_pos * next_pos) {
                    ans /= last_pos;
                    ans *= next_neg;
                }
                else {
                    ans /= last_neg;
                    ans *= next_pos;
                }
            }
        }

    }
    else {
        sort(A.begin(), A.end(), greater<ll>());
        rep(i,K) ans *= A[i];
    }

    cout << ans << endl;
}
