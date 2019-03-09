#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 굉장히 어려웠다.. 스터디를 통해 그나마 해결할 수 있었음
// 1. 핵심은 로그의 시간대는 오름차순으로 되어있다는 것
// 2. 시 * 3600 + 분 * 60 + 초 => 초로 만들어 놓고 해결하기
// 3. 현재 응답 완료시간과 다음 시작 시간을 잘 구분하여 식을 만들기

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<double, double> > process_times;
    for (int i = 0; i < lines.size(); i++) {
        // time_info -> 시간 정보
        string time_info = lines[i].substr(11, 12);
        // cp => completion time (응답 완료 시간)
        double cp_hour   = stod(time_info.substr(0, 2));    // 시
        double cp_minute = stod(time_info.substr(3, 2));    // 분
        double cp_sec    = stod(time_info.substr(6, 6));    // 초
        double cp_time   = stod(to_string(cp_hour*3600 + cp_minute*60 + cp_sec));
        
        // pcss => process time (처리 시간), st = > start time (시작 시간)
        size_t len = lines[i].find("s") - 24;
        double pcss_time = stod(lines[i].substr(24, len));
        double st_time   = cp_time - pcss_time + 0.001f;
        process_times.push_back(make_pair(st_time, cp_time));
    }
    
    for (int i = 0; i < process_times.size(); i++) {
        int count = 0;
        double current_cp_time = process_times[i].second;   // 현재 응답 완료 시간
        for (int j = i; j < process_times.size(); j++) {
            double next_st_time = process_times[j].first;   // 다음 시작 시간
            if (next_st_time - current_cp_time < 1.f) {
                ++count;
            }
        }
        answer = max(answer, count);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(4);
    
    vector<string> lines;
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 01:00:04.001 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 01:00:04.002 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 00:00:00.000 3s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 23:59:59.999 0.001s");
    cout << solution(lines) << '\n';
    return 0;
}

