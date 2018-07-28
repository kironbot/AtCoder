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
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << min({abs(a1-a2)+abs(a2-a3), abs(a2-a3) + abs(a3-a1), abs(a1-a3)+abs(a1-a2)}) << endl;
}
