#include <iostream>
#include <vector>
#include <cstdio> // scanf, printf
#include <algorithm> // binary_search, sort

using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);

    vector<int> cards;

    for (int i = 0; i < n; i++){
        int card;
        scanf("%d", &card);
        cards.push_back(card);
    }

    sort(cards.begin(), cards.end());

    scanf("%d", &m);

    for (int i = 0; i < m; i++){
        int key;
        scanf("%d", &key);

        if (binary_search(cards.begin(), cards.end(), key)){
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    return 0;
}