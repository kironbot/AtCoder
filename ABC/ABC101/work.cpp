#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int N;
    cin >> N;
    for (int n = 3; n < N; n++) {
        for (int k = 3; k < n; k++) {
            int res1, res2;
            res1 = (n - 2) / (k - 1) + 1;
            res2 = (n - k) / (k - 1) + 2;
            if (res1 != res2) cout << "n= " << n << ", k= " << k << ", res1= " << res1 << ", res2= " << res2 << endl;
        }
    }

}
