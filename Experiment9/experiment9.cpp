class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int range = 0;
        for(int num : arr) range += num;

        vector<vector<bool>> t(n+1, vector<bool>(range+1, 0));

        for(int i = 0; i < n + 1; i++) t[i][0] = 1;

        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < range + 1; j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }

        for(int j = range/2; j >= 0; j--)
            if(t[n][j]) return range - 2*j;
    }
};

// Time Complexity: O(n * range)
// Space Complexity: O(n * range)
