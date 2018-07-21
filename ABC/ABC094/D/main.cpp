#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    
    sort(a, a+n);

    ll A = a[n-1];
    ll B = a[0];
    double diff = (double)(A/2);
    for (int i=0; i<n; i++) {
        if (diff > abs(((double)A/2 - a[i]))) {
            B = a[i];
            diff = abs(((double)A/2 - a[i]));
        }
    }
    cout << A << " " << B << endl;
}
