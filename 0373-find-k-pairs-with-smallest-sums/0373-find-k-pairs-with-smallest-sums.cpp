#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0) return ans;

        // Min-heap to store the pairs with their sum
        auto compare = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

        // Initialize the heap with pairs (i, 0) for all i
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                minHeap.emplace(i, j + 1);
            }
        }

        return ans;
    }
};
