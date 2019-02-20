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
    int n, a, b;
    cin >> n >> a >> b;
    int cnt[3] = {};
    rep(i, n) {
        int p;
        cin >> p;
        if (p <= a) cnt[0]++;
        else if (b+1 <= p) cnt[2]++;
        else cnt[1]++;
    }
    cout << *min_element(cnt, cnt+3) << endl;
}
