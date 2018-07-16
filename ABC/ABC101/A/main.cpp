#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    string S;
    cin >> S;

    int res = 0;
    for (int i=0; i<4; i++) {
        if (S[i] == '+') res++;
        else res--;
    }
    
    cout << res << endl;

}
