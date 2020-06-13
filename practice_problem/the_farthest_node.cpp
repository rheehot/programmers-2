#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int NODE_LIMIT_COUNT = 20001;

int solution(int n, vector<vector<int>> edge) {
    
    vector<int> adj[NODE_LIMIT_COUNT];
    
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist = vector<int>(n+1, -1);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    int maxDist = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i];
            
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                maxDist = max(maxDist, dist[next]);
                q.push(next);
            }
        }
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        if (maxDist == dist[i]) answer++;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int> > edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(6, edge) << '\n';
    
    return 0;
}