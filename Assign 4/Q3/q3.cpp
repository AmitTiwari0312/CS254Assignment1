#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < nums.size(); i++) {
        min_heap.push(nums[i]);
        
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    return min_heap.top();
}

int main() {

    ifstream iF("input.txt");
    ofstream oF("output.txt");

    int t; iF >> t;
    while (t--) {
        int n; iF >> n;
        vector<int> nums;
        for (int i=0; i<n; i++) {
            int x; iF >> x;
            nums.push_back(x);
        }
        int k; iF >> k;

        int ans = kthLargest(nums, k);

        oF << "The " << k << "th largest element is: " << ans << endl;
    
    }

    return 0;
}
