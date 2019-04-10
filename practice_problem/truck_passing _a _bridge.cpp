// 프로그래머스 - 다리를 지나는 트럭
// 문제를 이해했지만.. 구현을 하지 못해서 블로그를 참고하여 구현했다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int> > wait;
    for (int tw : truck_weights) wait.push(make_pair(tw, bridge_length));
    
    int sec = 0;
    deque<pair<int, int> > bridge;
    while (!(wait.empty() && bridge.empty())) {
        ++sec;
        
        // 1. 다리에 트럭이 있는지
        if (!bridge.empty() && bridge.front().second <= 0) {
            weight += bridge.front().first;
            bridge.pop_front();
        }
        
        // 2. 대기 상태의 트럭을 다리로 옮기기
        if (!wait.empty() && weight - wait.front().first >= 0) {
            weight -= wait.front().first;
            bridge.push_back(wait.front());
            wait.pop();
        }
        
        // 다리 내에서 해당 트럭은 +1 만큼 이동
        for (int i = 0; i < bridge.size(); i++) {
            bridge[i].second -= 1;
        }
    }
    
    return sec;
}

int main() {
    vector<int> truck_weights = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    cout << solution(100, 100, truck_weights) << '\n';
}

