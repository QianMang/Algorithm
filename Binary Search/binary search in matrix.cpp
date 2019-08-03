//binary search in matrix
//problem  74


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;
        int mid;
        int midElement;
        while( left<=right ){
            mid = (left + right) / 2;
            midElement = matrix[mid / n][mid % n];
            if(target == midElement){
                return true;
            }
            else{
                if(target < midElement) 
                    right = mid - 1;
                else
                    left = mid+1;
            }
        }
          return false; 
            
    
    }
    
};