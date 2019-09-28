// leetcode  739
//use stack to find next larger num

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> waitList;
        vector<int> result(T.size(),0);
        for(int i=0;i<T.size();++i){
            while(!waitList.empty()){
                if(T[waitList.top()] < T[i]){
                    result[waitList.top()] = i - waitList.top();
                    waitList.pop();
                    continue;
                }
                break;
            }
            waitList.push(i);
        }
        return result;
    }
};