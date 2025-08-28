#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        for (char c : s) {
            if (c == '1') {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> a(n);
    int start = 1, end = n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t < k-1) {
            a[i] = start++;
            t++;
        }
        else if (s[i] == '1' && t == k-1) {
            cout << "NO\n";
            return;
        }
        else {
            t = 0;
            a[i] = end--;
        }
    }
    cout << "YES\n";
    for (int i : a) cout << i << " ";
    cout << endl;
    return;
    
    
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