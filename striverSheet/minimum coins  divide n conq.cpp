/*ALGORITHM:
1. initialise an answer with INT_MAX
2. sort the coins in desc order
3. use a void recursive helper function , pass sorted coins, index to process from(initially from 0), rem amount , ans by ref, current num of coins
4. in recursive call, 2 cases: if rem amount less than curr coin, or equal to, or greater than.
   if less: base case.
   else if: equal: write ans as min(ans,currnum)
   else if greater, update rem and make subsequent calls inlcuding curr coin
5. finally, if ans == INT_Max, return -1 else return ans  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int MinimumCoins(vector<int> &coins, int amount)
    {
        int ans = INT_MAX;
        sort(coins.rbegin(), coins.rend());
        selectCoin(coins, 0, amount, ans, 0);

        if (ans == INT_MAX)
            return -1;
        return ans;
    }

private:
    void selectCoin(vector<int> &coins, int i, int rem, int &ans, int curr)
    {
        if (rem == 0)
        {
            ans = min(ans, curr);
            return;
        }
        if (curr + 1 >= ans)
            return;
        for (int j = i; j < coins.size(); j++)
        {
            if (rem >= coins[j])
            {
                selectCoin(coins, j, rem - coins[j], ans, curr + 1);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> coins = {2, 5};
    int amount = 3;
    int res = s.MinimumCoins(coins, amount);
    cout << res;
    return 0;
}

/*Given an integer array of coins representing coins of different denominations
and an integer amount representing a total amount of money. Return the
fewest number of coins that are needed to make up that amount.
 If that amount of money cannot be made up by any combination
 of the coins, return -1. There are infinite numbers of coins of each type


Examples:
Input: coins = [1, 2, 5], amount = 11

Output: 3

Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.

Input: coins = [2, 5], amount = 3

Output: -1

Explanation: It's not possible to make amount 3 with coins 2 and 5.
 Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.*/

/*
soln:
OBERVATIONS:
 1. we could take the coin with most val, but if we commit, we might end up in a case, unable to complete the amount. two problems: whether to take or not and,
 how much to take. how to determine this. is the only problem
2. if somehow it can be determined , a certain amount is possible or not befotre annd after a selection, it is possible
3. or, can i try recursion to try all possiblities.after sorting in desc order at each call, i can take x , x-1, x-2 ... to the existing coin set , base condition if rem amt<=coin
*/