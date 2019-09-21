#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

void go(int now, vector<vector<int> >& computers) {
    for (int i = 0; i < computers[now].size(); i++) {
        if (now == i) continue;
        if (!visited[i] && computers[now][i] == 1) {
            visited[i] = true;
            go(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited = vector<bool>(computers.size());
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            go(i, computers);
            answer++;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > computers1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    cout << solution(3, computers1) << '\n';
    
    vector<vector<int> > computers2 = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    
    cout << solution(3, computers2) << '\n';
    
    return 0;
}
