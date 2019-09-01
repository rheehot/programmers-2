// 프로그래머스 42885 - 구명보트
// 맨 처음 정렬을 한다.
// 가장 작은 원소와 큰 원소를 더 했을때 limit 값을 넘는지 확인 한다.
// 50, 50, 70, 80 의 값이 있다면,
// 50 + 80 을 더한다. 이 때 더한 값(130)이 limit(100)를 초과한다. 따라서 80의 원소는 혼자 타야한다. (answer++)
// 끝 인덱스(end)를 -1 감소한다.
// 50 + 70 을 더한다. 이 때 더한 값(120)이 limit(100)를 초과한다. 따라서 70의 원소는 혼자 타야한다. (answer++)
// 끝 인덱스(end)를 -1 감소한다.
// 50 + 50 을 더한다. 이 때 더한 값이(100)이고 limit(100)와 동일하다. 따라서 두 사람은 같이 탈 수 있다. (answer++)
// 시작 인덱스(start)를 +1 증가한다.
// 끝 인덱스(end)를 -1 감소한다.
// 마지막으로 예외인 경우가 있다.
// 원소의 개수가 홀수이면서 양 끝에 있는 원소들이 짝을 이루었다면, 중간에 마지막 남은 사람이 존재하는데
// 이것을 처리 해줘야 한다. (start == end) answer++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int peopleSize = (int)people.size();
    int answer = 0;
    int start = 0, end = peopleSize - 1;
    while (end > start) {
        if (people[start] + people[end] <= limit) {
            answer++;
            start++;
        } else {
            answer++;
        }
        end--;
    }
    
    if (start == end) answer++;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({40, 50, 20, 40}, 100) << '\n';
    cout << solution({120, 90, 70, 30, 20}, 150) << '\n';
    cout << solution({70, 50, 80, 50}, 100) << '\n';
    cout << solution({70, 80, 50}, 100) << '\n';
    
    return 0;
}
