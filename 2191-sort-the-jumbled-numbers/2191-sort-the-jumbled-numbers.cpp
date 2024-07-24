class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> store;
        
        for(int i = 0; i < nums.size(); ++i) {
            int mappedValue = mapValue(nums[i], mapping);
            store.push_back({mappedValue, i, nums[i]});
        }
        
        sort(store.begin(), store.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<int> result;
        for(const auto& entry : store) {
            result.push_back(entry[2]);
        }
        
        return result;
    }

private:
    int mapValue(int num, const vector<int>& mapping) {
        if (num == 0) return mapping[0];
        int mappedValue = 0;
        int place = 1;
        while (num > 0) {
            int digit = num % 10;
            mappedValue = mapping[digit] * place + mappedValue;
            num /= 10;
            place *= 10;
        }
        return mappedValue;
    }
};
