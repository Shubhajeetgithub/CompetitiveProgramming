#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<deque<int>> occ(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, 0);
    if (a[0] == 1) {
        dp[0] = 1;
    } else {
        occ[a[0]].push_back(0);
    }
    for (int i = 1; i < n; i++) {
        occ[a[i]].push_back(i);
        if (a[i] == 1) dp[i] = 1 + dp[i-1];
        else if (occ[a[i]].size() == a[i]) {
            int index = occ[a[i]].front();
            int added = (index > 0) ? dp[index-1] : 0;
            if (a[i] + added > dp[i-1]) {
                dp[i] = a[i] + added;
            } else {
                dp[i] = dp[i-1];
            }
        } else if (occ[a[i]].size() > a[i]) {
            int index = occ[a[i]][occ[a[i]].size() - a[i]];
            int added = (index > 0) ? dp[index-1] : 0;
            if (added + a[i] > dp[i-1]) dp[i] = added + a[i];
            else dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1];
    }
    
    cout << dp[n-1] << endl;
    
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