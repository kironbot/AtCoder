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
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> even(100010, 0), odd(100010, 0); 
    for (ll i = 0; i < n; i++) {
        ll v;
        cin >> v;
        if (i % 2 == 0) even[v]++;
        else odd[v]++;
    }

    vector<pair<ll, ll>> pe, po;
    for (ll i = 1; i <= 100010; i++) {
        pe.push_back(make_pair(even[i], i));
        po.push_back(make_pair(odd[i], i));
    }
    sort(pe.begin(), pe.end(), greater<pair<ll, ll>>());
    sort(po.begin(), po.end(), greater<pair<ll, ll>>());

    ll ans;
    if (pe[0].second != po[0].second) ans = n - pe[0].first - po[0].first;
    else ans = min(n - pe[0].first - po[1].first, n - pe[1].first - po[0].first);

    cout << ans << endl;
}