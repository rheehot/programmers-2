#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill_trees.size(); i++) {
        string check_str = skill_trees[i];
        string make_str = "";
        for (int j = 0; j < check_str.length(); j++) {
            if (skill.find(check_str[j]) != string::npos) {
                make_str += check_str[j];
            }
        }
        string sub_skill_str = skill.substr(0, make_str.length());
        if (sub_skill_str.find(make_str) != string::npos) {
            ++answer;
        }
    }
    
    return answer;
}

// 두 번째 풀이
int solution2(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string skillTree : skill_trees) {
        string temp = "";
        for (char ch : skillTree) {
            if (skill.find(ch) != string::npos) {
                temp += ch;
            }
        }

        size_t tempLength = temp.length();
        if (skill.substr(0,  tempLength) == temp) {
            answer++;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string skill = "CBD";
    
    vector<string> skill_trees;
    skill_trees.push_back("BACDE");
    skill_trees.push_back("CBADF");
    skill_trees.push_back("AECB");
    skill_trees.push_back("BDA");
    
    cout << solution(skill, skill_trees) << '\n';
    cout << solution2(skill, skill_trees) << '\n';
    
    return 0;
}
