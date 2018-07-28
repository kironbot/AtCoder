#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], sum=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum - n << endl;
}
