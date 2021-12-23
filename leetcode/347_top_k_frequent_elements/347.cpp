class Comparator {
public:
    Comparator() {}
    
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        
        for (int num : nums) {
            counts[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
        for (pair<int, int> elem : counts) {
            pq.push(elem);
        }
        
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            int num {pq.top().first};
            ret.push_back(num);
            pq.pop();
        }
        
        return ret;
    }
};
