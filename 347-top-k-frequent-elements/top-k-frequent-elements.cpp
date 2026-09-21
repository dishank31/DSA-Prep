class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> FreqMpp;
        for(int i=0 ; i<nums.size() ; i++) FreqMpp[nums[i]]++;

        vector<pair<int, int>> FreqPairs;
        for(auto it : FreqMpp)
        {
            FreqPairs.push_back({it.second, it.first});
        }

        sort(FreqPairs.rbegin(), FreqPairs.rend());

        vector<int> ans;
        for(int i=0 ; i<k ; i++)
        {
            ans.push_back(FreqPairs[i].second);
        }

        return ans;
    }
};