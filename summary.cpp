//quick sort

int partition(vector<int>& nums, int left, int right){
    if(left >= right){
        return left;
    }
    
    int key = nums[(left+right)/2];
    swap(nums[left],nums[(left+right)/2]);
    int index_left = left;
    int index_right = right;
    while(index_left < index_right){
        while(index_left < index_right && nums[index_right] >= key){   //从小到大 和 从大到小
            --index_right;
        }
        while(index_left < index_right && nums[index_left] <= key){
            ++index_left;
        }
        if(index_left<index_right)
            swap(nums[index_right], nums[index_left]);
        
    }
    swap(nums[index_left],nums[left]);
    //变体
    if(index_left == nums.size()/2 ){
        return index_left;
    }
    else if(index_left < nums.size()/2){
        return partition(nums,index_left+1,right);
    }else{
        return partition(nums,left,index_left - 1);
    }
    
}



//merge sort
void mergeSort(vector<int>& nums,int left,int right){
        if(left >= right){
            return;
        }
        int mid =(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        
        vector<int> temp(right-left+1);
        int index_left = mid;
        int index_right = right;
        int i=temp.size()-1;
        while(index_left >= left && index_right >= mid+1){
            
            if(nums[index_left] > nums[index_right]){
                temp[i--] = nums[index_left--];
            }else{
                temp[i--] = nums[index_right--];
            }
        }
       
        while(index_left >= left){
            temp[i--] = nums[index_left--];
            
        }
        while(index_right >= mid+1){
            temp[i--] = nums[index_right--];
        }
        for(int i=left ; i<=right ; ++i){
            nums[i] = temp[i-left];
        }
    }



//LRU
class LRUCache {
public:
    LRUCache(int capacity) {
       _capacity=capacity;
        
    }
    
    int get(int key) {
        if(Cache.find(key) == Cache.end()){
            return -1;
        }
        rank.erase(index[key]);
        rank.push_front(key);
        index[key] = rank.begin();
        return Cache[key];
    }
    
    void put(int key, int value) {
       if(Cache.find(key) == Cache.end()){
            if(Cache.size() == _capacity){
                int pop_one = rank.back();
                rank.pop_back();
                Cache.erase(pop_one);
                index.erase(pop_one);
            }
            Cache[key] = value;
            rank.push_front(key);
            index[key] = rank.begin();
       }else{
            Cache[key] = value;
            rank.erase(index[key]);
            rank.push_front(key);
            index[key] = rank.begin();
       }
        
    }
    
private:
    unordered_map<int,int> Cache;
    unordered_map<int, list<int>::iterator> index;
    list<int> rank;
    int _capacity;
};