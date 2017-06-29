#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPair(std::stack<char> &parStack, const char par) {
    if(parStack.empty()) return false;
    if(parStack.top() == par) {
        parStack.pop();
        return true;
    }
    return false;
}

bool is_balanced(string expression) {
    std::stack<char> parStack;

    for(auto par : expression) {
        switch(par) {
            case '[':
            case '{':
            case '(':
                parStack.push(par);
            break;
            case ']':
                if(!(isPair(parStack, '['))) {
                    return false;
                }
            break;
            case '}':
                if(!(isPair(parStack, '{'))) {
                    return false;
                }
            break;
            case ')':
                if(!(isPair(parStack, '('))) {
                    return false;
                }                   
            break;
            
        }
    }
    if(parStack.empty()) {
        return true;
    } else {
        return false;
    }      
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
