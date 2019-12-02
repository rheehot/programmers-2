#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<string> split(string str) {
    vector<string> result;
    
    for (int i = 0; i < str.length()-1; i++) {
        string s = str.substr(i, 2);
        
        // 영문에서 소문자, 대문자가 아닌 경우
        bool check = true;
        for (char ch : s) {
            if (('a' > ch || ch > 'z') && ('A' > ch || ch > 'Z')) {
                check = false;
                break;
            }
        }
        
        if (!check) continue;
        
        // 소문자를 영문자로 변환
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        
        result.push_back(s);
    }
    
    return result;
}

int solution(string str1, string str2) {
    vector<string> splitStr1 = split(str1);
    vector<string> splitStr2 = split(str2);
    
    if (splitStr1.empty() && splitStr2.empty()) {
        return 65536;
    }
    
    set<string> words;
    
    for (string s : splitStr1) words.insert(s);
    for (string s : splitStr2) words.insert(s);
    
    int intersectionCnt = 0;
    int unionCnt = 0;

    for (string s : words) {
        int cnt1 = 0;
        for (string s1 : splitStr1) {
            if (s == s1) cnt1++;
        }
        
        int cnt2 = 0;
        for (string s2 : splitStr2) {
            if (s == s2) cnt2++;
        }
        
        int minCnt = min(cnt1, cnt2);
        int maxCnt = max(cnt1, cnt2);
        
        intersectionCnt += minCnt;
        unionCnt += maxCnt;
    }
    
    double answer = (double)intersectionCnt / (double)unionCnt;
    
    return answer * 65536;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("FRANCE", "french") << '\n';
    cout << solution("handshake", "shake hands") << '\n';
    cout << solution("aa1+aa2", "AAAA12") << '\n';
    cout << solution("E=M*C^2", "e=m*c^2") << '\n';
    
    return 0;
}
