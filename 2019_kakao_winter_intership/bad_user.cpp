#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string> > totalCheck;
int answer = 0;

bool isMatch(string bid, string uid) {
    if (bid.length() != uid.length()) return false;
    
    for (int i = 0; i < bid.length(); i++) {
        if (bid[i] != uid[i] && bid[i] != '*') return false;
    }
    
    return true;
}

void dfs(set<string>& check, vector<vector<string> >& candidates, int i) {
    if (candidates.size() == i) {
        if (candidates.size() != check.size()) return;
        for (auto it = totalCheck.begin(); it != totalCheck.end(); it++) {
            if (*it == check) return;
        }
        totalCheck.insert(check);
        answer++;
        return;
    }
    
    for (int j = 0; j < candidates[i].size(); j++) {
        string candidate = candidates[i][j];
        if (!check.count(candidate)) {
            check.insert(candidate);
            dfs(check, candidates, i + 1);
            check.erase(check.find(candidate));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string> > candidates;
    for (string bid : banned_id) {
        vector<string> tempCandidates;
        for (string uid : user_id) {
            if (isMatch(bid, uid)) {
                tempCandidates.push_back(uid);
            }
        }
        candidates.push_back(tempCandidates);
    }
    
    set<string> check;
    dfs(check, candidates, 0);
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> user_id1 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id1 = {"fr*d*", "abc1**"};
    cout << solution(user_id1, banned_id1) << '\n';
    
    totalCheck.clear();
    answer = 0;

    vector<string> user_id2 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id2 = {"*rodo", "*rodo", "******"};
    cout << solution(user_id2, banned_id2) << '\n';
    
    totalCheck.clear();
    answer = 0;
    
    vector<string> user_id3 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id3 = {"fr*d*", "*rodo", "******", "******"};
    cout << solution(user_id3, banned_id3) << '\n';
    
    return 0;
}

