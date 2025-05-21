#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Coin Exchange: Greedy Algorithm */
int coinChangeGreedy(vector<int> &coins, int amt) {
    
    sort(coins.begin(), coins.end());

    int i = coins.size() - 1;
    int count = 0;

    while (amt > 0 && i >= 0) {
        
        while (i >= 0 && coins[i] > amt) {
            i--;
        }
        if (i < 0) break; //Unable to give change, exit loop

        amt -= coins[i];
        count++;
    }

    //If no feasible solution is found, -1 is returned.
    return amt == 0 ? count : -1;
}

int main() {
    vector<int> coins = {1, 2, 5, 10};
    int amount = 18;

    int res = coinChangeGreedy(coins, amount);
    if (res != -1) {
        cout << "Minimum number of coins required:" << res << endl;
    } else {
        cout << "Unable to get change" << endl;
    }

    return 0;
}

