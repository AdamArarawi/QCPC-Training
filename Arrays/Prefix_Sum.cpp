// Compile with: g++ -std=c++17 prefix_examples.cpp -O2
#include <bits/stdc++.h>
using namespace std;

/*
 📘 Prefix Sum Notes:
    - prefix[0] = 0
    - prefix[i] = sum(arr[0..i-1])   // i-th prefix includes arr[i-1]
    - sum(l, r) = prefix[r+1] - prefix[l]

 Common uses:
    - Answer range sum queries in O(1) after O(n) preprocessing.
    - Balance left/right sums.
    - Subarray sum problems (fixed or variable length).
    - Basis for more advanced: 2D prefix, difference arrays, etc.
*/

// --------------- Example 1: Range Sum Queries ---------------
void example_easy(const vector<int>& nums, const vector<pair<int,int>>& queries) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + nums[i-1];

    cout << "Example 1: Range Sum Queries\n";
    for (auto [l, r] : queries) {
        int sumLR = prefix[r+1] - prefix[l];
        cout << "Sum[" << l << "," << r << "] = " << sumLR << "\n";
    }
    cout << "\n";
}

// --------------- Example 2: Find Equilibrium Index ---------------
void example_medium(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + nums[i-1];

    cout << "Example 2: Equilibrium Index\n";
    for (int i = 0; i < n; i++) {
        int leftSum = prefix[i];
        int rightSum = prefix[n] - prefix[i+1];
        if (leftSum == rightSum) {
            cout << "Index " << i << " is equilibrium (sum=" << leftSum << ")\n";
        }
    }
    cout << "\n";
}

// --------------- Example 3: Max Subarray Sum of Fixed Length k ---------------
void example_hard(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + nums[i-1];

    cout << "Example 3: Max Subarray Sum of length " << k << "\n";
    int maxSum = INT_MIN;
    for (int l = 0, r = k; r <= n; l++, r++) {
        int sum = prefix[r] - prefix[l];
        maxSum = max(maxSum, sum);
    }
    cout << "Max sum = " << maxSum << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 1, 5, 1, 3, 2};

    // Example 1
    vector<pair<int,int>> queries = {{0,2}, {1,3}, {0,5}};
    example_easy(arr, queries);

    // Example 2
    example_medium(arr);

    // Example 3
    example_hard(arr, 3);

    // Quick summary
    cout << "Complexity summary:\n";
    cout << " Build prefix: O(n)\n";
    cout << " Range query: O(1)\n";
    cout << " Equilibrium: O(n)\n";
    cout << " Max fixed subarray: O(n)\n";

    return 0;
}
