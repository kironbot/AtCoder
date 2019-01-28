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
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({10 * a + b + c, a + 10 * b + c, a + b + 10 * c}) << endl;
}
