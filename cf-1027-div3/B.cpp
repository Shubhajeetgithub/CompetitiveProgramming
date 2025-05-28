#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    int countFreq[2] = {0};
    for (char c : s) {
        int id = c - '0';
        countFreq[id]++;
    }
    int a = countFreq[0];
    int b = countFreq[1];
    if (a >= (n/2) - k && (a + k - n/2) % 2 == 0 && b >= (n/2) - k && (b + k - n/2) % 2 == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
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