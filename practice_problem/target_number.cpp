// 프로그래머스 43165 - 타켓 넘버
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

// Data가 많은 경우에서는 DFS로 구현한 코드가 BFS로 구현한 코드보다 약 3배 빠름
// 이 코드에서 그렇다는 것이지 DFS가 BFS보다 빠른 알고리즘이라는 것이 아님
// BFS          DFS
// 22.43ms      6.58ms
// 20.93ms      6.49ms
// Data가 적은 경우에서는 별 차이 없음

// DFS 풀이
int dfs(vector<int>& numbers, int target, int index, int value) {
    if (index == numbers.size()) {
        if (value == target) return 1;
        else return 0;
    }
    int answer = 0;
    answer += dfs(numbers, target, index + 1, value + numbers[index]);
    answer += dfs(numbers, target, index + 1, value - numbers[index]);
    return answer;
}

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
    //    return bfs(numbers, target);
    return dfs(numbers, target, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers, 3) << '\n';
    
    return 0;
}
