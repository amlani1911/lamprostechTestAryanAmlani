#include<bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Create a hashmap to count element frequencies
    map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    for(auto num : freqMap){
        cout<<num.first<< " " << num.second<<endl;
    }

    // Create a priority queue (min heap) to store the elements with their frequencies
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Iterate over the hashmap and add elements to the min heap
    for (auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first});
        // Keep the heap size <= k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    // Extract the top k elements from the min heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    // Reverse the result to get the elements in descending order of frequency
    reverse(result.begin(), result.end());

    return result;
}

int main() {

    // Input the array size
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the array elements
    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Input the value of k
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Find the top k frequent elements
    vector<int> result = topKFrequent(nums, k);

    // Print the result
    cout << "Top " << k << " Frequent Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}