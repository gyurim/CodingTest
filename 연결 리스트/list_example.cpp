#include <iostream>
#include <list>

using namespace std;

/*
push_front
push_back
pop_front
pop_back
*/

int main() {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin();
    L.push_front(10); // 10 1 2 
    cout << *t << '\n'; // 1 출력
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입 // 10 6 1 2 5
    t++; // t는 2를 가리킴
    t = L.erase(t); // 2를 지우고 그 다음 원소인 5의 위치 반환 // 10 6 1 5
    cout << *t << '\n'; // 5

    // C++ 11 이상 
    for (auto i : L) cout << i << ' ';
    cout << '\n';

    // C++ 11 미만 
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) 
        cout << *it << ' ';

    return 0;
}