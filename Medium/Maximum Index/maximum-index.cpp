//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        // int idx = 0;
        // int maxIdx = 0;
        // for (int i = 0; i < n-1; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (arr[j] - arr[i] >= 0) idx = j-i;
        //         maxIdx = max(maxIdx, idx);
        //     }
        // }
        // return maxIdx;
        vector<int> leftMin(n);
        vector<int> rightMax(n);
        leftMin[0] = arr[0];
        rightMax[n-1] = arr[n-1];
        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(leftMin[i-1], arr[i]);
        }
        for (int i = n-2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        int ans = -1;
        int i = 0;
        int j = 0;
        while (i < n and j < n)
        {
            if (leftMin[i] <= rightMax[j])
            {
                ans = max(ans, j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends