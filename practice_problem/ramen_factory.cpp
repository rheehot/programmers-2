// 프로그래머스 42629 - 라면공장
// 문제의 핵심
// 밀가루를 공급하는 시점에서 밀가루를 추가할지 말지를 결정하는 것이 아닌 밀가루가 부족해지는 시점에 추가하는 방식
// 밀가루를 공급받는 날이 되면 일단 우선순위 큐에 공급 받을 수 있는 밀가루의 양을 넣는다.
// 그리고 밀가루가 필요하면 우선순위 큐에서 꺼낸다. 이때 우선순위 큐 위에는 가장 많은 양의 밀가루가 들어있다.
// 따라서 밀가루를 공급받는 횟수를 최소로 만든다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int> pq;
    int answer = 0, index = 0;
    for (int day = 0; day < k; day++) {
        if (index < dates.size() && day == dates[index]) {
            pq.push(supplies[index++]);
        }
        
        if (stock == 0) {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        
        stock -= 1;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(4, {4, 10, 15}, {20, 5, 10}, 30) << '\n';
    return 0;
}
