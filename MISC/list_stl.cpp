#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        list<int> positive, negative;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 0) b.push_back(0);
            else if (x > 0) positive.push_back(x);
            else negative.push_back(x);
        }
        int prefSum = 0;
        if (positive.empty() && negative.empty()) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            while (!positive.empty() || !negative.empty()) {
                if (prefSum >= 0) {
                    auto it = negative.begin();
                    b.push_back(*it);
                    prefSum += (*it);
                    negative.erase(it);
                }
                else {
                    auto it = positive.begin();
                    b.push_back(*it);
                    prefSum += (*it);
                    positive.erase(it);
                }
            }
            for (int i = 0; i < n; i++) cout << b[i] << " ";
            cout << endl;
        }
    }
    return 0;
}