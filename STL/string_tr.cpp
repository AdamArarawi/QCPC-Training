#include <bits/stdc++.h>
using namespace std;

// isalnum() ترجع true إذا كان الحرف رقم أو حرف (A–Z, a–z, 0–9).

// ---------------- 1. Valid Palindrome ----------------
// نتحقق إذا string Palindrome بعد تجاهل الرموز والمسافات
bool isPalindrome(string s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}

// ---------------- 2. Reverse String ----------------
void reverseString(string &s) {
    reverse(s.begin(), s.end());
}

// ---------------- 3. Valid Anagram ----------------
// نتحقق إذا s و t عبارة عن نفس الحروف لكن بترتيب مختلف
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    for (char c : t) {
        if (--freq[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    // ----- Test Palindrome -----
    string p1 = "A man, a plan, a canal: Panama";
    string p2 = "race a car";
    cout << "Palindrome test 1: " << isPalindrome(p1) << "\n"; // 1
    cout << "Palindrome test 2: " << isPalindrome(p2) << "\n"; // 0

    // ----- Test Reverse String -----
    string r = "hello";
    reverseString(r);
    cout << "Reversed: " << r << "\n"; // "olleh"

    // ----- Test Anagram -----
    cout << "Anagram test 1: " << isAnagram("anagram", "nagaram") << "\n"; // 1
    cout << "Anagram test 2: " << isAnagram("rat", "car") << "\n";         // 0

    return 0;
}
