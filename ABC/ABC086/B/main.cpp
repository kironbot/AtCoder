#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
  
    string s;
    s = to_string(a) + to_string(b);
    int n = stoi(s);

    for (int i=1; i<n; i++) {
        if (i * i == n) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
