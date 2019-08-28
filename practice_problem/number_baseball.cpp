// 프로그래머스 42841 - 숫자 야구
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > baseball) {
    string src = "";
    string dst = "";
    int answer = 0;
    for (int num = 123; num <= 987; num++) {
        src = to_string(num);
        // 같은 숫자가 존재하면 contiue
        if (src[0] == src[1] || src[0] == src[2] || src[1] == src[2]) {
            continue;
        }
        // 숫자중에 0이 있으면 continue
        if (src[0] == '0' || src[1] == '0' || src[2] == '0') {
            continue;
        }
        
        bool ok = true;
        for (int i = 0; i < baseball.size(); i++) {
            dst = to_string(baseball[i][0]);
            int strike = 0, ball = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k && src[j] == dst[k]) {
                        strike++;
                        continue;
                    }
                    if (j != k && src[j] == dst[k]) {
                        ball++;
                        continue;
                    }
                }
            }
            if (baseball[i][1] != strike || baseball[i][2] != ball) {
                ok = false;
                break;
            }
        }
        
        if (ok) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > baseball = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};
    cout << solution(baseball) << '\n';
    
    return 0;
}
