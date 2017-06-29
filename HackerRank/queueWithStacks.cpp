#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

class MyQueue {
  
    public:        
        void push(int pushValue) {
            if(stackNewestOnTop.empty() && stackOldestOnTop.empty()) { 
                stackOldestOnTop.push(pushValue);
            } else { 
                stackNewestOnTop.push(pushValue);
            }
        }
        
        void orderStacks() { 
            std::vector<int> stackElements;
            while(!stackNewestOnTop.empty()) { 
                stackElements.push_back(stackNewestOnTop.top());
                stackNewestOnTop.pop();
            }
            for(auto value : stackElements) {
                stackOldestOnTop.push(value);
            }
        }
        
        void pop() {
            if(stackOldestOnTop.empty() && !stackNewestOnTop.empty()) { 
                orderStacks();
            } 
            stackOldestOnTop.pop();
        }

        int front() {
            if(stackOldestOnTop.empty() && !stackNewestOnTop.empty()) { 
                orderStacks();
            }          
            return stackOldestOnTop.top();
        }
        
private:
    std::stack<int> stackNewestOnTop, stackOldestOnTop;  
};

int main() {
    MyQueue q1;
    int q, type, x;
    std::cin >> q;
    
    for(int i = 0; i < q; i++) {
        std::cin >> type;
        if(type == 1) {
            std::cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else std::cout << q1.front() << std::endl;
    }
    return 0;
}
