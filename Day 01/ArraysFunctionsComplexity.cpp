#include <bits/stdc++.h>
using namespace std;

int main () {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int mx = arr[0];
    for (int i = 1; i < 10; i++) {
        mx = max(mx, arr[i]);
    }

    long long sum = 0;
    for (int i = 0; i< 10; i++) sum += arr[i];
    double avg = sum * 1.0 / 10;

    for (int i = 0; i < 10/2; i ++) {
        swap(arr[i], arr[10-1-i]);
    }

    int even = 0, odd = 0;
    for (int i = 0; i < 10; i++) (arr[i] % 2 == 0 ? even++ : odd++);

    return 0;
}

int prefix() {
    int n;
    cin >> n;

    vector<int> arr(n+1);   // خليه n+1 عشان indexing يبدأ من 1
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // بناء prefix
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    // q queries
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }

    // first K sum
    int k;
    cin >> k;
    int firstK = pref[k] - pref[0];
    cout << "First K sum = " << firstK << "\n";

    // last K sum
    int lastK = pref[n] - pref[n-k];
    cout << "Last K sum = " << lastK << "\n";

    return 0;
}


int algorithms () {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = arr[0];
    for (int i = 1;i < n; i++) {
        mx = max(mx, arr[i]);
    }

    int target;
    cin >> target;

    bool isEquelTarget = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            isEquelTarget = true;
        }
    }

    if (isEquelTarget) cout << "Yes";
    else cout << "No";

    for (int i = n-1; i > 0; i--) {
        cout << arr[i] << " ";
    }
    
    unordered_map<int, int> freq;
    pair<int,int> mostFreq = {0,0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (mostFreq.second < freq[arr[i]]) {
            mostFreq = {arr[i], freq[arr[i]]};
        }
    }


    return 0;
}

int sliding_window_example() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 2};
    int K = 5;
    int n = arr.size();

    int left = 0, right = 0;
    int sum = 0;
    int max_len = 0;

    while (right < n) {
        sum += arr[right];
        right++;

        while (sum > K && left < right) {
            sum -= arr[left];
            left++;
        }

        max_len = max(max_len, right - left);
    }

    cout << max_len << '\n';    
    return max_len;
}

