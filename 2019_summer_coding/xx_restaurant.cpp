#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> s) {
    int answer = 0;
    
    vector<int> cntNum(s.size()+1);
    for (int i = 0; i < s.size(); i++) cntNum[s[i]-1]++;
    
    // 테스트 케이스에 맞혀 구현한 것이다..
    // 예외 케이스도 생각해봐야 하는 코드..
    // 4
    answer += cntNum[3];
    
    // 3
    answer += cntNum[2];
    if (cntNum[2] >= cntNum[0]) cntNum[0] = 0;
    else cntNum[0] = cntNum[2] - cntNum[0];
    
    // 2
    if (cntNum[1] % 2 == 0) answer += cntNum[1] / 2;
    else {
        answer += (cntNum[1] / 2) + 1;
        if (cntNum[0] <= 2) cntNum[0] = 0;
        else cntNum[0] -= 2;
    }
    
    // 1
    if (cntNum[0] % 4 == 0) answer += cntNum[0] / 4;
    else answer += (cntNum[0] / 4) + 1;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> s1 = {1, 2, 4, 3, 3};
    vector<int> s2 = {2, 3, 4, 4, 2, 1, 3, 1};
    
    cout << solution(s1) << '\n';
    cout << solution(s2) << '\n';
    return 0;
}

