#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, int unit) {
    vector<string> splitData;
    int i = 0;
    int sLen = (int)s.length();
    while (i < sLen) {
        splitData.push_back(s.substr(i, unit));
        i += unit;
    }
    return splitData;
}

int solution(string s) {
    int halfSize = (int)s.length() / 2;
    int answer = (int)s.length();
    int unit = 1;
    while (unit <= halfSize) {
        vector<string> splitData = split(s, unit);
        
        string answerStr = "";
        int splitDataSize = (int)splitData.size();
        int i = 0;
        while (i < splitDataSize) {
            string prev = splitData[i];
            int overlapCount = 1;
            int j = i + 1;
            while (j < splitDataSize) {
                if (prev == splitData[j]) {
                    prev = splitData[j];
                    overlapCount++;
                } else {
                    i = j - 1;
                    break;
                }
                j++;
            }
            
            if (overlapCount > 1) {
                answerStr += to_string(overlapCount) + splitData[i];
            } else {
                answerStr += splitData[i];
            }
            
            if (j >= splitDataSize) {
                i = j;
            } else {
                i++;
            }
        }
        
        answer = min(answer, (int)answerStr.length());
        
        unit++;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // cout << solution("aabbaccc") << '\n';
    // cout << solution("ababcdcdababcdcd") << '\n';
    // cout << solution("abcabcdede") << '\n';
    //    cout << solution("abcabcabcabcdededededede") << '\n';
    cout << solution("xababcdcdababcdcd") << '\n';
    
    return 0;
}
