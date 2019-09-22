// 프로그래머스 12980 - 점프와 순간 이동
// 이런 생각조차 하지도 못했음... 블로그 참고...
// 구현해서 풀 수 있을거라 생각했지만, 시간도 문제였고 풀이 방법도 틀렸다.
// 순간 이동은 2의 배수인 경우와 같다.
// 2의 배수가 아니면 -1을 감소시키고, 사용량을 +1 증가시킨다.
#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n -= 1;
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(5) << '\n';
    cout << solution(6) << '\n';
    cout << solution(5000) << '\n';
    
    return 0;
}
