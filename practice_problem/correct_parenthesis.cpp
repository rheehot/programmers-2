#include <iostream>
#include <string>
using namespace std;

bool solution(string s)
{
    int count = 0;
    for (char ch : s) {
        // count가 음수가 되는것의 의미?
        // 1. 첫 번째 문자가 ')' 인 경우에는 무조건 올바르지 않은 괄호이다.
        // 2. '(' 보다 ')' 가 더 많아서 올바르지 않은 괄호이다.
        if (count < 0) return false;
        (ch == '(') ? count++ : count--;
    }
    return count == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("()()") << '\n';
    cout << solution("(())()") << '\n';
    cout << solution(")()(") << '\n';
    cout << solution("(()(") << '\n';
    cout << solution("))))))") << '\n';
    cout << solution("((((((") << '\n';
    cout << solution("((())))") << '\n';
    
    return 0;
}
