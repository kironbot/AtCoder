#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B;
    string S;
    cin >> A >> B;
    cin >> S;
    
    for (int i=0; i<S.size(); i++) {
        if (i != A && S[i] == '-') {
            cout << "No" << endl;
            return 0;
        }
        else if (i == A && S[i] != '-'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
