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
    ll n;
    cin >> n;
    vector<ll> prime;
    for (int i = 2; i <= n; i++) {
        bool ok = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) ok = false;
        }
        if (ok) prime.push_back(i);
    }
    map<ll, ll> mp;
    for (auto i : prime) {
        ll cnt = 0;
        for (int j = 2; j <= n; j++) {
            ll tmp = j;
            while(tmp > 0) {
                if (tmp % i == 0) {
                    cnt++;
                    tmp /= i;
                }
                else break;
            }    
        }
        mp[i] = cnt;
    }
    vector<int> pn(5);
    for (auto i : prime) {
        if (mp[i] >= 74) pn[4]++, pn[3]++, pn[2]++, pn[1]++, pn[0]++;
        else if (mp[i] >= 24) pn[3]++, pn[2]++, pn[1]++, pn[0]++;
        else if (mp[i] >= 14) pn[2]++, pn[1]++, pn[0]++;
        else if (mp[i] >= 4) pn[1]++, pn[0]++;
        else if (mp[i] >= 2) pn[0]++;
    }
    int ans = pn[4] + max(0, pn[3] * (pn[0] - 1)) + max(0, pn[2] * (pn[1] - 1)) + max(0, (pn[1] * (pn[1] - 1)) / 2 * (pn[0] - 2));
    cout << ans << endl;
}
