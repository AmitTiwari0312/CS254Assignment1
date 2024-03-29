#include<bits/stdc++.h>
using namespace std;


struct Item {
    int value;
    int weight;
};


int knapsackDP(const vector<Item> &items, int capacity) {
    int n = items.size();
    
    
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity]; 
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cin >> capacity;

    int maxValue = knapsackDP(items, capacity);
    
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
