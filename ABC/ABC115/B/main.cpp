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
    cin >> n;
    int ans, pmax=0, sum=0;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pmax = max(tmp, pmax);
        sum += tmp;
    }
    ans = sum - pmax / 2;
    cout << ans << endl;
}
