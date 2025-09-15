#include <bits/stdc++.h>
using namespace std;

int main () {
    // Vector
    // vector<int> v;              // فارغ
    // vector<int> v(5);           // 5 عناصر قيمتها 0
    // vector<int> v(5, 7);        // 5 عناصر كلها 7
    vector<int> v = {1,2,3,4};  // initializer list

    v.push_back(1);       // O(1) (أمورتايزد Amortized) ← أحيانًا O(n) عند إعادة التخصيص
    v.pop_back();         // O(1)

    v.insert(v.begin()+2, 99); // O(n) ← لأنه ممكن يحرك كل العناصر اللي بعد index=2
    v.erase(v.begin()+2);      // O(n) ← يحرك كل العناصر اللي بعد المحذوف
    v.clear();            // O(n) ← يمسح كل العناصر (لكن فعليًا بيصفر size فقط، capacity بتظل)

    v[0];                 // O(1)
    v.at(0);              // O(1)
    v.front();            // O(1)
    v.back();             // O(1)

    v.size();             // O(1)
    v.empty();            // O(1)
    v.capacity();         // O(1)
    v.resize(10);         // O(n) ← يضيف/يمسح عناصر حسب الفرق

    reverse(v.begin(), v.end());   // O(n)
    sort(v.begin(), v.end());      // O(n log n)
    sort(v.rbegin(), v.rend());    // O(n log n)

    
    /*
        Questions
    */


    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    reverse(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()));

    return 0;
}