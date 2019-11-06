#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int sLength = (int)s.length();
    int answer = sLength;
    
    for (int unit = 1; unit <= sLength; unit++) {
        string words = s.substr(0, unit);
        string str = "";
        
        // unit 단위로 자르기
        int wordsCount = 1;
        for (int i = unit; i < sLength; i+=unit) {
            // unit 단위로 자르기 때문에 for문을 통해 문자열이 일치하는지 체크한다.
            bool ok = true;
            for (int k = 0 ; k < words.length(); k++) {
                if (words[k] != s[i + k]) {
                    ok = false;
                    break;
                }
            }
            
            // 문자열이 일치하면 카운트 증가
            if (ok) wordsCount++;
            else {
                // 문자열이 일치하지 않으면 압축된 문자열 만들기
                // 주의할 점은 문자가 1개이면, 압축된 문자열에 포함시키지 않는다.
                if (wordsCount > 1) str += to_string(wordsCount);
                str += words;
                words = s.substr(i, unit);
                wordsCount = 1;
            }
        }
        
        // 마지막 남은 문자를 압축된 문자열에 더한다.
        if (wordsCount > 1) str += to_string(wordsCount);
        str += words;
        
        answer = min(answer, (int)str.length());
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("aabbaccc") << '\n';
    cout << solution("ababcdcdababcdcd") << '\n';
    cout << solution("abcabcdede") << '\n';
    cout << solution("abcabcabcabcdededededede") << '\n';
    cout << solution("xababcdcdababcdcd") << '\n';
    
    return 0;
}
