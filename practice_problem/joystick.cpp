// programmers 42860 - 조이스틱
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
int minMove;

// 커서를 오른쪽으로 이동하면서, 현재 위치에서 'A'를 제외한 가장 가까운 문자를 찾는다.
pair<int, int> searchRight(string& name, int index) {
    size_t nameLength = name.length();
    int rightMove = 0, rightIndex = 0;
    for (int mv = 1; mv < nameLength; mv++) {
        rightIndex = index + mv;
        if (rightIndex >= nameLength) rightIndex -= nameLength;
        if (name[rightIndex] != 'A' && !visited[rightIndex]) {
            rightMove = mv;
            break;
        }
    }
    return make_pair(rightMove, rightIndex);
}

// 커서를 왼쪽으로 이동하면서, 현재 위치에서 'A'를 제외한 가장 가까운 문자를 찾는다.
pair<int, int> searchLeft(string& name, int index) {
    size_t nameLength = name.length();
    int leftMove = 0, leftIndex = 0;
    for (int mv = 1; mv < nameLength; mv++) {
        leftIndex = index - mv;
        if (leftIndex < 0) leftIndex += nameLength;
        if (name[leftIndex] != 'A' && !visited[leftIndex]) {
            leftMove = mv;
            break;
        }
    }
    return make_pair(leftMove, leftIndex);
}

void go(string& name,  int remainingCount, int index, int currentMove) {
    // 'A'를 제외한 나머지 문자를 모두 체크한 경우
    if (remainingCount == 0) {
        // 이동한 값 중에서 최소 값을 구한다.
        if (minMove == -1 || minMove > currentMove) {
            minMove = currentMove;
        }
        return;
    }
    
    pair<int, int> rightInfo = searchRight(name, index);
    pair<int, int> leftInfo = searchLeft(name, index);
    
    int rightMove = rightInfo.first, rightIndex = rightInfo.second;
    int leftMove = leftInfo.first, leftIndex = leftInfo.second;
    
    // 왼쪽으로 이동한 횟수와 오른쪽으로 이동한 횟수의 경우에는 둘 다 DFS 탐색을 해본다.
    if (rightMove == leftMove) {
        if (!visited[rightIndex]) {
            visited[rightIndex] = true;
            go(name, remainingCount - 1, rightIndex, currentMove + rightMove);
            visited[rightIndex] = false;
        }
        
        if (!visited[leftIndex]) {
            visited[leftIndex] = true;
            go(name, remainingCount - 1, leftIndex, currentMove + leftMove);
            visited[leftIndex] = false;
        }
    } else {
        // 왼쪽으로 이동한 횟수와 오른쪽으로 이동한 횟수가 다르다면 (rightMove < leftMove 또는 rightMove > leftMove)
        // 적게 이동한 방향으로 탐색을 시작하여 최적의 해를 찾는다.
        int nextMove = 0, nextIndex = 0;
        if (rightMove < leftMove) {
            nextMove = currentMove + rightMove;
            nextIndex = rightIndex;
        } else {
            nextMove = currentMove + leftMove;
            nextIndex = leftIndex;
        }
        
        if (!visited[nextIndex]) {
            visited[nextIndex] = true;
            go(name, remainingCount - 1, nextIndex, nextMove);
            visited[nextIndex] = false;
        }
    }
}

int solution(string name) {
    int nameLength = (int)name.length();
    int answer = 0, aCount = 0;
    // 문자를 변환하는 조이스틱을 미리 계산한다.
    for (char ch : name) {
        if (ch == 'A') {
            aCount++;
            continue;
        }
        answer += min(ch - 'A', 26 - ch + 'A');
    }
    
    // 모두 A이면, 조작해야하는 경우가 없으므로 0을 리턴
    if (aCount == nameLength) return 0;
    
    // A가 하나도 없는 경우에는 차례대로 조이스틱을 조작하면 된다.
    if (aCount == 0) return answer + nameLength - 1;
    
    // A를 제외한 나머지 문자
    int remainingCount = nameLength - aCount;
    
    // 처음 시작이 A가 아닌 경우에는 count를 1 감소시켜야 한다.
    if (name[0] != 'A') remainingCount--;
    
    // 방문 여부 체크를 위함
    visited = vector<bool>(nameLength);
    visited[0] = true;
    
    // 백트래킹을 활용해서 좌,우로 이동하는 최적의 값을 계산
    minMove = -1;
    go(name, remainingCount, 0, 0);
    
    // 문자를 변환하기 위해 조작한 횟수 + 커서를 이동하기 위해 조작한 횟수
    return answer + minMove;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("ABAAABB") << '\n';
    cout << solution("JAZ") << '\n';
    cout << solution("AZAAAZ") << '\n';
    cout << solution("ABAAAB") << '\n';
    cout << solution("AAAZAAZA") << '\n';
    cout << solution("ABABAAAAAAABA") << '\n';
    cout << solution("AAAAAAA") << '\n';
    cout << solution("JEROEN") << '\n';
    cout << solution("JAN") << '\n';

    return 0;
}
