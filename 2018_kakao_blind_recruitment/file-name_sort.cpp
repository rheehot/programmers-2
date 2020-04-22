// c++의 sort 함수는 퀵정렬이고, 불안정 정렬이다.
// stable_sort 함수는 병합정렬이고, 안정 정렬이다.
// 우선 불안정 정렬은 같은 데이터를 비교할 때, 기존의 순서가 바뀔 수 있기 때문에 원래의 순서를 보장할 수 없다.
// 안정 정렬의 같은 경우에는 같은 데이터를 비교할 때, 기존의 순서가 유지된다.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<tuple<string, int, string>, string> pairTuple;

vector<string> solution(vector<string> files) {
    vector<pair<tuple<string, int, string>, string> > datas;
    for (string file : files) {
        size_t fileLen = file.length();
        
        int i = 0;
        while (i < fileLen) {
            if (('0' <= file[i] && file[i] <= '9')) {
                break;
            }
            i++;
        }
        
        string head = file.substr(0, i);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        
        int fixI = i;
        while (i < fileLen) {
            if (('a' <= file[i] && file[i] <= 'z') ||
                ('A' <= file[i] && file[i] <= 'Z') ||
                file[i] == ' ' || file[i] == '.' || file[i] == '-') {
                break;
            }
            i++;
        }
        
        int number = stoi(file.substr(fixI, i - fixI));
        string tail = file.substr(i, fileLen - i);
        
        datas.push_back(make_pair(make_tuple(head, number, tail), file));
    }
    
    stable_sort(datas.begin(), datas.end(), [](pairTuple a, pairTuple b) -> bool {
        string headA, headB;
        int numberA, numberB;
        
        tie(headA, numberA, ignore) = a.first;
        tie(headB, numberB, ignore) = b.first;
        
        if (headA == headB) return numberA < numberB;
        
        return headA < headB;
    });
    
    vector<string> answer;
    for (auto data : datas) {
        string file = data.second;
        answer.push_back(file);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> answer = solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
    for (string file : answer) {
        cout << file << '\n';
    }
    cout << '\n';

    vector<string> answer1 = solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
    for (string file : answer1) {
        cout << file << '\n';
    }
    cout << '\n';
    
    vector<string> answer2 = solution({"foo9.txt", "foo010bar020.zip", "F-15"});
    for (string file : answer2) {
        cout << file << '\n';
    }
    cout << '\n';

    vector<string> answer3 = solution({"F-15", "f15", "F15.png" });
    for (string file : answer3) {
        cout << file << '\n';
    }
    cout << '\n';
    
    return 0;
}

