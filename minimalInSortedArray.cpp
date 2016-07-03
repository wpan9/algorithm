// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// 
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// Find the minimum element.
// 
// You may assume no duplicate exists in the array.
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        assert(!nums.empty());

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] <= nums[right])
                return nums[left];

            int middle = left + (right - left + 1) / 2;
            if (nums[middle] >= nums[right])
                left = middle;
            else
                right = middle;
        }
        return nums[left];
    }
};
