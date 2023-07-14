class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    //To access the median in O(1), we need a data structure that give us the maximum of low half and the minimum of high half in O(1)
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());   //contains max element of array
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());    //maxheap contains min eleme of array
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size()>minheap.size()){
            return maxheap.top();
        }
        return (maxheap.top()+minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */