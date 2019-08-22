// 프로그래머스 43165 - 타켓 넘버
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

// BFS 풀이
int bfs(vector<int>& numbers, int target) {
    queue<pair<int, int> > q;
    q.push(make_pair(-1, 0));
    
    int answer = 0;
    int numberSize = (int)numbers.size();
    while (!q.empty()) {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        
        if (index == numberSize) break;
        if (index == numberSize - 1 && value == target) {
            answer++;
        }
        
        q.push(make_pair(index+1, value + numbers[index+1]));
        q.push(make_pair(index+1, value - numbers[index+1]));
    }
    
    return answer;
}

int solution(vector<int> numbers, int target) {
    return bfs(numbers, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers, 3) << '\n';
    
    return 0;
}
