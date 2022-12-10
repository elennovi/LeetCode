class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> mg(nums1.size() + nums2.size());
        // first part: merge until the last element of any vector
        int k = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]){
                mg[k] = nums1[i];
                i++;
                k++;
            }
            else if (nums1[i] > nums2[j]){
                mg[k] = nums2[j];
                j++;
                k++; 
            }
            else{ 
                mg[k] = nums2[j];
                mg[k + 1] = nums2[j];
                j++;
                i++;
                k += 2;
            }
        }

        // are there elements in nums1
        while(i < nums1.size())
            mg[k] = nums1[i], i++, k++;

        // are there elements in nums2
        while(j < nums2.size())
            mg[k] = nums2[j], j++, k++;
    
        // obtain the median
        // odd
        if (mg.size() % 2 != 0){
            int half = mg.size() / 2;
            return mg[half];
        } 
        // even
        else {
            int half = mg.size() / 2;
            return (mg[half - 1] + mg[half]) / 2.0;
        }
    }
};
