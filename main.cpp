#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    map<int,int> intervals; // start -> end, non‑overlapping
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            // Find first interval with start > r
            auto it = intervals.lower_bound(l);
            // Check possible overlap with previous interval
            if (it != intervals.begin()) {
                auto prev = std::prev(it);
                if (prev->second >= l) {
                    it = prev; // start erasing from prev
                }
            }
            int removed = 0;
            // Erase all intervals that intersect [l, r]
            while (it != intervals.end() && it->first <= r) {
                ++removed;
                it = intervals.erase(it);
            }
            // Insert the new interval
            intervals[l] = r;
            cout << removed << "\n";
        } else if (op == 'B') {
            cout << intervals.size() << "\n";
        }
    }
    return 0;
}

