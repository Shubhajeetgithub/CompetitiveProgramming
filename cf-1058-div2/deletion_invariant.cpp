/*
https://codeforces.com/problemset/problem/1917/B
observation based. 
Observe that when you perform k deletions, the last n-k-1 digits remain the same 
and their is a choice of selecting 1 digit from the first k+1 digits.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s;
        cin >> s;
        bool present[128] = {false};
        vector<int> distinct_cnt(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!present[(int)s[i]]) {
                present[(int)s[i]] = true;
                cnt++;
            }
            distinct_cnt[i] = cnt;
        }
        ll ans = 1; // no deletion at all
        for (int k = 1; k <= n-1; k++) {
            ans += (ll)distinct_cnt[k];
        }
        cout << ans << endl;

    }
    return 0;
}