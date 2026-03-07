#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n) {
    int output[n];

    // Find maximum element
    int maxVal = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    // Count array
    int count[maxVal + 1];
    for(int i = 0; i <= maxVal; i++)
        count[i] = 0;

    // Store frequency
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Update count array (prefix sum)
    for(int i = 1; i <= maxVal; i++)
        count[i] += count[i-1];

    cout << "Counting array: ";
    for(int i = 0; i <= maxVal; i++)
        cout << count[i] << " ";
    cout << endl;

    // Build output array
    for(int i = n-1; i >= 0; i--){
        int currentElement = arr[i];
        int updatedFreq = count[currentElement];
        int indexOutput = updatedFreq - 1;

        output[indexOutput] = currentElement;
        count[currentElement]--;
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}