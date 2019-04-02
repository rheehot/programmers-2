#include <iostream>
using namespace std;

long long solution(int a, int b) {
    // 1. a 와 b 가 같은지??
    if (a == b) return a;
    
    // 2. 대소 비교
    int start = 0, end = 0;
    if (a < b) {
        start = a;
        end = b;
    } else if (a > b) {
        start = b;
        end = a;
    }
    
    // 3. 모든 값을 더해준다.
    long long answer = 0;
    for (int i = start; i <= end; i++) {
        answer += i;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    cout << solution(a, b) << '\n';
    
    return 0;
}

