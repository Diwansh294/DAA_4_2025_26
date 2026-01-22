#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> jobs;
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        
        sort(jobs.rbegin(), jobs.rend());

        
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int jobCount = 0;
        int totalProfit = 0;

        for (auto &job : jobs) {
            int prof = job.first;
            int dead = job.second;

           
            int available = findParent(dead, parent);

            if (available > 0) {
                jobCount++;
                totalProfit += prof;
                parent[available] = findParent(available - 1, parent);
            }
        }

        return {jobCount, totalProfit};
    }
};
