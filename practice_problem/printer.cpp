#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int> > q;
    vector<int> priorityCount(10);
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        priorityCount[priorities[i]]++;
    }
    
    int answer = 1;
    while (!q.empty()) {
        int index = q.front().first;
        int curPriority = q.front().second;
        q.pop();
        
        bool isExist = false;
        for (int priority = curPriority+1; priority <= 9; priority++) {
            if (priorityCount[priority] > 0) {
                q.push(make_pair(index, curPriority));
                isExist = true;
                break;
            }
        }
        
        if (!isExist) {
            if (index == location) break;
            priorityCount[curPriority]--;
            answer++;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({2, 1, 3, 2}, 2) << '\n';
    cout << solution({1, 1, 9, 1, 1, 1}, 0) << '\n';
    
    return 0;
}
