#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0; i < 4; i++) {
        int digit = s[i] - '0';
        num = num * 10 + digit;
    }
    int root = (int)sqrt(num);
    if (root * root != num) {
        cout << -1 << endl;
        return;
    }
    cout << 0 << " " << root << endl;
    return;
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt; while (tt--) {
        solve();
        fflush(stdout);
    }
    return 0;
}