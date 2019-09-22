//leetcode   207

class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int node){
        
        if(color[node] == 1){
            return false;
        }else if(color[node] == 2){
            return true;
        }    
        color[node] = 1;
        if(graph[node].size()==0){
            color[node] = 2;
            return true;
        }
        for(int j = 0; j < graph[node].size(); ++j){
            if(!dfs(graph,color,graph[node][j])){
                return false;
            }
            
        }
        color[node] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> color(numCourses,0);//0 not visited 1 visited in this dfs 2 visted
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
        for(int i=0; i< graph.size();++i){
            if(!dfs(graph,color,i)){
                return false;
            }
        }
        return true;
       
    }
};