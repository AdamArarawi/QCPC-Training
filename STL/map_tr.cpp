#include <bits/stdc++.h>
using namespace std;

int main () {
    // Map
    /*
        العمليات الأساسية (إضافة، بحث، حذف): O(log n).
    */

    map<string,int> age;
    age["Ali"] = 20;
    age["Omar"] = 25;
    cout << age["Ali"]; // 20


    /*
        Types:
            1- map:
                مفاتيح مرتبة تصاعديًا افتراضيًا.

                العمليات: O(log n).

                استخدامه ممتاز لو بدك دايمًا تطلع على العناصر بالترتيب.

            2- unordered_map
                مبني على Hash Table.

                مفاتيح غير مرتبة.

                العمليات المتوسطة: O(1)، لكن أسوأ حالة O(n).

                ممتاز للـ frequency count أو lookup السريع.
            
            3- multimap
                مثل map لكن بيسمح بتكرار المفاتيح.

                العناصر مرتبة حسب المفتاح.

                بتفيد لما بدك تخزن key نفسه مع قيم متعددة.

        importent methods:
            mp[key]          // الوصول أو الإنشاء (value=0 افتراضيًا إن ما كان موجود)
            mp.at(key)       // الوصول مع تحقق (throw exception إذا مش موجود)
            mp.insert({key, value}); // إدخال عنصر
            mp.erase(key);   // حذف عنصر
            mp.find(key);    // إرجاع iterator للمفتاح أو mp.end() إذا مش موجود
            mp.count(key);   // 0 أو 1 (هل المفتاح موجود؟)
            mp.size();       // عدد العناصر
            mp.clear();      // مسح الكل

    */

    return 0;
}

// Questions

int most_freq() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    int best = v[0];
    int maxFreq = 0;

    for (auto &p : freq) {
        if (p.second > maxFreq || (p.second == maxFreq && p.first < best)) {
            maxFreq = p.second;
            best = p.first;
        }
    }

    cout << best << "\n";
    return 0;
}
