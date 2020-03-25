#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N), S(N);
    rep(i, N) cin >> H[i] >> S[i];

    // right以下でクリアできるか？を二分探索でチェック
    ll left = 0, right = INF;
    while(right - left > 1) {
        ll mid = (left + right) / 2;

        bool ok = true;
        vector<ll> t(N, 0);
        rep(i, N) {
            if (mid < H[i]) ok = false;
            else t[i] = (mid - H[i]) / S[i]; // 残りの使用できる時間
        }

        sort(t.begin(), t.end());
        // 時間が厳しい順に打ち落とす。無理になったらfalse
        rep(i, N) if(t[i] < i) ok = false;
        if(ok) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
