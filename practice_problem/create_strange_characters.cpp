#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 1;
    for (int i = 0; i < s.length(); i++, index++) {
        if (s[i] == ' ') {
            answer += " ";
            index = 0;
            continue;
        }
        (index & 1) ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("try hello world") << '\n';
    return 0;
}
