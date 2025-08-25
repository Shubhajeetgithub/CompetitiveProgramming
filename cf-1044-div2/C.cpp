#include<bits/stdc++.h>
using namespace std;
// Debug macro: only prints in LOCAL mode
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

void solve() {
    int n;
    cin >> n;
    if (n < 2) {
      return;
    }
    debug(n);
    int x;
    int max = -1, maxId = -1;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      cout << "? " << i << " " << n << " ";
      for (int j = 1; j <= n; j++) {
        cout << j;
        if (j != n) cout << " ";
      }
      cout << endl;
      fflush(stdout);
      cin >> x;
      if (x <= 0) return;
      debug(x);
      mp[i] = x;
      if (x > max) {
        max = x;
        maxId = i;
      }
      debug(i);
      debug(maxId);
    }
    if (max < 1) return;
    if (max == 1) {
      cout << "! 1 1\n";
      fflush(stdout);
      return;
    }
    else {
      vector<int> ans;
      ans.push_back(maxId);
      int j = maxId;
      int count = 0;
      while (count < max - 1) {
      for (int i = 1; i <= n; i++) {
        if (mp[i] == mp[j] - 1) {
          cout << "? " << j << " 2 "  << j << " " << i << endl;
          fflush(stdout);
          cin >> x;
          if (x <= 0) return;
          if (x == 2) {
            ans.push_back(i); 
            count++; 
            j = i;
            break;
          }

        }
      }
      }
      cout << "! " << ans.size();
      for (int a : ans) {
        cout << " " << a;
      }
      
      cout << endl;
      fflush(stdout);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    debug(t);
    while (t--) {
        solve();
    }
}
