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

int f(int n){
    ll s=0;
    while(n>0){
        s += n % 10;
        n /= 10;
    }
    return s;
}


int main() {
    int n;
    cin >> n;

    if(n % f(n) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
