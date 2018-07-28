#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
    int a, b;
    char x[110][110];
    
    cin >> a >> b;
    a--, b--;
    for(int i=1; i<=50; i++){
        for(int j=1; j<=100; j++){
            x[i][j] = '.';
        }
    }
    for(int i=51; i<=100; i++){
        for(int j=1; j<=100; j++){
            x[i][j] = '#';
        }
    }
    for(int i=1; i<=50 && b; i+=2){
        for(int j=1; j<=100 && b; j+=2){
            x[i][j] = '#';
            b--;
        }
    }
    for(int i=100; i>=51 && a; i-= 2){
        for(int j=1; j<=100 && a; j+=2){
            x[i][j] = '.';
            a--;
        }
    }
    
    cout << "100 100" << endl;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            cout << x[i][j];
        }
        cout << endl;
    } 
}
