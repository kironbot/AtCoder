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
typedef long long LL;

int main() {
    int n;
    int l[110];
    cin >> n;
    int lmax = 1, lsum = 0;
    for (int i = 0; i<n; i++) {
        int tmp;
        cin >> tmp;
        lmax = max(lmax, tmp);
        lsum += tmp;
    }
    if (lmax < lsum - lmax) cout << "Yes" << endl;
    else cout << "No" << endl;
}
