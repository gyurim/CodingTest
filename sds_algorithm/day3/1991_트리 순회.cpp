#include <iostream>
using namespace std;

struct stNode {
    char left;
    char right;
};

stNode Data[27];

// 전위 순회: node -> left -> right
void preOrder(char node){
    if (node == '.') return;

    printf("%c", node);
    preOrder(Data[node-'A'].left);
    preOrder(Data[node-'A'].right);
}

// 중위 순회: left -> node -> right 
void inOrder(char node){
    if (node == '.') return;

    inOrder(Data[node-'A'].left);
    printf("%c", node);
    inOrder(Data[node-'A'].right);
}

// 후위 순회: left -> right -> node 
void postOrder(char node){
    if (node == '.') return;

    postOrder(Data[node-'A'].left);
    postOrder(Data[node-'A'].right);
    printf("%c", node);
}
 
int main() {
    int n;
    // scanf("%d", &n);
    cin >> n;

    for (int i = 0; i < n; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        // scanf("%c %c %c", &node, &left, &right);
        Data[node-'A'].left = left;
        Data[node-'A'].right = right;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');

    return 0;
}