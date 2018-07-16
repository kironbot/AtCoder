#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << (b-a-1)*(b-a)/2 - a << endl;
}
