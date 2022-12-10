class Solution {
public:
    int search(vector<int>& nums, int target) {
        return recursive_way(nums, target, 0, nums.size() - 1);
    }

private:
    int recursive_way(vector<int>& nums, int target, int i, int j) {
        // base case
        if (i == j){ // jinterval of 1 elemnt
            if (nums[i] == target) return i;
            else return -1;
        }
        else if (i == j - 1){ // interval of elements
            if (nums[i] == target) return i;
            else if (nums[j] == target) return j;
            else return -1;
        }
        // recursive case
        else{
            // get the middle idx
            int mid = 0;
            if ((j - i) % 2 == 0) // even
                mid = (j - i) / 2;
            else // odd
                mid = (j - i) / 2 + 1;
            mid += i; // in the middle of the segment

            // k position among [i, j]
            if(nums[i] > nums[mid] && nums[mid] < nums[j]) { // rotation between i and mid
                if (target > nums[j] || target < nums[mid])
                    return recursive_way(nums, target, i, mid);
                else 
                    return recursive_way(nums, target, mid, j);
            }
            else if(nums[i] < nums[mid] && nums[mid] < nums[j]) { // no rotation
                if (target < nums[mid])
                    return recursive_way(nums, target, i, mid);
                else 
                    return recursive_way(nums, target, mid, j);
            }
            else { // rotation between mid and j
                if (target > nums[mid] || target < nums[i])
                    return recursive_way(nums, target, mid, j);
                else 
                    return recursive_way(nums, target, i, mid);
            }            
        }
    }
};
// i > mid, mid < j (4 5 1 2 3) --> rotation between i and mid
// i < mid, mid < j (no rotation) 
// i < mid, mid > j (3 4 5 1 2) --> rotation between mid and j
