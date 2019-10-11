// 문제의 카테고리는 탐욕법이지만, 보자마자 '최소 스패닝 트리'가 생각났다.
// 예전에 최소 스패닝 트리 알고리즘은 구현 방법이 2가지가 있다.
// '크루스칼', '프림' 알고리즘이다. 개인적으로 '프림' 알고리즘이 더 쉬워보여서 적용해서 해결했다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;
const int MAX_V = 100;
// 그래프의 인접 리스트 (연결된 정점의 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];

int prim(int n) {
    vector<pair<int, int> > selected;
    vector<bool> added(n, false);
    
    vector<int> minWeight(n, INF);
    vector<int> parent(n, -1);
    
    int cost = 0;
    minWeight[0] = parent[0] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }
        
        // (parent[u], u)를 트리에 추가 한다.
        if (parent[u] != u) selected.push_back(make_pair(parent[u], u));
    
        cost += minWeight[u];
        added[u] = true;
        
        // u에 인접한 간선 (u, v)들을 검사 한다.
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (!added[v] && minWeight[v] > w) {
                minWeight[v] = w;
                parent[v] = u;
            }
        }
    }
    
    return cost;
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int c = costs[i][2];
        
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    
    return prim(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
    cout << solution(4, costs) << '\n';
    
    return 0;
}
