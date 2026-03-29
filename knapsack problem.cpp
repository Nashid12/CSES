#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double weight;
    double value;
};

int knapsack(int idx, int capacity, vector<Item>& item) {

    if(idx >= item.size())
        return 0;

    int skip = knapsack(idx + 1, capacity, item);

    int take = 0;

    if(capacity >= item[idx].weight)
        take = item[idx].value + knapsack(idx + 1, capacity - item[idx].weight, item);

    return max(skip, take);
}

int main() {

    vector<Item> item = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int capacity = 50;

    cout << knapsack(0, capacity, item);

}