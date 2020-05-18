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
    int n;
    cin >> n;
    vector<pair<int, int>> red;
    vector<pair<int, int>> blue;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        red.push_back(p);
    }
    sort(red.begin(), red.end());

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        blue.push_back(p);
    }
    sort(blue.begin(), blue.end());
    
    int res = 0;
    for (int i=0; i<n; i++) {
        int num = -1;
        for (int j=0; red[j].first < blue[i].first && j < red.size(); j++) {
            if (num == -1 && red[j].second < blue[i].second) num = j;
            else if (num != -1 && red[num].second < red[j].second && red[j].second < blue[i].second) num = j;
        }
            if (red[num].first < blue[i].first && red[num].second < blue[i].second){
                res++;
                red.erase(red.begin() + num);
            }
    }

    cout << res << endl;
}
