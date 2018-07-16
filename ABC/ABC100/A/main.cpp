#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (max(A, B) <= 8) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}
