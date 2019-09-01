//leetcode p357
//how to use priority_queue for topK problem
//https://www.cnblogs.com/xzxl/p/7266404.html
//especially cmp
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int > frequency;
        priority_queue<pair<int,int>, vector<pair<int,int>> , cmp> topK;
        for(auto it = nums.cbegin(); it != nums.cend(); ++it){
            if(frequency[*it] == NULL){
                frequency[*it] = 1;
            }
             ++frequency[*it];
        }
        for(auto it = frequency.cbegin(); it != frequency.cend();++it){
            topK.push(*it);
            if(topK.size() > k){
                topK.pop();
            }
            
        }
        while(!topK.empty()){
            result.push_back(topK.top().first);
            topK.pop();
        }
        return result;
    }
};