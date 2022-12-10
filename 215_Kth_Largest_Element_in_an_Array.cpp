class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // the heap (inside implementation)
        int n = nums.size(); // number of elements
        for(int i = 0; i < n; ++i)
            pq.push(nums[i]);   

        // delete the maximum kth times
        for (int i = 0; i < k - 1; ++i)
            pq.pop();
        return pq.top(); // the most priority element
    }
};
