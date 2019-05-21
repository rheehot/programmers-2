#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    stack<char> st;
    for (int i = 0; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') st.push(arrangement[i]);
        else if (arrangement[i] == ')') {
            st.pop();
            if (arrangement[i-1] == '(') answer += st.size();
            else answer++;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("()(((()())(())()))(())") << '\n';
    cout << solution("(()()(()))") << '\n';
    
    return 0;
}
