// 프로그래머스 42890 - 후보키
// 굉장히 어렵다...
// 거의 코드 복붙 수준으로 참고했다...
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void makeCombination(vector<vector<int> >& combinations, vector<int> order, vector<int> value, int index, int columnSize, bool flag) {
    if (index == columnSize) return;
    if (flag) {
        value.push_back(order[index]);
        combinations.push_back(value);
    }
    makeCombination(combinations, order, value, index + 1, columnSize, false);
    makeCombination(combinations, order, value, index + 1, columnSize, true);
}

bool sortCombinations(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

bool unionFunc(set<int> a, set<int> b) {
    int count = 0;
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        if (b.find(*iter) != b.end()) {
            count++;
        }
    }
    if (count == a.size()) return true;
    return false;
}

int solution(vector<vector<string>> relation) {
    // 1. 모든 조합을 만든다.
    vector<vector<int> > combinations;
    vector<int> order, value;
    
    int relationRowSize = (int)relation.size();
    int relationColSize = (int)relation[0].size();
    
    // 속성의 인덱스를 order 배열에 저장
    // order값으로 조합을 만든다.
    for (int i = 0; i < relationColSize; i++) {
        order.push_back(i);
    }
    
    // 재귀 함수를 통해 조합을 만든다.
    makeCombination(combinations, order, value, 0, relationColSize, true);
    makeCombination(combinations, order, value, 0, relationColSize, false);
    
    sort(combinations.begin(), combinations.end(), sortCombinations);
    
    // 2. 유일성 걸러내기
    vector<set<int> > result;
    int combinationsRowSize = (int)combinations.size();
    for (int r = 0; r < combinationsRowSize; r++) {
        // columns의 값을 key에 담아 중복된 것이 있는지 확인하고,
        // 이를 통해서 유일성을 걸러낼 수 있다.
        map<vector<string>, bool> columnsValueMap;
        int combinationsColSize = (int)combinations[r].size();
        bool flag = false;
        for (int rR = 0; rR < relationRowSize; rR++) {
            vector<string> columnsValue;
            for (int c = 0; c < combinationsColSize; c++) {
                columnsValue.push_back(relation[rR][combinations[r][c]]);
            }
            if (columnsValueMap[columnsValue]) {
                flag = true;
                break;
            }
            columnsValueMap[columnsValue] = true;
        }
        
        set<int> columnsIndex;
        if (!flag && columnsValueMap.size() == relationRowSize) {
            for (int c = 0; c < combinationsColSize; c++) {
                columnsIndex.insert(combinations[r][c]);
            }
            result.push_back(columnsIndex);
        }
    }
    
    // 3. 최소성 만족하기
    // 남은 부분집합들은 부분집합끼리 포함되는 관계에서 포함시키는 부분을 제거해야 최소성을 만족시킨다.
    int answer = 0;
    for (int i = 0; i < result.size(); i++) {
        answer++;
        for (int j = i+1; j < result.size(); j++) {
            if (unionFunc(result[i], result[j])) {
                result.erase(result.begin() + j);
                j--;
            }
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<string> > data = {
        {"100","ryan","music","2"},
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2"}
    };
    
    cout << solution(data) << '\n';
    return 0;
}
