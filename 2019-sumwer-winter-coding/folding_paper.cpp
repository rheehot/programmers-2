#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    answer.push_back(0);
    
    for (int i = 1; i < n; i++) {
        answer.push_back(0);
        for (int j = answer.size() - 2; j >= 0; j--) {
            answer.push_back(1 - answer[j]);
        }
    }
    
    return answer;
}