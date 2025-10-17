/*
https://codeforces.com/problemset/problem/1832/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    else if (n == 2) {
        if (a[0] == a[1]) {
            cout << 1 << endl;
            return;
        }
        else {
            cout << 2 << endl;
            return;
        }
    }
    int cnt = 1;
    int x = 0;
    while (x < n) {
        int y = x + 1;
        while (y < n && a[y] == a[x]) y++;
        if (y == n) {
            cout << cnt << endl;
            return;
        }
        bool increasing = a[y] > a[x];
        while (y + 1 < n && 
               ((increasing && a[y + 1] >= a[y]) || (!increasing && a[y + 1] <= a[y]))) {
            y++;
        }
        cnt++;
        x = y;
    }
    cout << cnt << endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}