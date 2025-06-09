#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    std::unordered_map<int, int> counts;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        counts[a[i]]++;
    }

    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    std::unordered_set<int> left_uniques;
    for(auto const& [val, count] : counts) {
        left_uniques.insert(val);
    }
    
   
    std::unordered_set<int> right_uniques;
    

    int segments = 1;

    for (int i = n - 1; i > 0; i--) {
        int element = a[i];

        right_uniques.insert(element);

        counts[element]--;

        if (counts[element] == 0) {
            left_uniques.erase(element);
        }

        
        bool can_partition = true;
        for (int val : left_uniques) {
            if (right_uniques.find(val) == right_uniques.end()) {
                can_partition = false;
                break;
            }
        }

        if (can_partition) {
            segments++;
            right_uniques.clear();
        }
    }

    std::cout << segments << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}