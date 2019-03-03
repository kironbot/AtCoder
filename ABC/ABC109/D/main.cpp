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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W, 0));
    int odd = 0;
    rep(i, 0, H) rep(j, 0, W) {
        cin >> a[i][j];
        if (a[i][j] & 1) odd++;
    }
    vector<tuple<int, int, int, int>> ans;
    int num = 0, x = 0, y = 0;
    rep(iter, 0, W*H) {
        if (a[x][y] & 1) num++;

        int nx = x, ny = y;
        if(x % 2 == 0) {
            if (ny == W-1) nx++;
            else ny++;
        }
        else {
            if (ny == 0) nx++;
            else ny--;
        }
        if (num & 1) if (num < odd) ans.emplace_back(x+1, y+1, nx+1, ny+1);
        x = nx, y = ny;
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        int a, b, c, d;
        tie(a, b, c, d) = p;
        cout << a << " " << b << " " << c << " " << d << endl;
    }
}
