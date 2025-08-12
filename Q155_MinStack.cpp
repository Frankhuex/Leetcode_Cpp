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

class MinStack {
private:
    vector<int> mainStack;
    vector<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        mainStack.push_back(val);
        if (minStack.size()>0) {
            minStack.push_back(min(minStack[minStack.size()-1],val));
        } else {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        mainStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return mainStack[mainStack.size()-1];
    }
    
    int getMin() {
        return minStack[minStack.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}