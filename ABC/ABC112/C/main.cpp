#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n;
    cin >> n;
    vector<ll> vx(n), vy(n), vh(n);
    for (int i = 0; i < n; i++) {
        cin >> vx[i] >> vy[i] >> vh[i];
    }
    ll resx=-1, resy=-1, resh=-1;
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            ll h;
            for (int i = 0; i < n; i++) {
                if (vh[i] > 0) {
                    h = vh[i] + abs(vx[i] - x) + abs(vy[i] - y);
                    break;
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (vh[i] > 0 && vh[i] != h - abs(vx[i] - x) - abs(vy[i] - y)) ok = false;
                if (vh[i] == 0 && 0 < h - abs(vx[i] - x) - abs(vy[i] - y)) ok = false;
            }
            if (ok) {
                resx = x, resy = y, resh = h;
                cout << resx << " " << resy << " " << resh << endl;
                return 0;
            }
        }
    }
}
