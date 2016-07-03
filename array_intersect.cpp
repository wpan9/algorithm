// Given two arrays, write a function to compute their intersection.
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
// Note:
// Each element in the result must be unique.
// The result can be in any order.
//
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (int i : nums1)
          s1.insert(i);
        unordered_set<int> s2;
        for (int i : nums2) {
            if (s1.find(i) != s1.end()) {
                s2.insert(i);
            }
        }

        vector<int> result;
        for (int i : s2) {
            result.push_back(i);
        }
        return result;
    }
};
