#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 0-1 Backpack: Dynamic Planning after Space Optimization*/
int knapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    vector<int> dp(cap + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}

int main() {
    //Example item weights and values
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1500, 2000, 3000, 3500};
    int capacity = 7;

    int maxValue = knapsackDPComp(weights, values, capacity);
    cout << "The capacity of the backpack is " << capacity << " The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}

