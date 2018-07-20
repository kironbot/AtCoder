#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {    
    ll N, C;
    cin >> N >> C;

    ll x[N], v[N];
    for (int i=0; i<N; i++){
        cin >> x[i] >> v[i];
    }

    ll rsum[N+10], lsum[N+10], vr=0, vl=0;
    rsum[0] = 0;
    lsum[0] = 0;
    for (int i=0; i<N; i++){
        vr += v[i];
        rsum[i+1] = max(rsum[i], vr-x[i]);
        vl += v[N-i-1];
        lsum[i+1] = max(lsum[i], vl-(C-x[N-i-1]));
    }
    
    ll ans=0;
    for (int i=0; i<N; i++){
        ll sum = rsum[i] + lsum[N-i];

        ll rcal = x[i-1];
        if (i == 0) rcal = 0;
        ll rans = sum - rcal;
        
        ll lcal = C - x[i];
        if (i == N) lcal = 0;
        ll lans = sum - lcal;

        ans = max({ans, rans, lans});
    }
    cout << ans << endl;
}
