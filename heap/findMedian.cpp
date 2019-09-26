//leetcode   295   find Median  

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return static_cast<double>(maxHeap.top());
        }else{
            return (static_cast<double>(maxHeap.top()) + static_cast<double>(minHeap.top())) / 2;
        }
    }
};
