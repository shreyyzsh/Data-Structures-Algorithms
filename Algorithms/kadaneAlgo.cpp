
// To Find Maximum Sum of Sub Array

/*
    - Brute Force approach results in a time complexity of O(n^2)
    - By using kadane's algorithm we get a time complexity of O(n) 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-1,2,3,-4,5};

    int maxSum = arr[0];
    int maxEnding = arr[0];

    for (int st = 1; st < arr.size(); st++) {
        //deciding whether to start from curr index or prev subarr:
        maxEnding = max(maxEnding+arr[st], arr[st]);

        maxSum = max(maxEnding, maxSum);
    }

    cout << maxSum << endl;
    return 0;

}