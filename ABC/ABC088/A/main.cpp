#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    int mod = N % 500;

    if (A >= mod) cout << "Yes" << endl;
    else cout << "No" << endl;
}
