// Given a non-empty array of integers, return the k most frequent elements.
//
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
// Note:
// You may assume k is always valid, 1 <= k <= number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// Subscribe to see which companies asked this question

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n)
        unordered_map<int, int> freq;
        for (auto i : nums) {
            ++freq[i];
        }

        // O(nlog(k))
        vector<pair<int, int>> vfreq(k);
        auto cmp = [](pair<int, int> A, pair<int, int> B) { return A.second > B.second; };
        partial_sort_copy(freq.begin(), freq.end(), vfreq.begin(), vfreq.end(), cmp);

        // O(k)
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = vfreq[i].first;
        }
        return result;
    }
};

