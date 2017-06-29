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

bool isPair(std::stack<char> &bracketRepository, const char bracket) {
    if (bracketRepository.empty()) return false;
    if (bracketRepository.top() == bracket) {
        bracketRepository.pop();
        return true;
    }
    return false;
}

bool is_balanced(std::string givenExpression) {
    std::stack<char> bracketRepository;

    for (auto currentBracket : givenExpression) {
        switch (currentBracket) {
            case '[':
            case '{':
            case '(':
                bracketRepository.push(currentBracket);
            break;
            case ']':
                if(!(isPair(bracketRepository, '['))) {
                    return false;
                }
            break;
            case '}':
                if(!(isPair(bracketRepository, '{'))) {
                    return false;
                }
            break;
            case ')':
                if(!(isPair(bracketRepository, '('))) {
                    return false;
                }                   
            break;
            
        }
    }
    if (bracketRepository.empty()) {
        return true;
    else
        return false;   
}

int main(){
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        std::string expression;
        std::cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}
