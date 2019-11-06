#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

pair<string, string> splitParentheses(string& p) {
    string u = "", v = "";
    
    int open = 0, close = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') open++;
        else if (p[i] == ')') close++;
        
        if (open == close) {
            u = p.substr(0, i+1);
            v = p.substr(i+1, p.length()-i);
            break;
        }
    }
    
    return make_pair(u, v);
}

bool checkParentheses(string& p) {
    int count = 0;
    for (char ch : p) {
        if (count < 0) return false;
        (ch == '(') ? count++ : count--;
    }
    return count == 0;
}

string solution(string p) {
    // 1번 조건
    if (p.empty()) return "";
    
    // 2번 조건
    pair<string, string> splitData = splitParentheses(p);
    string u = splitData.first;
    string v = splitData.second;
    
    // 3번 조건
    if (checkParentheses(u)) {
        return u + solution(v);
    }
    
    // 4번 조건
    // 4-1, 4-2, 4-3 조건
    string answer = "(" + solution(v) + ")";
        
    // 4-4 조건
    u = u.substr(1, u.length()-2);
    for (char ch : u) {
        answer += (ch == '(') ? ")" : "(";
    }
    
    // 4-5 조건
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string p1 = "(()())()";
    cout << solution(p1) << '\n';
    
//    pair<string, string> answer1 = splitParentheses(p1);
//    cout << answer1.first << '\n';
//    cout << checkParentheses(answer1.first) << '\n';
//
//    cout << answer1.second << '\n';
//    cout << checkParentheses(answer1.second) << '\n';
//
//    cout << '\n';

    string p2 = "()";
    cout << solution(p2) << '\n';
    
//    pair<string, string> answer2 = splitParentheses(p2);
//    cout << answer2.first << '\n';
//    cout << checkParentheses(answer2.first) << '\n';
//
//    cout << answer2.second << '\n';
//    cout << checkParentheses(answer2.second) << '\n';
//
//    cout << '\n';
    
    string p3 = "()))((()";
    cout << solution(p3) << '\n';
    
//    pair<string, string> answer3 = splitParentheses(p3);
//    cout << answer3.first << '\n';
//    cout << checkParentheses(answer3.first) << '\n';
//
//    cout << answer3.second << '\n';
//    cout << checkParentheses(answer3.second) << '\n';
    
//    string p4 = ")(";
//    cout << p4.substr(1, p4.length() - 2) << '\n';
//
//    string p5 = "))((";
//    cout << p5.substr(1, p5.length() - 2) << '\n';
//
//    string p6 = "))((()";
//    cout << p6.substr(1, p6.length() - 2) << '\n';

    return 0;
}
