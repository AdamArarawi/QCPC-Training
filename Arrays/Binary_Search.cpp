#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& boxes, int d, int load) {
    int days = 1;         
    int currLoad = 0;     

    for (int b : boxes) {
        if (b > load) return false;
        if (currLoad + b <= load) {
            currLoad += b;  
        } else {
            days++;               
            currLoad = b;
        }
    }

    return days <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> boxes = {3, 2, 2, 4, 1};
    int d = 3;

    int l = *max_element(boxes.begin(), boxes.end());
    int r = accumulate(boxes.begin(), boxes.end(), 0);
    int result = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (isPossible(boxes, d, mid)) {
            result = mid;  
            r = mid - 1;
        } else {
            l = mid + 1;  
        }
    }

    cout << result << "\n";
    return 0;
}
