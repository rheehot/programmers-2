#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 다른 사람 풀이중에 정렬후, 비교하는 방법을 사용한 풀이가 있었다.
// 참신해서 풀어봤다. 속도는 hashmap으로 푼 것보다 느리다.
string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) return participant[i];
    }
    
    return participant[participant.size()-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> participant1 = {"leo", "kiki", "eden"};
    vector<string> participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> participant3 = {"mislav", "stanko", "mislav", "ana"};
    
    vector<string> completion1 = {"eden", "kiki"};
    vector<string> completion2 = {"josipa", "filipa", "marina", "nikola"};
    vector<string> completion3 = {"stanko", "ana", "mislav"};
    
    cout << solution(participant1, completion1) << '\n';
    cout << solution(participant2, completion2) << '\n';
    cout << solution(participant3, completion3) << '\n';
    
    return 0;
}
