#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, 0, m) cin >> a[i] >> b[i], a[i]--, b[i]--;

    UnionFind uf(n);
    ll cur = n * (n-1) / 2;
    vector<ll> ans;
    rep(i, 0, m) {
        ans.push_back(cur);

        int ta = a[m-1-i], tb = b[m-1-i];
        if (uf.issame(ta, tb)) continue;

        ll sa = uf.size(ta), sb = uf.size(tb);
        cur -= sa * sb;
        uf.merge(ta, tb);
    }
    for (int i = m-1; i >= 0; i--) cout << ans[i] << endl;
}