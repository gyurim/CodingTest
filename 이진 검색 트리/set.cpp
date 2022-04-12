#include <iostream>
#include <set>

using namespace std;

void set_example(){
    set<int> s;
    s.insert(-10);
    s.insert(100);
    s.insert(15);
    // {-10, 100, 15}
    s.insert(100); // {-10, 100, 15} 중복 허용 X

    cout << s.erase(100) << '\n'; // {-10, 15}, 1
    cout << s.erase(20) << '\n'; // {-10, 15}, 0

    if (s.find(15) != s.end()) 
        cout << "15 in s\n";
    else cout << "15 not in s\n";

    cout << s.size() << '\n'; // 2
    cout << s.count(50) << '\n'; // 0

    for (auto e : s)   
        cout << e << ' ';
    cout << '\n';

    s.insert(-40); // {-40, -10, 15};
    set<int>::iterator it1 = s.begin(); // it1 : -40
    it1++; // it1 : -10
    auto it2 = prev(it1); // it2 : -40
    it2 = next(it1); // it2 : 15
    advance(it2, -2); // it2 : -40
    auto it3 = s.lower_bound(-20); // it3 : -10 
    // lower_bound : key 이상인 수가 처음으로 등장하는 위치
    // upper_bound : key 초과인 수가 처음으로 등장하는 위치 
    auto it4 = s.find(15); // it4 : 15
    cout << *it1 << '\n'; // -10
    cout << *it2 << '\n'; // -40
    cout << *it3 << '\n'; // -10
    cout << *it4 << '\n'; // 15
}