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
#define irep(i, n) for (ll i = n-1; i >= 0; i--)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll T;
    cin >> T;
    rep(_, T) {
        ll N;
        cin >> N;
        vll K(N), L(N), R(N);
        vvll VL(N+1), VR(N+1);
        ll ans = 0;
        rep(i, N) {
            cin >> K[i] >> L[i] >> R[i];
            K[i]--;
            if(L[i] > R[i]) {
                ans += R[i];
                VL[K[i]].push_back(L[i]-R[i]);
            }
            else {
                ans += L[i];
                VR[K[i]].push_back(R[i]-L[i]);
            }
        }

        priority_queue<ll, vll, greater<ll>> pq1;
        rep(i, N) {
            for(auto x : VL[i]) pq1.push(x);
            while(i+1 < pq1.size()) pq1.pop();
        }
        while(!pq1.empty()) {
            ans += pq1.top();
            pq1.pop();
        }

        priority_queue<ll, vll, greater<ll>> pq2;
        irep(i, N) {
            for(auto x : VR[i]) pq2.push(x);
            while(N-1-i < pq2.size()) pq2.pop();
        }
        while(!pq2.empty()) {
            ans += pq2.top();
            pq2.pop();
        }

        cout << ans << endl;
    }
}
