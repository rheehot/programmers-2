// programmers 43163 - 단어 변환
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size());
    queue<pair<string, int> > q;
    q.push(make_pair(begin, 0));
    
    int answer = 0;
    while (!q.empty()) {
        string nowWord = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (nowWord == target) {
            answer = dist;
            break;
        }
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int sameCount = 0;
            int wordLength = (int)word.length();
            for (int j = 0; j < wordLength; j++) {
                if (nowWord[j] == word[j]) sameCount++;
            }
            
            if (!visited[i] && sameCount == wordLength-1) {
                visited[i] = true;
                q.push(make_pair(word, dist+1));
            }
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';
    
    return 0;
}
