#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp, int target)
{
    if (i == arr.size())
    {
        if (sum == target)
            return 0;
        else
            return -100000;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = -100000;

    if (sum + arr[i] <= target)
        take = 1 + solve(i + 1, sum + arr[i], arr, dp, target);

    int skip = solve(i + 1, sum, arr, dp, target);

    if (take > skip)
        dp[i][sum] = take;
    else
        dp[i][sum] = skip;

    return dp[i][sum];
}

vector<int> getLongestSubset(vector<vector<int>> &dp, vector<int> &arr, int target)
{
    vector<int> ans;
    int currentSum = 0;
    int i = 0;

    while (i < arr.size() && currentSum <= target)
    {
        int take = -100000;

        if (currentSum + arr[i] <= target)
            take = 1 + dp[i + 1][currentSum + arr[i]];

        int skip = dp[i + 1][currentSum];

        if (take >= skip && take > -100000)
        {
            ans.push_back(arr[i]);
            currentSum += arr[i];
        }

        i++;
    }

    return ans;
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

    int length = solve(0, 0, arr, dp, target);

    if (length < 0)
    {
        cout << "No subset found";
    }
    else
    {
        cout << length << endl;
        vector<int> subset = getLongestSubset(dp, arr, target);
        for (int i = 0; i < subset.size(); i++)
            cout << subset[i] << " ";
    }

    return 0;
}
