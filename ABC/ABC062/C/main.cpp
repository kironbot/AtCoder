#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll h, w;
    cin >> h >> w;

    ll sa, sb, sc, hb, hc, wb, wc;
    ll ans = INF;
    rep(ha, 1, h) {
        sa = ha * w;
        
        hb = (h-ha) / 2;
        sb = hb * w;
        hc = h - ha - hb;
        sc = hc * w;
        if (sb > 0 && sc > 0) chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
    
        wb = w / 2;
        sb = (h-ha) * wb;
        wc = w - wb;
        sc = (h-ha) * wc;
        if (sb > 0 && sc > 0) chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
    }

    rep(wa, 1, w) {
        sa = wa * h;

        wb = (w-wa) / 2;
        sb = h * wb; 
        wc = w - wa - wb;
        sc = h * wc;
        if (sb > 0 && sc > 0) chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
    
        hb = h / 2;
        sb = (w-wa) * hb;
        hc = h - hb;
        sc = (w-wa) * hc;
        if (sb > 0 && sc > 0) chmin(ans, max(sa, max(sb, sc)) - min(sa, min(sb, sc)));
    }
    cout << ans << endl;
}
