// programmers 12973 - 짝지어 제거하기
// 스택을 이용해서 풀기
// 괄호 문제를 연상해서 풀었음
// 가능한 이유? 알파벳이 2개 붙어 있는 짝을 찾는다. -> '()' 를 찾는 것과 같다.
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    return (st.empty()) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("baabaa") << '\n';
    cout << solution("cdcd") << '\n';
    
    return 0;
}
