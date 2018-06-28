#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    cout << max(A+B, max(A-B, A*B)) << endl;

}
