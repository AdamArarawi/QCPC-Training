#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& houses, int r) {
    int wifis = 0;
    vector<int> housesDone(houses.size());
    int currHouse = houses[0];


    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> houses(n);
    for (int i =0 ; i < n; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int l = houses[0];
    int r = houses.back() - houses.front();
    int result = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (isPossible(houses,  mid)) {
            result = mid;  
            l = mid + 1;
        } else {
            r = mid - 1;  
        }
    }

    cout << result << "\n";
    return 0;
}
