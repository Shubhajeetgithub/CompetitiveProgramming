#include <iostream>
#include <string>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;
        std::string s; std::cin >> s;

        std::vector<int> ids;
        for (int i = 0; i < n; i += k) ids.push_back(i);
        bool check = true;
        int cnt1_tot = 0, cnt0_tot = 0;
        for (int i = 0; i < k; i++) {
            int cnt1 = 0, cnt0 = 0;
            for (int id: ids) {
                if (id + i < n) {
                    if (s[id+i] == '0') cnt0++;
                    else if (s[id+i] == '1') cnt1++;
                }
            }
            if (cnt1 > 0 && cnt0 > 0) {
                check = false;
                break;
            }
            else {
                if (cnt0 == 0 && cnt1 > 0) cnt1_tot++;
                else if (cnt1 == 0 && cnt0 > 0) cnt0_tot++;
            }
        }
        if (cnt1_tot > k/2 || cnt0_tot > k/2) check = false;
        if (check) {
            std::cout << "YES\n";
        }
        else std::cout << "NO\n";
    }
    return 0;
}