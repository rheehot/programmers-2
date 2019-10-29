#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool compareTotalPlay(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

bool comparePlay(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 정보를 해시에 저장
    unordered_map<string, vector<pair<int, int> > > hashMap;
    
    int size = (int)genres.size();
    
    for (int i = 0; i < size; i++) {
        hashMap[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    // totalPlayCount 기준으로 정렬
    vector<pair<string, int> > tempInfo;
    for (auto p : hashMap) {
        string genre = p.first;
        
        vector<pair<int, int> > info = p.second;
        
        int totalPlay = 0;
        
        for (auto p2 : info) totalPlay += p2.second;
        
        tempInfo.push_back(make_pair(genre, totalPlay));
    }
    
    sort(tempInfo.begin(), tempInfo.end(), compareTotalPlay);
    
    // 장르 내에서 재생 횟수가 높은 순서대로 정렬하고 나서 정답을 구하기..
    // 정답을 구할 때 주의할 점!
    // 장르 내에 음악이 없을수도 있고, 1개만 있을수도 있다는 점을 고려하기
    vector<int> answer;
    
    for (auto p : tempInfo) {
        string genre = p.first;
        
        vector<pair<int, int> > temptempInfo = hashMap[genre];
        
        // 정렬 -> 고유 번호, 재생 횟수
        sort(temptempInfo.begin(), temptempInfo.end(), comparePlay);
    
        int tempSize = (int)temptempInfo.size();
        
        if (tempSize > 1) tempSize = 2;
        
        for (int i = 0; i < tempSize; i++) {
            answer.push_back(temptempInfo[i].first);
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> answer1 = solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
    
    for (int value : answer1) {
        cout << value << " ";
    }
    
    cout << '\n';
    
    vector<int> answer2 = solution({"classic", "pop", "classic", "pop", "classic", "classic"}, {400, 600, 150, 2500, 500, 500});
    
    for (int value : answer2) {
        cout << value << " ";
    }
    
    cout << '\n';
    
    return 0;
}
