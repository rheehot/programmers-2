#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> check;
    
    for (int i = 0; i < words.size(); i++) {
        if (check.count(words[i]) != 0) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        
        check.insert(words[i]);
        
        if (i > 0) {
            int prevLastChar = words[i-1][words[i-1].length()-1];
            int curFirstChar = words[i][0];
            
            if (prevLastChar != curFirstChar) {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                break;
            }
        }
    }
    
    if (answer.empty()) {
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
    
    vector<string> words2 = {
        "hello", "observe", "effect", "take", "either",
        "recognize", "encourage", "ensure", "establish", "hang",
        "gather", "refer", "reference", "estimate", "executive"
    };
    vector<int> answer2 = solution(5, words2);
    cout << answer2[0] << " " << answer2[1] << '\n';
    
    return 0;
}
