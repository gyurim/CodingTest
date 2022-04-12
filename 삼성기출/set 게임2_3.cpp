#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T, N;
vector<string> cards; // input(string)
vector<int> v; // var cards -> bit mask(int)
vector<int> which_set; // to make cases
int result = 0;

int my_num[4][4] =  {{(1<<12) | (1<<11) | (1<<10), 1<<12, 1<<11, 1<<10}, 
                    {(1<<9) | (1<<8) | (1<<7),     1<<9, 1<<8, 1<<7}, 
                    {(1<<6) | (1<<5) | (1<<4),     1<<6, 1<<5, 1<<4}, 
                    {(1<<3) | (1<<2) | (1<<1),     1<<3, 1<<2, 1<<1}};

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++){
        // init
        cards.clear();
        v.clear();
        which_set.clear();

        // input
        cin >> N;
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            cards.push_back(s);
        }
        
        // bit masking
        for(int i = 0; i < N; i++) {
            int num = 0;
            string target = cards[i];
            if(target[0] == '1') num |= (1 << 12);
            else if(target[0] == '2') num |= (1 << 11);
            else if(target[0] == '3') num |= (1 << 10);

            if(target[1] == 'R') num |= (1 << 9);
            else if(target[1] == 'G') num |= (1 << 8);
            else if(target[1] == 'P') num |= (1 << 7);

            if(target[2] == 'E') num |= (1 << 6);
            else if(target[2] == 'D') num |= (1 << 5);
            else if(target[2] == 'T') num |= (1 << 4);

            if(target[3] == 'F') num |= (1 << 3);
            else if(target[3] == 'S') num |= (1 << 2);
            else if(target[3] == 'W') num |= (1 << 1);

            v.push_back(num);
        }

        // make cases(for next_permutation)
        int s_cnt = 0;
        int s_i = 0;
        for (int i = 1; i <= N; i++) {
            s_i++;
            which_set.push_back(s_cnt);

            if(s_i % 3 == 0){
                s_cnt++;
                s_i = 0;
            }
        }

        // next_permutation
        int and_res[30] = {0,};
        result = 0;
        int cnt = 0;
        int M = N / 3; // "and_res" size
        bool flg = true;
        bool success = false;
        do {
            cnt = 0;
            for(int i = 0; i < N; i++) and_res[i] = 0; // init
            for(int i = 0; i < N; i++) and_res[which_set[i]] |= v[i]; // bit on & AND op
            for(int i = 0; i < M; i++){
                flg = true;
                int target = and_res[i];
                
                for(int a = 0; a < 4; a++){
                    success = false;
                    for(int b = 0; b < 4; b++)
                        if ((target & my_num[a][0]) == my_num[a][b]) success = true;
                    if(!success) flg = false;
                    if(!flg) break;
                }

                if (flg) cnt++;
            }
            result = max(result, cnt);
            if (result == M-1) break;

        } while(next_permutation(which_set.begin(), which_set.end()));
        
        // print result
        cout << '#' << t << ' ' << result << '\n';
    }
    return 0;
}