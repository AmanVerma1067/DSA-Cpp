# DSA Playbook — Maps & Data Structures (Compact, Contest-Focused)

🎉 **Nice — you were close. Sorting was the right idea; maps were the missing piece.**

Below is a compact, practical playbook you can keep as a reference. It's hands-on and focused on contest/exam usage.

# 1) Quick overview

- **What you’ll get:**
  1. Prioritized list of must-know data structures
  2. When & why to use each (complexities included)
  3. C++ usage tips & short snippets (including `map` / `unordered_map`)
  4. Problem patterns & thinking tricks
  5. Practice roadmap & next steps

---

# 2) Must-know data structures (priority order)

🔰 **Essential (learn cold)**

- **Hash map — `unordered_map<T,U>`**
  - Use: frequency, index mapping, coordinate compression.
  - Complexity: Average O(1) per op (worst-case O(n) rare).
  - Typical: `unordered_map<int,int> mp; mp[x]++; mp.find(x);`

- **Ordered map — `map<T,U>`**
  - Use: ordered keys, `lower_bound`/`upper_bound`, predecessor/successor.
  - Complexity: O(log n).
  - Typical: `map<int,int> m; auto it = m.lower_bound(x);`

- **`vector` / array** — contiguous storage, prefix sums, two-pointer.

- **`set` / `multiset`** — sorted multiset operations, arbitrary deletion. O(log n).

- **Priority queue (heap)**
  - Use: greedy tasks, K-th largest, Dijkstra.
  - `priority_queue<int>` or min-heap: `priority_queue<int,vector<int>,greater<int>>`

- **Deque** — sliding window techniques (monotonic deque), O(1) both ends.

- **DSU (Union-Find)** — components, Kruskal, grouping. ~O(α(n)).

- **Fenwick Tree (BIT)** — prefix sums with updates. O(log n).

- **Segment Tree** — range queries/updates, lazy propagation. O(log n).

- **Trie** — strings, prefix queries, bitwise trie for xor-max.


💡 **Very useful / advanced (learn later)**

- PBDS (ordered set with `order_of_key`, `find_by_order`) — order-statistics.
- Treap / Splay / implicit treap — split/merge, sequence operations.
- Suffix structures, rolling-hash, 2D BIT / Segment Tree, flow algorithms (Dinic/Hopcroft-Karp).
- Contest tools: Mo’s algorithm, HLD, centroid decomposition, FFT/NTT.

---

# 3) C++ snippets & tips (maps + example)

### Map vs `unordered_map` — quick rule
- Use `unordered_map` for speed when order doesn’t matter.
- Use `map` when key order or range queries (`lower_bound`) are needed.

```cpp
#include <bits/stdc++.h>
using namespace std;

// unordered_map example
unordered_map<int,int> freq;
for (int x : nums) freq[x]++;
if (freq.find(val) != freq.end()) { /* exists */ }

// fast I/O
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

### Sorting + map to restore original order (your earlier idea)

```cpp
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    unordered_map<int,int> firstPos; // value -> count of strictly smaller
    for (int i = 0; i < n; ++i) {
        if (firstPos.find(sorted[i]) == firstPos.end())
            firstPos[sorted[i]] = i; // i numbers are strictly smaller
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = firstPos[nums[i]];
    return ans;
}
```

### Defensive habits
- Use `int n = nums.size();` to avoid signed/unsigned pitfalls.
- Use `long long` for large sums.
- Reserve unordered_map size when big: `mp.reserve(1<<10);` before inserts.

---

# 4) Problem patterns — quick decision flow

Ask these in order when you see a problem:

1. **Does order matter?**
   - No → sorting / freq array.
2. **Is value range small?**
   - Yes → counting sort / freq array.
3. **Do I need `lower_bound`/order queries?**
   - Yes → `map` / segment tree.
4. **Need quick insertion + random removal + median?**
   - Use PBDS / two-heaps / balanced BST.
5. **Offline heavy queries?**
   - Mo’s algorithm.
6. **Connectivity/grouping?**
   - DSU.
7. **Path or range queries?**
   - Fenwick / Segment Tree.
8. **Combine intervals or lazy range ops?**
   - Segment Tree + lazy.

---

# 5) Mental habits / competitor tricks

- **Preprocess once, answer many** — prefix sums, frequency maps.
- **Transform** problems (reduce to counting/prefix sums).
- **Use index as info** — map value → index, reconstruct order.
- **Coordinate compression** when values are huge.
- **Two pointers on sorted** arrays for sum/pair problems.
- **Binary search on answer** for feasibility problems.
- **Sliding window**: fixed or variable window with deque or two pointers.
- **Use invariants** and memoize where possible.
- **Always test edge cases**: tiny n, all-equal, extremes.

---

# 6) Must-practice algorithm templates (copy & reuse)

- DSU (path compression + union by rank)
- Fenwick tree (point update, prefix query)
- Segment tree (+ lazy)
- Dijkstra (priority_queue)
- Topological sort (Kahn)
- Binary search template (index & predicate)
- BFS/DFS variants (multi-source, level order)
- KMP / Z / rolling hash; Trie for strings
- Two heaps for median maintenance

---

# 7) Debugging & performance tips

- Prefer `unordered_map` for speed; if TLE, check hash behavior and reserve size.
- Avoid repeated `.size()` in loops. Store it in `n`.
- Use `ios::sync_with_stdio(false); cin.tie(nullptr);`.
- When TLE, re-evaluate complexity and constant factors (log vs constant-time).
- Watch off-by-one and index bounds.

---

# 8) Learning roadmap (what to practice next)

1. **Immediate (2 weeks):** `unordered_map`, `map`, `set`, `multiset`, `priority_queue`, `deque`.
   - Practice: frequency counting, kth element, sliding-window.
2. **Mid (3–4 weeks):** Fenwick & Segment Tree. Solve range sum / update problems.
3. **Graph/DSU:** MST & connectivity problems.
4. **Strings:** Trie + KMP, rolling hash.
5. **PBDS & order-statistics.**
6. **Advanced:** HLD, Centroid, Mo’s, FFT (deep dives as needed).

---

# 9) Suggested follow-ups I can make for you

- ✅ One-page **printable cheat-sheet** (APIs + templates)
- ✅ 3 example problems solved step-by-step (maps / Fenwick)
- ✅ Convert sorting idea to mapping pattern for other problems

Tell me which one you want and I’ll prepare it next.

---

*Saved as a compact contest-focused playbook — keep it open while you practice.* 💪✨

