#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long ops = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {

    ops++;
    maxDepth = max(maxDepth, depth);

    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            ops++;
        }
        p >>= 1;
        ops++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        ops++;
    }

    reverse(small.begin(), small.end());
    ops += n;

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {

    int nValues[] = {8, 16, 32};

    cout << "n\tOperations\tDepth\tTime(ms)\n";

    for (int n : nValues) {

        ops = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();

        complexRec(n, 1);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << n << "\t"
             << ops << "\t\t"
             << maxDepth << "\t"
             << duration.count() << endl;
    }
}

// reccurrance relation-T(n)=3T(n/2)+O(nlogn)
//time complexity
// case:1-if logb(a)>k then O(n^logb(a))
// ans-O(n^log2(3))
