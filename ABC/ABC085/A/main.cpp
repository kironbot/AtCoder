#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    cout << "2018" + s.substr(4, s.size()-4) << endl;
}
