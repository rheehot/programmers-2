// programmers 12985 - 예상 대진표
#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int round = 0;
    while (a != b) {
        // a와 b가 같은 대진표의 그룹이 아니기 때문에 round를 먼저 증가하고
        round++;
        // 다음 라운드의 번호를 부여한다.
        a = (a % 2) ? a / 2 + 1 : a / 2;
        b = (b % 2) ? b / 2 + 1 : b / 2;
    }
    return round;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(8, 4, 7) << '\n';
    
    return 0;
}
