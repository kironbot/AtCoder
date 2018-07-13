#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<ll> A(N);
    vector<ll> sum_l2r(N), sum_r2l(N);

    vector<int> left_ix(N-1), right_ix(N-1);

    sum_l2r[0] = 0, sum_r2l[0] = 0;
    for (int i = 0; i<N; i++) {
        cin >> A[i];
        if (i > 0) {
            sum_l2r[i] += (sum_l2r[i-1] + A[i]);
        }
        else sum_l2r[i] = A[i];
    }
    for (int i = 0; i<N; i++) {
        if (i > 0) {
            sum_r2l[i] += (sum_r2l[i-1] + A[N-i-1]);
        }
        else sum_r2l[0] = A[N-1];
    }
    
    for (int mid_ix = 1; mid_ix < N-2; mid_ix++) {
        if (mid_ix > 1) {
            left_ix[mid_ix] = left_ix[mid_ix-1];

            ll left_diff = abs(sum_l2r[mid_ix] - 2*sum_l2r[left_ix[mid_ix-1]]);
            for (int ix = left_ix[mid_ix-1]+1; ix < mid_ix; ix++) {
                if (left_diff > abs(sum_l2r[mid_ix] - 2*sum_l2r[ix])) {
                    left_ix[mid_ix] = ix;
                    left_diff = abs(sum_l2r[mid_ix] - 2*sum_l2r[ix]);
                }
                else break;
            }

            right_ix[mid_ix] = right_ix[mid_ix-1];
            
            ll right_diff = abs(sum_r2l[mid_ix] - 2*sum_r2l[right_ix[mid_ix - 1]]);
            for (int ix = right_ix[mid_ix-1]+1; ix < mid_ix; ix++) {
                if (right_diff > abs(sum_r2l[mid_ix] - 2*sum_r2l[ix])) {
                    right_ix[mid_ix] = ix;
                    right_diff = abs(sum_r2l[mid_ix] - 2*sum_r2l[ix]);
                }
                else break;
            }
        }
        else {
            left_ix[1] = 0;
            right_ix[1] = 0;
        }
    }

    ll ans = 1e9 + 7;
    for (int mid_ix = 1; mid_ix < N-2; mid_ix++) {
        ll left_min = min(sum_l2r[mid_ix] - sum_l2r[left_ix[mid_ix]], sum_l2r[left_ix[mid_ix]]);
        ll left_max = max(sum_l2r[mid_ix] - sum_l2r[left_ix[mid_ix]], sum_l2r[left_ix[mid_ix]]);
        ll right_min = min(sum_r2l[N-2-mid_ix] - sum_r2l[right_ix[N-2-mid_ix]], sum_r2l[right_ix[N-2-mid_ix]]);
        ll right_max = max(sum_r2l[N-2-mid_ix] - sum_r2l[right_ix[N-2-mid_ix]], sum_r2l[right_ix[N-2-mid_ix]]);
        
        ans = min(max(left_max, right_max) - min(left_min, right_min), ans);
    }
    
    cout << ans << endl;
}
