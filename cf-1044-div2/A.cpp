#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int count[101] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }
    for (int i = 2; i <= 100; i++) {
      if (count[i] > 1) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
        fflush(stdout);
    }
    return 0;
}



