#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int arr[], int s, int e){
    int p = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= p)
            count++;
    }

    int p_index = s + count;
    swap(arr[s], arr[p_index]);

    int i = s;
    int j = e;

    while(i < p_index && j > p_index){

        while(arr[i] < p)
            i++;

        while(arr[j] > p)
            j--;

        if(i < p_index && j > p_index){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return p_index;
}

void quickSort(int arr[], int s, int e){
    if(s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr.data(), 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}