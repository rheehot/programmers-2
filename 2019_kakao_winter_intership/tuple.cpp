#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(string s) {
    size_t sLen = s.length();
    string tempS = s.substr(1, sLen - 2);

    vector<vector<int> > arr;
    
    int i = 0;
    while (i < tempS.length()) {
        if (tempS[i] == '{') {
            queue<int> q;
            
            int j = i + 1;
            while (tempS[j] != '}') {
                if (tempS[j] != ',') {
                    int k = j;
                    int cnt = 1;
                    while (tempS[j] != '}' && tempS[j] != ',') {
                        cnt++;
                        j++;
                    }
                    q.push(stoi(tempS.substr(k, cnt)));
                } else j++;
            }
            
            vector<int> tempArr;
            while (!q.empty()) {
                tempArr.push_back(q.front());
                q.pop();
            }
            
            arr.push_back(tempArr);
            
            i = j + 1;
        } else i++;
    }
    
    sort(arr.begin(), arr.end(), [](vector<int> first, vector<int> second) -> bool {
        return first.size() < second.size();
    });
    
    set<int> check;
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (check.count(arr[i][j])) continue;
            answer.push_back(arr[i][j]);
            check.insert(arr[i][j]);
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> a1 = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int a : a1) {
        cout << a << " ";
    }
    cout << '\n';
    
    vector<int> a2 = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (int a : a2) {
        cout << a << " ";
    }
    cout << '\n';
    
    vector<int> a3 = solution("{{20,111},{111}}");
    for (int a : a3) {
        cout << a << " ";
    }
    cout << '\n';
    
    vector<int> a4 = solution("{{123}}");
    for (int a : a4) {
        cout << a << " ";
    }
    cout << '\n';
    
    vector<int> a5 = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (int a : a5) {
        cout << a << " ";
    }
    cout << '\n';
    
    return 0;
}

