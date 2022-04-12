#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y, cost;
    Node(int x, int y, int cost) : x(x), y(y), cost(cost) {}
    bool operator < (const Node& other) const {
        return cost < other.cost;
    }
};

int main() {
    vector<Node> v;
    v.push_back(Node(1, 1, 5));
    v.push_back(Node(2, 2, 3));
    v.push_back(Node(3, 3, 4));
    v.push_back(Node(4, 4, 1));
    v.push_back(Node(5, 5, 2));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) 
        cout << v[i].x << " " << v[i].y << " " << v[i].cost << endl;

    return 0;
}