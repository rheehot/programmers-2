// 프로그래머스 42626 - 더 맵게
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int val : scoville) pq.push(val);
    
    int answer = 0;
    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    
    if (pq.top() < K) answer = -1;
    
    return answer;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> scoville1 = {1, 2, 3, 9, 10, 12};
    cout << solution(scoville1, 7) << '\n';
    
    vector<int> scoville2 = {1, 2, 1, 5};
    cout << solution(scoville2, 100000) << '\n';
    
    return 0;
}
