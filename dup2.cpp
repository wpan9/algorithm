// 
// Given an array of integers and an integer k, find out whether there there
// are two distinct indices i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.
//
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() <= 1)
            return false;

        // value -> index map
        map<int, int> valueMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto ret = valueMap.insert(std::make_pair(nums[i], i));

            // such a value already exists in the map.
            if (ret.second == false) {
                // difference is within k. just return.
                if (ret.first->second + k >= i)
                    return true;

                // update the value with this larger index.
                ret.first->second = i;
            }
        }

        return false;        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() <= 1)
            return false;

        // value -> index map
        map<int, int> valueMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto ret = valueMap.insert(std::make_pair(nums[i], i));

            // such a value already exists in the map.
            if (ret.second == false) {
                // difference is within k. just return.
                if (ret.first->second + k >= i)
                    return true;

                // update the value with this larger index.
                ret.first->second = i;
            }
        }

        return false;        return false;
    }
};
