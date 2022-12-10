class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(); // the size of the vector
        vector<int> new_nums(size); // to storage the new vector
        for(int i = 0; i < size; i++)
            new_nums[(i + k) % size] = nums[i]; // the new position for nums at i is  (i+ k)%  
        nums = new_nums;
    }
};

// 0 1 2 3 4 5
// 1 2 3 4 5 6
// k = 3
// 4 5 6 1 2 3

// pos = 2
