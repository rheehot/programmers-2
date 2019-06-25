#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days;
    int size = (int)progresses.size();
    for (int i = 0; i < size; i++) {
        int temp = 100 - progresses[i];
        int day = temp / speeds[i];
        if (temp % speeds[i] > 0) day++;
        days.push_back(day);
    }
    
    vector<int> answer;
    int i = 0;
    while (i < size) {
        int j = i + 1;
        int count = 1;
        while (j < size) {
            if (days[i] >= days[j]) {
                count++;
            } else break;
            j++;
        }
        answer.push_back(count);
        i = j;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr = solution({93, 30, 55}, {1, 30, 5});
    for (int v : arr) cout << v << '\n';
    return 0;
}
