#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ {
    const T e = INF;
    // 最大値に修正
    function<T(T, T)> fx = [](T x1, T x2) -> T { return max(x1, x2); };
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ * 4, e) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the maximum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            // 見つからなければ-INF
            return -e;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    int find_rightest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    int find_leftest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};


vll X, Y;
void rec(ll i, ll last, ll x, ll y, vpll &v) {
    if (i == last) {
        v.push_back(pll(x, y));
        return;
    }
    rec(i+1, last, x, y, v);
    rec(i+1, last, x + X[i], y - Y[i], v);
    rec(i+1, last, x - X[i], y + Y[i], v);
}

int main() {
    ll N, D;
    cin >> N >> D;
    X.resize(N), Y.resize(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vpll L, R;
    rec(0, N/2, 0, 0, L);
    rec(N/2, N, 0, 0, R);
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int n = (int)L.size();
    RMQ<ll> rmq(n);
    rep(i, n) rmq.set(i, L[i].second);
    rmq.build();

    ll ans = 0;
    for(auto p : R) {
        ll x = p.first, y = p.second;
        ll l = lower_bound(L.begin(), L.end(), make_pair(-x-D, -(1ll<<60))) - L.begin();
        ll r = lower_bound(L.begin(), L.end(), make_pair(-x+D+1, -(1ll<<60))) - L.begin();
        if(0 <= l && r <= n && l < r) chmax(ans, y + rmq.query(l, r));
    }
    cout << ans << endl;
}
