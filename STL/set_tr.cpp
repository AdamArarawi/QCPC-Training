#include <bits/stdc++.h>
using namespace std;

int main() {
    // ============================================================
    // SET
    // مجموعة مرتبة (tree-based), عناصرها فريدة
    // العمليات الأساسية O(log n)
    // ============================================================

    /*
        Methods:
            insert(x)             // O(log n)
            erase(key)            // O(log n) يمسح عنصر بالقيمة
            erase(it)             // O(log n) يمسح بالـ iterator
            find(key)             // O(log n) -> iterator أو end()
            count(key)            // O(log n) -> يرجع 0 أو 1 فقط (فريدة)
            size(), empty()       // O(1)
            begin(), end()        // O(1)
            rbegin(), rend()      // O(1)
            clear()               // O(n)
            lower_bound(x)        // O(log n) أول عنصر >= x
            upper_bound(x)        // O(log n) أول عنصر > x
            swap(other)           // O(1)
            merge(other_set)      // O(n) يحرك العقد بدون نسخ (C++17)
    */

    set<int> s;

    // إدخال
    s.insert(5);
    s.insert(2);
    s.insert(8);

    // البحث
    if (s.find(2) != s.end()) cout << "set: found 2\n";

    // أصغر وأكبر عنصر
    cout << "set: smallest = " << *s.begin() << "\n";
    cout << "set: largest = " << *s.rbegin() << "\n";

    // lower_bound / upper_bound
    auto it1 = s.lower_bound(6); // أول عنصر >= 6
    if (it1 != s.end()) cout << "set: lower_bound(6) = " << *it1 << "\n";

    auto it2 = s.upper_bound(5); // أول عنصر > 5
    if (it2 != s.end()) cout << "set: upper_bound(5) = " << *it2 << "\n";

    // حذف بالـ key
    s.erase(2);

    // حذف أثناء التكرار (الطريقة الآمنة)
    for (auto it = s.begin(); it != s.end(); ) {
        if (*it % 2 == 0) {
            auto toErase = it++;
            s.erase(toErase);
        } else {
            ++it;
        }
    }

    // ترتيب تنازلي
    set<int, greater<int>> desc;
    desc.insert(1);
    desc.insert(3);
    desc.insert(2);
    cout << "desc order set: ";
    for (auto x : desc) cout << x << " ";
    cout << "\n";

    // set of pairs
    set<pair<int,int>> st;
    st.insert({2, 100});
    st.insert({2, 50});
    st.insert({1, 10});
    cout << "set of pairs:\n";
    for (auto [a, b] : st) cout << "(" << a << "," << b << ") ";
    cout << "\n\n";

    // ============================================================
    // MULTISET
    // مثل set لكن يسمح بالتكرار، برضه O(log n)
    // ============================================================
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(2);
    ms.insert(8);

    cout << "multiset elements: ";
    for (auto x : ms) cout << x << " ";
    cout << "\n";

    cout << "count(5) in multiset = " << ms.count(5) << "\n";

    // erase يمسح جميع النسخ
    ms.erase(5);
    cout << "after erase(5), multiset: ";
    for (auto x : ms) cout << x << " ";
    cout << "\n\n";

    // ============================================================
    // UNORDERED_SET
    // مبني على hash table, غير مرتب, متوسط O(1)
    // ============================================================
    unordered_set<int> us;
    us.insert(5);
    us.insert(2);
    us.insert(8);
    us.insert(2); // تجاهل لأنه مكرر

    cout << "unordered_set elements: ";
    for (auto x : us) cout << x << " ";
    cout << "\n";

    if (us.find(8) != us.end()) cout << "unordered_set: found 8\n";
    cout << "unordered_set size = " << us.size() << "\n\n";

    // ============================================================
    // COMPARISON SUMMARY
    // ============================================================
    cout << "Summary:\n";
    cout << "set        -> عناصر فريدة مرتبة, O(log n)\n";
    cout << "multiset   -> يسمح بالتكرار, مرتبة, O(log n)\n";
    cout << "unordered_set -> عناصر فريدة غير مرتبة, متوسط O(1)\n";

    return 0;
}
