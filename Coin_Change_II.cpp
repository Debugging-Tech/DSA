// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.

#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0) return (amount % coins[ind] == 0) ? 1 : 0; 
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind - 1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[ind]){
            take = solve(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = take + notTake; 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1)); 
        return solve(n-1, amount, coins, dp);
    }


int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    cout << change(amount, coins) << endl;

}