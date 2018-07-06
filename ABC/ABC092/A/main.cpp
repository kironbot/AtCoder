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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << min(A, B) + min(C, D) << endl;
}
