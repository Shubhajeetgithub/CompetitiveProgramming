#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int n1 = 0, n0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') n1++;
        else n0++;
    }
    int ans = (n-1) * n1 + n0;
    cout << ans << endl;
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