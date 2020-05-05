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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

short fld[4200][4200];
vector<int> dx = {0, 0, 1, -1} , dy = {1, -1, 0, 0};
vector<int> wx, wy;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    vector<int> x1(n), x2(n), y1(n), y2(n);
    rep(i, n) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        wx.push_back(x1[i]);
        wx.push_back(x2[i]);
        wy.push_back(y1[i]);
        wy.push_back(y2[i]);

        int nx1 = x1[i] - 1, nx2 = x2[i] + 1;
        if(0 <= nx1 && nx1 < w) wx.push_back(nx1);
        if(0 <= nx2 && nx2 < w) wx.push_back(nx2);
        int ny1 = y1[i] - 1, ny2 = y2[i] + 1;
        if(0 <= ny1 && ny1 < h) wy.push_back(ny1);
        if(0 <= ny2 && ny2 < h) wy.push_back(ny2);
    }
    sort(wx.begin(), wx.end());
    sort(wy.begin(), wy.end());
    wx.erase(unique(wx.begin(), wx.end()), wx.end());
    wy.erase(unique(wy.begin(), wy.end()), wy.end());

    rep(i, n) {
        x1[i] = find(wx.begin(), wx.end(), x1[i]) - wx.begin();
        x2[i] = find(wx.begin(), wx.end(), x2[i]) - wx.begin();
        y1[i] = find(wy.begin(), wy.end(), y1[i]) - wy.begin();
        y2[i] = find(wy.begin(), wy.end(), y2[i]) - wy.begin();
    }
    ll nw = wx.size(), nh = wy.size();

    rep(i, n) fld[y1[i]][x1[i]]++, fld[y2[i]][x1[i]]--, fld[y1[i]][x2[i]]--, fld[y2[i]][x2[i]]++;
    rep(i, 4100) rep(j, 4100) fld[i][j+1] += fld[i][j];
    rep(i, 4100) rep(j, 4100) fld[i+1][j] += fld[i][j];
    rep(i, nh) fld[i][nw-1] = 1;
    rep(i, nw) fld[nh-1][i] = 1;

    ll ans = 0;
    rep(y, nh) rep(x, nw) {
        if (fld[y][x] >= 1) continue;
        ans++;

        queue<pll> que;
        que.emplace(x, y);
        while(!que.empty()) {
            ll sx = que.front().first, sy = que.front().second;
            que.pop();

            rep(i, 4) {
                ll nx = sx + dx[i], ny = sy + dy[i];
                if(nx < 0 || nw <= nx || ny < 0 || nh <= ny) continue;
                if(fld[ny][nx] >= 1) continue;
                que.emplace(nx, ny);
                fld[ny][nx] = 1;
            }
        }
    }
    cout << ans << endl;
}
