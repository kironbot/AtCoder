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

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();

    for (ll i = n-m; i >= 0; i--) {
        string u = s.substr(i, m);
        bool ok = true;
        for (ll j = 0; j < m; j++) {
            if (u[j] != '?' && u[j] != t[j]) ok = false;
        }
        if (ok) {
            for (ll k = 0; k < n; k++) {
                if (i <= k && k <= i+m-1) cout << t[k-i];
                else if (s[k] == '?') cout << 'a';
                else cout << s[k];
            }
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}
