#include <iostream>
#include <vector>
#include <stack>

// 나중에 제출해보기 ! 

using namespace std;

int Answer;
int N;

void func(int start, vector<int>& friends, vector<int>& people) {
    int next = people[start];
    stack<int> s;
    s.push(start);

    while(next <= N) {
        if (friends[next] == 0) {
            friends[next] = start;
            s.push(next);
            next = people[next];
        } else {
            start = friends[next];
            while(!s.empty()) {
                int front = s.top();
                friends[front] = start;
                s.pop();
            }
            Answer--;
            break;
        }
    }
}

void solution() {
    vector<int> people;
    vector<int> friends(N+1, 0); 

    people.push_back(0);

    for (int i = 1; i <= N; i++) {
        int number;
        cin >> number;
        people.push_back(number+i);
    }

    for (int i = 1; i <= N; i++) {
        if (friends[i] == 0) {
            friends[i] = i;
            func(i, friends, people);
            Answer++;
        } 
    }
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;

		Answer = 0;
		solution();

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int Answer;

// bool isValid(int f, vector<int>& friends) {
//     if (friends[f] == 0) {
        
//     }
// }

// void solution(int N) {
//     vector<int> people;
//     vector<int> friends(N, 0); 

//     int count = 0;

//     people.push_back(0);

//     for (int i = 1; i <= N; i++) {
//         int number;
//         cin >> number;
//         people.push_back(number+i);
//     }

//     for (int i = 1; i <= N; i++) {
//         if (friends[i] == 0) {
//             friends[i] = i;
//             if (isValid(people[i], friends)) {

//             }
//         } 
//     }
// }

// int main(int argc, char** argv)
// {
// 	int T, test_case;

// 	cin >> T;
// 	for(test_case = 0; test_case  < T; test_case++)
// 	{
//         int N;
//         cin >> N;

// 		Answer = 0;
// 		solution(N);

// 		/////////////////////////////////////////////////////////////////////////////////////////////
// 		/*
// 		   Implement your algorithm here.
// 		   The answer to the case will be stored in variable Answer.
// 		 */
// 		/////////////////////////////////////////////////////////////////////////////////////////////
		
// 		// Print the answer to standard output(screen).
// 		cout << "Case #" << test_case+1 << "\n";
// 		cout << Answer << "\n";
// 	}

// 	return 0;//Your program should return 0 on normal termination.
// }

// -------------------------<Time Limit>-------------------------

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int Answer;

// void bfs(int start, vector<int> people, vector<bool> &isvisit, int N) {
//     queue<int> q;
//     isvisit[start] = true;
//     q.push(start);

//     while (!q.empty()) {
//         int front = q.front();
//         int next = people[front];
//         q.pop();
        
//         if (!isvisit[next] && next <= N) {
//             q.push(next);
//             isvisit[next] = true;
//         } else if (isvisit[next]) {
//             Answer--;
//             return;
//         }
//     }
// }

// void solution(int N) {
//     vector<int> people;
//     vector<bool> isvisit(N, false);
//     int count = 0;

//     people.push_back(0);
//     // isvisit.push_back(false);

//     for (int i = 1; i <= N; i++) {
//         int number;
//         cin >> number;
//         people.push_back(number+i);
//     }

//     for (int i = 1; i <= N; i++) {
//         if (!isvisit[i]) {
//             bfs(i, people, isvisit, N);
//             Answer++;
//         } 
//     }
// }

// int main(int argc, char** argv)
// {
// 	int T, test_case;
// 	ios_base :: sync_with_stdio(false); 
// 	cin.tie(NULL); 
// 	cout.tie(NULL);

// 	cin >> T;
// 	for(test_case = 0; test_case  < T; test_case++)
// 	{
//         int N;
//         cin >> N;

// 		Answer = 0;
		
// 		solution(N);
		
// 		cout << "Case #" << test_case+1 << endl;
// 		cout << Answer << endl;
// 	}

// 	return 0;//Your program should return 0 on normal termination.
// }