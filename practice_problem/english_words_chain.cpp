// 프로그래머스 12981 - 영어 끝말잇기
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> us;
    vector<int> answer;
    string prev = "";
    bool ok = true;
    for (int i = 0; i < words.size(); i++) {
        if (us.count(words[i]) == 0) {
            if (i == 0) {
                us.insert(words[i]);
                prev = words[i];
            } else {
                if (prev[prev.length()-1] == words[i][0]) {
                    us.insert(words[i]);
                    prev = words[i];
                } else {
                    answer.push_back(i % n + 1);
                    answer.push_back(i / n + 1);
                    ok = false;
                    break;
                }
            }
        } else {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            ok = false;
            break;
        }
    }
    
    if (ok) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> words1 = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<int> answer1 = solution(3, words1);
    cout << answer1[0] << " " << answer1[1] << '\n';
    
    vector<string> words2 = {"hello", "observe", "effect", "take", "either", "recognize",
        "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
    vector<int> answer2 = solution(5, words2);
    cout << answer2[0] << " " << answer2[1] << '\n';
    
    vector<string> words3 = {"hello", "one", "even", "never", "now", "world", "draw"};
    vector<int> answer3 = solution(2, words3);
    cout << answer3[0] << " " << answer3[1] << '\n';
    
    return 0;
}
