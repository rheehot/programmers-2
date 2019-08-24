// 프로그래머스 12949 - 행렬의 곱셈
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2) {
    size_t row = arr1.size();
    size_t col1 = arr1[0].size();
    size_t col2 = arr2[0].size();
    vector<vector<int> > answer(row, vector<int>(col2));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int> > arr2 = {{3, 3}, {3, 3}};
    vector<vector<int> > answer = solution(arr1, arr2);
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
    
    vector<vector<int> > arr11 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}};
    vector<vector<int> > arr22 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};
    vector<vector<int> > answer2 = solution(arr11, arr22);
    
    for (int i = 0; i < answer2.size(); i++) {
        for (int j = 0; j < answer2[0].size(); j++) {
            cout << answer2[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
