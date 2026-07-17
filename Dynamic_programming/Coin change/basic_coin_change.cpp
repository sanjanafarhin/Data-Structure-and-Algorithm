#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {1, 3, 4};
    int amount = 9;

    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << "DP Array:\n";

    for (int i = 0; i <= amount; i++) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    cout << "\nMinimum coins needed = " << dp[amount];

    return 0;
}

