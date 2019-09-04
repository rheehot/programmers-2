// 프로그래머스 42888 - 오픈 채팅방
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> parseByWhiteSpace(string info) {
    vector<string> parseData;
    int length = 0;
    int stdIndex = 0;
    int infoLength = (int)info.length();
    for (int i = 0; i < infoLength; i++) {
        if (info[i] == ' ') {
            parseData.push_back(info.substr(stdIndex, length));
            stdIndex = i + 1;
            length = 0;
        } else length++;
    }
    parseData.push_back(info.substr(stdIndex, length));
    return parseData;
}

string print(string command, string nickName) {
    if (command == "Enter") return nickName + "님이 들어왔습니다.";
    return nickName + "님이 나갔습니다.";
}

vector<string> solution(vector<string> record) {
    enum { COMMAND = 0, USER_ID = 1, NICKNAME = 2 };
    unordered_map<string, string> userInfo;
    vector<pair<string, string> > userTemp;
    for (string info : record) {
        vector<string> parseData = parseByWhiteSpace(info);
        if (parseData[COMMAND] == "Enter" || parseData[COMMAND] == "Change") {
            userInfo[parseData[USER_ID]] = parseData[NICKNAME];
        }
        if (parseData[COMMAND] == "Enter" || parseData[COMMAND] == "Leave") {
            userTemp.push_back(make_pair(parseData[COMMAND], parseData[USER_ID]));
        }
    }
    
    vector<string> answer;
    for (auto temp : userTemp) {
        answer.push_back(print(temp.first, userInfo[temp.second]));
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> answer = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"});
    for (string ans : answer) {
        cout << ans << '\n';
    }
    
    return 0;
}
