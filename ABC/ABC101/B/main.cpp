#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int calcDigitSums (int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}



int main() {
    int N;
    cin >> N;

    if ((N % calcDigitSums(N)) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}
