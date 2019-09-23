class Solution {
private:
    stack<int> courseStack;
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int node){
        if(color[node] == 1){
            return false;
        }
        else if (color[node] == 2){
            return true;
        }
        color[node] = 1;
        for(int i=0; i < graph[node].size(); ++i){
            if(!dfs(graph,color,graph[node][i])){
                return false;
            }
        }
        courseStack.push(node);
        color[node] = 2;
        return true;
    } 
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> color(numCourses,0);  //0 not visited, 1 visited in this dfs, 2 visited
        vector<int> result;
        for(int i=0;i < prerequisites.size(); ++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<graph.size();++i)
            if(!dfs(graph,color,i)){
                return result;
            }
        while(!courseStack.empty()){
            result.push_back(courseStack.top());
            courseStack.pop();
        }
        return result;
    }
};