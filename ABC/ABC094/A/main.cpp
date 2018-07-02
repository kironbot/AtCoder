#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B, X;
    cin >> A >> B >> X;

    if (A <= X && X <= A+B) cout << "YES" << endl;
    else cout << "NO" << endl;
}
