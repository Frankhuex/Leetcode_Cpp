#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;


class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (minHeap.empty() || num>=minHeap.top()) {
            if (minHeap.size()>maxHeap.size())  {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            minHeap.push(num);
        } else {
            if (maxHeap.size()>minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxHeap.push(num);
        }
    }
    
    double findMedian() {
        if (maxHeap.size()>minHeap.size()) {
            return maxHeap.top();
        } else if (maxHeap.size()<minHeap.size()) {
            return minHeap.top();
        } else {
            return (maxHeap.top()+minHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    return 0;
}