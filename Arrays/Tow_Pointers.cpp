#include <bits/stdc++.h>
using namespace std;

// int twoSum () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     vector<int> numbers =  {2,7,11,15};
//     int target = 9;

//     int l=0,r=numbers.size()-1;
//     int sum = 0;    
//     while (l < r)
//     {
//         sum = numbers[l] + numbers[r];
//         if ( sum == target ) {
//             cout << "[" << l+1 << "," << r+1<< "]";
//         } else if (sum < target)  {
//             l++;
//         } else {
//             r--;
//         }
//     }
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int l = i+1, r = nums.size()-1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                results.push_back({nums[i], nums[l], nums[r]});
                l++; r--;
                while (l < r && nums[l] == nums[l-1]) l++;
                while (l < r && nums[r] == nums[r+1]) r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    return 0;

}
