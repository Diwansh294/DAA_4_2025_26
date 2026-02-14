#include <iostream>
#include <vector>
using namespace std;

int countSubsets(int i, int sum, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (i == arr.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = 0;

    if (sum + arr[i] <= target)
        take = countSubsets(i + 1, sum + arr[i], arr, target, dp);

    int notTake = countSubsets(i + 1, sum, arr, target, dp);

    dp[i][sum] = take + notTake;
    return dp[i][sum];
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    cout << countSubsets(0, 0, arr, target, dp);

    return 0;
}
