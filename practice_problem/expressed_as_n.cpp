// [ programmers level 3 ] [ 42985 - N으로 표현 ]
// 블로그를 참고했다..
// 완전 탐색(브루트 포스)으로 해결한 방법인데,
// set container에 조합 가능한 모든 수를 넣어서 판별하는 방법이다.
// set container를 이용한 완전 탐색의 새로운 방법을 알게 되었음
// level 3을 능숙하게 풀어야 기업 코딩 테스트에서 승산이 있는데..
// 열심히 해야한다.
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MAX = 8;

int solution(int N, int number) {
    // 최솟값이 8보다 크면 -1을 return
    int answer = -1, base = 0;
    
    // 주어진 N을 최대 8번 사용하여 만든다.
    unordered_set<int> numbers[MAX];
    for (int i = 0; i < MAX; i++) {
        base = 10 * base + N;
        numbers[i].insert(base);
    }
    
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < i; j++) {
            for (auto op1 : numbers[j]) {
                for (auto op2 : numbers[i - j - 1]) {
                    numbers[i].insert(op1 + op2);
                    numbers[i].insert(op1 - op2);
                    numbers[i].insert(op1 * op2);
                    if (op2 != 0) {
                        numbers[i].insert(op1 / op2);
                    }
                }
            }
        }
        
        if (numbers[i].count(number) > 0) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(5, 12) << '\n';
    cout << solution(2, 11) << '\n';
    cout << solution(5, 31168) << '\n';
    
    return 0;
}

