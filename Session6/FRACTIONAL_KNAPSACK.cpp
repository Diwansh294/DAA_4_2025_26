#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int maxCap;
    cout << "Enter knapsack capacity: ";
    cin >> maxCap;

    vector<Item> arr(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> arr[i].weight >> arr[i].profit;
        arr[i].ratio = (double)arr[i].profit / arr[i].weight;
    }

    sort(arr.begin(), arr.end(), [](Item a, Item b) {
        return a.ratio > b.ratio;
    });

    int totalWeight = 0;
    double totalValue = 0.0;

    for(int i = 0; i < n && totalWeight < maxCap; i++) {
        if(arr[i].weight <= maxCap - totalWeight) {
            totalWeight += arr[i].weight;
            totalValue += arr[i].profit;
        }
        else {
            totalValue += (maxCap - totalWeight) * arr[i].ratio;
            totalWeight = maxCap;
        }
    }

    cout << "Maximum value = " << totalValue << endl;
    return 0;
}
