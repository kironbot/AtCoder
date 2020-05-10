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

/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,fp,ex,em): モノイド(集合X, 二項演算fx,fa,fm,fp
   単位元ex,em)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazyProportional(int n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_, M em_)
        : n(), fx(fx_), fa(fa_), fm(fm_), fp(fp_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(int k, int len) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main() {
    int q, k;
    cin >> q >> k;

    vector<tuple<ll, ll, ll>> vec;
    map<ll, ll> mp, mp2;

    rep(i, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int d, a;
            cin >> d >> a;
            vec.emplace_back(c, d, a);
            mp[d] = 0;
        } else {
            int d;
            cin >> d;
            vec.emplace_back(c, d, 0);
            mp[d] = 0;
        }
    }
    ll cnt = 0;
    mp[0] = 0;
    for(auto& x : mp) x.second = cnt, cnt++;
    for(auto& x : mp) mp2[x.second] = x.first;

    ll n = cnt;
    using X = pll;
    using M = pll;
    auto fx = [](X x1, X x2) -> X { return pll(x1.first + x2.first, max(x1.second + x2.first, x2.second)); };
    auto fa = [](X x, M m) -> X { return pll(x.first + m.first, max(x.second + m.first, m.second)); };
    auto fm = [](M m1, M m2) -> M { return pll(m1.first + m2.first, max(m1.second + m2.first, m2.second)); };
    auto fp = [](M m, long long n) -> M { return m; };
    X ex = pll(0, 0);
    M em = pll(0, 0);
    SegTreeLazyProportional <X, M> rmq(n, fx, fa, fm, fp, ex, em);

    for(ll i = 1; i < n; i++) rmq.set(i, pll(k * (mp2[i] - mp2[i-1]), 0));
    rmq.build();

    rep(i, q) {
        ll c = get<0>(vec[i]), d = get<1>(vec[i]), a = get<2>(vec[i]);

        if(c == 1) {
            rmq.update(mp[d], mp[d]+1, pll(-a, 0));
        } else {
            auto p = rmq.query(0, mp[d]+1);
            cout << k*d - max(p.first, p.second) << endl;
        }
    }
}