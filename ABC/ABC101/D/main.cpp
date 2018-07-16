#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

ll S(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    ll K;
    cin >> K;
    vector<ll> ans; 
    for (ll i = 0; i <= 15; i++) {
        for (ll j = 1; j <= 1000; j++) {
            if (i == 0 && j == 1) continue;
            ll tmp = j * pow(10ll, i) - 1;
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    for (ll i = 0; i < ans.size(); i++) {
        for (int j = i + 1; j < ans.size(); j++) {
            if ((long double) ans[i] / S(ans[i]) > (long double)ans[j] / S(ans[j])) {
                ans.erase(ans.begin() + i);
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }
}
