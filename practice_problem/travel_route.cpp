/*
 주어진 모든 항공권을 다 써야하는게 핵심 -> 즉, DFS에 백트래킹 문제이다.
 또한, 똑같은 항공권이 존재할 수 있기 때문에 map<pair<string, string>, boolean> visited 으로
 선언하지 말고 map<pair<string string>, int> visited 으로 선언 해야하고,
 그래프를 만들때 항공권의 갯수만큼 초기화 해야한다.

 ex)
 티켓 : [["ICN", "COO"], ["ICN", "BOO"], ["COO", "ICN"], ["BOO", "DOO"]]
 결과 : ["ICN", "COO", "ICN", "BOO", "DOO"]

 그런데 알파벳 순으로 정렬만 해놓고 문제를 해결한다면, ["ICN, BOO, DOO"]가 된다. 문제의 조건에 맞춰서
 주어진 모든 항공권을 다 써야하기 때문에 "현재 이동 횟수 == 티켓의 수" 일때 해당 경로를 반환해야 한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;

vector<string> answer;
map<string, vector<string> > adj;
map<pair<string, string>, int> visited;

void dfs(string current) {
    answer.push_back(current);
    
    if (answer.size() == n + 1) return;
    
    for (int i = 0; i < adj[current].size(); i++) {
        string next = adj[current].at(i);
        
        if (visited[{ current, next }] != 0) {
            visited[{ current, next }]--;
            
            dfs(next);
            
            if (answer.size() == n + 1) return;
            
            visited[{ current, next }]++;
        }
    }
    
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    n = (int)tickets.size();
    
    for (int i = 0; i < tickets.size(); i++) {
        string start = tickets[i][0];
        string arrive = tickets[i][1];
        adj[start].push_back(arrive);
        visited[{ start, arrive }]++;
    }
    
    for (auto iter = adj.begin(); iter != adj.end(); iter++) {
        sort(adj[iter->first].begin(), adj[iter->first].end());
    }
    
    dfs("ICN");
    
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<string> > tickets1 = {
        {"ICN", "JFK"},
        {"HND", "IAD"},
        {"JFK", "HND"}
    };

    vector<string> answer1 = solution(tickets1);

    for (string answer : answer1) {
        cout << answer << '\n';
    }
    cout << '\n';

    answer.clear();
    visited.clear();
    adj.clear();

    vector<vector<string> > tickets2 = {
        {"ICN", "SFO"},
        {"ICN", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "ICN"},
        {"ATL", "SFO"}
    };

    vector<string> answer2 = solution(tickets2);

    for (string answer : answer2) {
        cout << answer << '\n';
    }
    cout << '\n';

    answer.clear();
    visited.clear();
    adj.clear();
    
    vector<vector<string> > tickets3 = {
        {"ICN", "BOO"},
        {"ICN", "COO"},
        {"COO", "DOO"},
        {"DOO", "COO"},
        {"BOO", "DOO"},
        {"DOO", "BOO"},
        {"BOO", "ICN"},
        {"COO", "BOO"}
    };
    
    vector<string> answer3 = solution(tickets3);
    
    for (string answer : answer3) {
        cout << answer << '\n';
    }
    cout << '\n';
    
    answer.clear();
    visited.clear();
    adj.clear();
    
    return 0;
}
