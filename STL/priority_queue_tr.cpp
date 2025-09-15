// Compile with: g++ -std=c++17 priority_examples.cpp -O2
#include <bits/stdc++.h>
using namespace std;

/*
 Methods (priority_queue<T, Container, Compare>):
    push(x) / emplace(...)   // O(log n)
    pop()                    // O(log n)
    top()                    // O(1)
    size(), empty()          // O(1)
    swap(other)              // O(1)

 Notes:
    - default: priority_queue<T> is a max-heap (largest on top).
    - min-heap: priority_queue<T, vector<T>, greater<T>>.
    - For pairs/tuples, greater<> and less<> use lexicographical compare.
    - Can't iterate in sorted order without popping elements.
    - No built-in decrease-key (common pattern: push new value and ignore stale entries).
*/

// --------------- Example 1: Basic max-heap ---------------
void example_max_heap() {
    cout << "Example 1: max-heap\n";
    priority_queue<int> pq; // max-heap
    pq.push(5);
    pq.push(1);
    pq.push(8);
    cout << "top: " << pq.top() << "\n"; // 8
    pq.pop();
    cout << "after pop top: " << pq.top() << "\n"; // 5
    cout << "size: " << pq.size() << "\n\n";
}

// --------------- Example 2: min-heap ---------------
void example_min_heap() {
    cout << "Example 2: min-heap\n";
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(5);
    minpq.push(1);
    minpq.push(8);
    cout << "top (min): " << minpq.top() << "\n"; // 1
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n\n";
}

// --------------- Example 3: pairs (Dijkstra style) ---------------
void example_pairs_dijkstra_style() {
    cout << "Example 3: pairs (min-heap) for Dijkstra style\n";
    // pair<dist, node>, min-heap by dist using greater<>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({10, 2});
    pq.push({5, 1});
    pq.push({7, 3});
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        cout << "dist=" << d << " node=" << node << "\n";
    }
    cout << "\n";
}

// --------------- Example 4: custom comparator ---------------
struct Cmp {
    // min-heap by .first (smaller .first has higher priority)
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.first > b.first; // same behavior as greater<pair<int,int>>
    }
};
void example_custom_cmp() {
    cout << "Example 4: custom comparator\n";
    priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pq;
    pq.push({4, 10});
    pq.push({2, 20});
    pq.push({4, 15});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n\n";
}

// --------------- Example 5: Top-K largest elements ---------------
vector<int> topK_largest(const vector<int>& a, int k) {
    // keep a min-heap of size k
    priority_queue<int, vector<int>, greater<int>> minpq;
    for (int x : a) {
        if ((int)minpq.size() < k) minpq.push(x);
        else if (x > minpq.top()) {
            minpq.pop();
            minpq.push(x);
        }
    }
    vector<int> res;
    while (!minpq.empty()) { res.push_back(minpq.top()); minpq.pop(); }
    // res is ascending (smallest of top-k first), we may reverse if want descending
    reverse(res.begin(), res.end()); // now descending (largest first)
    return res;
}

// --------------- Example 6: Merge K sorted arrays ---------------
vector<int> merge_k_sorted(const vector<vector<int>>& lists) {
    // min-heap of tuple (value, list_index, element_index)
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    int k = lists.size();
    for (int i = 0; i < k; ++i) {
        if (!lists[i].empty()) pq.emplace(lists[i][0], i, 0);
    }
    vector<int> result;
    while (!pq.empty()) {
        auto [val, li, idx] = pq.top(); pq.pop();
        result.push_back(val);
        if (idx + 1 < (int)lists[li].size()) {
            pq.emplace(lists[li][idx+1], li, idx+1);
        }
    }
    return result;
}

// --------------- Example 7: make_heap / push_heap / pop_heap ---------------
void example_make_push_pop_heap() {
    cout << "Example 7: make_heap / push_heap / pop_heap (vector-based)\n";
    vector<int> v = {3, 1, 4, 1, 5};
    // make_heap creates a max-heap on v (largest at v.front())
    make_heap(v.begin(), v.end()); // default comparator = less<>
    cout << "heap top (v[0]) = " << v.front() << "\n"; // largest
    // push a new element: push_back then push_heap
    v.push_back(9);
    push_heap(v.begin(), v.end());
    cout << "after push_heap top = " << v.front() << "\n"; // now 9
    // pop top: pop_heap moves largest to end, then pop_back to remove
    pop_heap(v.begin(), v.end());
    cout << "after pop_heap moved element = " << v.back() << "\n";
    v.pop_back();
    cout << "remaining heap top = " << v.front() << "\n\n";
}

int main() {
    example_max_heap();
    example_min_heap();
    example_pairs_dijkstra_style();
    example_custom_cmp();

    // Top-K demo
    vector<int> arr = {5,1,9,3,14,7,8};
    int k = 3;
    auto topk = topK_largest(arr, k);
    cout << "Top " << k << " largest: ";
    for (int x : topk) cout << x << " ";
    cout << "\n\n";

    // Merge K sorted arrays demo
    vector<vector<int>> lists = {
        {1,4,7},
        {2,5,6},
        {3,8,9}
    };
    auto merged = merge_k_sorted(lists);
    cout << "Merged K sorted arrays: ";
    for (int x : merged) cout << x << " ";
    cout << "\n\n";

    example_make_push_pop_heap();

    // Quick summary
    cout << "Complexity summary:\n";
    cout << " push/pop: O(log n), top: O(1)\n";
    cout << " Use min-heap via greater<T> or custom comparator\n";
    cout << " Common uses: Dijkstra, Prim, top-K, merge K lists, scheduling tasks\n";

    return 0;
}
