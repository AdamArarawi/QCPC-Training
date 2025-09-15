#include <bits/stdc++.h>
using namespace std;

// ------------------- STL -------------------
// Vector: اطبع العناصر unique
void printUniqueVector(vector<int>& nums){
    sort(nums.begin(), nums.end());
    auto last = unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
};

// Map/Set: عدّد تكرار كل رقم
void printFrequencies(const vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int i =0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    for (const auto& i: mp) {
        cout << i.first << " --> " << i.second << '\n';
    }
};

// Map/Set: تحقق إذا string فيه كل أحرف unique
bool hasAllUniqueChars(const string& s) {
    unordered_set<char> chars;
    for (int i = 0; i < s.size(); i++) {
        chars.insert(s[i]);
    }

    return chars.size() == s.size();
};

// Priority Queue: اطبع أكبر 3 أعداد
void printTop3(const vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++) {
        if ((int)pq.size() < 3) { pq.push(nums[i]);}
        else if ((pq.top() < nums[i])) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    vector<int> res(3);
    for (int i = 0; i < 3; i++) {
        res[i] = (pq.top());
        pq.pop();
    }

    reverse(res.begin(), res.end());

    for (int i = 0; i < 3; i++) {
       cout << res[i];
    }
};

// Priority Queue: اطبع أصغر 3 أعداد
void printSmallest3(const vector<int>& nums) {
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
        if ((int)pq.size() < 3) { pq.push(nums[i]);}
        else if ((pq.top() < nums[i])) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << pq.top();
        pq.pop();
    }
};

// ------------------- Strings -------------------
// تحقق إذا Palindrome
bool isPalindrome(const string& s) {
    int left = 0, right = s.size()-1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
};

// اعكس string
string reverseString(string& s) {
    reverse(s.begin(), s.end());
    return s;
};

// أطول substring بدون تكرار
int longestUniqueSubstring(const string& s) {
    unordered_set<char> st;
    int l = 0, r = 0, maxLen = 0;

    while (r < (int)s.size()) {
        // إذا الحرف الحالي مش مكرر → ضيفه وحرك r
        if (!st.count(s[r])) {
            st.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        // إذا مكرر → شيل من اليسار وحرك l
        else {
            st.erase(s[l]);
            l++;
        }
    }
    return maxLen;
}


// ------------------- Frequency / Sorting -------------------
// اطبع الحروف حسب التكرار
void sortCharsByFrequency(const string& s);

// اطبع الأعداد حسب frequency (لو تساووا → حسب القيمة)
void sortByFrequency(const vector<int>& nums);

// ------------------- main -------------------
int main() {
    // جرّب تختبر كل دالة هون مع input بسيط
    vector<int> v = {1,2,3,1,3,1,1};
    printUniqueVector(v);

    cout << "\n";

    v = {1,2,3,1,3,1,1};
    printFrequencies(v);

    cout << hasAllUniqueChars("adam") << '\n';

    printTop3({3,4,1,2,5});
    cout << '\n';
    printSmallest3({3,4,1,2,5});
    cout << "\n";
    cout << longestUniqueSubstring("abcdabc");
    return 0;
}
