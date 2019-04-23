// Summer Coding - 배달
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int> > >& adj, int N) {
    const int INF = 0x7FFFFFFF;
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int curCost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (dist[cur] < curCost) continue;
        
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int nextCost = adj[cur][i].second + curCost;
            
            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }
    }
    
    return dist;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int> > > adj(N+1);
    for (int i = 0; i < road.size(); i++) {
        adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    vector<int> dist = dijkstra(adj, N);
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] <= K) answer++;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int > > road(5);
    road[0].push_back(1);
    road[0].push_back(2);
    road[0].push_back(1);
    
    road[1].push_back(2);
    road[1].push_back(3);
    road[1].push_back(3);
    
    road[2].push_back(5);
    road[2].push_back(2);
    road[2].push_back(2);
    
    road[3].push_back(1);
    road[3].push_back(4);
    road[3].push_back(2);
    
    road[4].push_back(5);
    road[4].push_back(3);
    road[4].push_back(1);
    
    road[4].push_back(5);
    road[4].push_back(4);
    road[4].push_back(2);
    
    
    int answer = solution(5, road, 3);
    cout << answer << '\n';
    return 0;
}

