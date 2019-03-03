#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> pos(n);
    for(int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;

    // すべてのiについてパリティが一致しているかチェック．一致していなければ-1．
    // 同時に，座標を45度回転させ(x+y, x-y)とする．後続処理でここに辿りつくステップを考える．
    int par = (abs(pos[0].first) + abs(pos[0].second)) % 2;
    for (int i = 0; i < n; i++) {
        int tmp = (abs(pos[i].first) + abs(pos[i].second)) % 2;
        pos[i] = pair<ll, ll>(pos[i].first + pos[i].second, pos[i].first - pos[i].second);
        if (tmp != par) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<ll> d;
    for(int i = 30; i >= 0; i--) d.emplace_back(1LL<<i);
    if (par % 2 == 0) d.emplace_back(1);
    cout << d.size() << endl;
    for (int j = 0; j < d.size(); j++) cout << d[j] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        int xdir, ydir;
        ll xsum = 0, ysum = 0;
        for (int j = 0; j < (int)d.size(); j++) {
            if (xsum <= pos[i].first) xdir = 1, xsum += d[j];
            else xdir = -1, xsum -= d[j];
            if (ysum <= pos[i].second) ydir = 1, ysum += d[j];
            else ydir = -1, ysum -= d[j];

            if (xdir == 1 && ydir == 1) cout << "R";
            else if (xdir == 1 && ydir == -1) cout << "U";
            else if (xdir == -1 && ydir == -1) cout << "L";
            else cout << "D";
        }
        cout << endl;
    }
}
