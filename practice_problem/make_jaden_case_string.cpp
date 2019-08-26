// 프로그래머스 12951 - JadenCase 문자열 만들기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int i = 0;
    int sLength = (int)s.length();
    while (i < sLength) {
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
            if (s[i-1] == ' ') s[i] = toupper(s[i]);
            else if (i == 0) s[i] = toupper(s[i]);
            // 첫 문자를 대문자로 만들고 (숫자인 경우 제외)
            // 나머지 뒤에 있는 문자들을 소문자로 만든다.
            // 공백이 나오면 종료한다.
            int j = i + 1;
            while (j < sLength) {
                if (s[j] == ' ') break;
                else  s[j] = tolower(s[j]);
                j++;
            }
            // j 인덱스가 움직인 만큼 i 인덱스를 초기화 한다.
            i = j;
        } else i++;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("3people unFollowed me") << '\n';
    cout << solution("for the last week") << '\n';
    
    return 0;
}
