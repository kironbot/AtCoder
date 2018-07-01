#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    if (a <= b) {
        cout << a << endl;
    }
    else {
        cout << max(1, a-1) << endl;
    }

}
