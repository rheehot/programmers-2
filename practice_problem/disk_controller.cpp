// 프로그래머스 42627 - 디스크 컨트롤러
// 너무 어렵다.. 다시 풀어본 후, 정리하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Disk {
    int requestTime;
    int processTime;
};

struct Cmp1 {
    bool operator()(Disk d1, Disk d2) {
        return d1.processTime > d2.processTime;
    }
};

bool cmp2(Disk& d1, Disk& d2) {
    return d1.requestTime < d2.requestTime;
}

int solution(vector<vector<int>> jobs) {
    priority_queue<Disk, vector<Disk>, Cmp1> pq;
    
    vector<Disk> disks;
    int jobsSize = (int)jobs.size();
    for (int i = 0; i < jobsSize; i++) {
        Disk disk = {jobs[i][0], jobs[i][1]};
        disks.push_back(disk);
    }
    
    sort(disks.begin(), disks.end(), cmp2);
    
    int totalTime = 0;
    int initTime = disks[0].requestTime;
    for (Disk disk : disks) {
        disk.requestTime -= initTime;
        totalTime += disk.processTime + disk.requestTime;
    }
    
    int index = 0;
    int answer = 0;
    int prevTime = 0;
    int currenJob = 0;
    for (int currentTime = 0; currentTime <= totalTime; currentTime++) {
        // 같은 시간에 요청하는 시간이 여러 개 있는 경우를 생각해야 한다.
        // while문 통해 현재 요청 시간을 모두 우선순위 큐에 담는다.
        while (index < disks.size() && currentTime == disks[index].requestTime) {
            pq.push(disks[index++]);
        }
        
        // 작업 처리하기
        if (currenJob == 0 && !pq.empty()) {
            currenJob = pq.top().processTime;
            answer += pq.top().processTime - pq.top().requestTime + prevTime;
            pq.pop();
        }
        
        if (currenJob > 0) currenJob--;
        
        prevTime++;
    }
    
    return answer / jobsSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({{0, 3}, {1, 9}, {2, 6}}) << '\n';
    cout << solution({{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}) << '\n';
    cout << solution({{0, 5}, {1, 2}, {5, 5}}) << '\n';
    return 0;
}
