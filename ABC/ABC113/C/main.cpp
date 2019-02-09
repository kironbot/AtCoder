#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n, m;
    cin >> n >> m;
    tuple<int, int, int> data[m]; // Y_i, P_i, i
    for (int i = 0; i < m; i++) {
        int p, y;
        cin >> p >> y;
        data[i] = make_tuple(y, p, i);
    }
    sort(data, data + m); // sort by Y_i
    int cnt[n + 1];
    fill(cnt, cnt + n + 1, 0);

    pair<int, int> id[m]; // P_i, order
    
    for (int i = 0; i < m; i++) {
        int y, p, idx;
        tie(y, p, idx) = data[i];
        cnt[p]++;
        id[idx] = make_pair(p, cnt[p]);
    }

    for (int i = 0; i < m; i++) {
        cout << setw(6) << setfill('0') << id[i].first;
        cout << setw(6) << setfill('0') << id[i].second << endl;
    }
}
