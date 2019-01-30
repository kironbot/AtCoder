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
    for(int i=1; i<10; i++) {
        if(n <= i * 111) {
            cout << 111 * i << endl;
            break;
        }
    }
}
