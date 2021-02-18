/*Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number.

Examples :

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33

    Create three variables, l=0, sum = 0
    Traverse the array from start to end.
    Update the variable sum by adding current element, sum = sum + array[i]
    If the sum is greater than the given sum, update the variable sum as sum = sum - array[l], and update l as, l++.
    If the sum is equal to given sum, print the subarray and break the loop.

*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s){
    
    // Your code here
    int sum=arr[0],i,start=0;
    vector<int> result;
    for(int i=1;i<=n;i++)
    {
        while(sum>s && start<i-1)
        {
            sum=sum-arr[start];
            start++;
        }
        if(sum==s)
        {
            result.push_back(start+1);
            result.push_back(i);
            return result;
        }
        if(i<n)
        {
            sum=sum+arr[i];
        }
        
        
    }
    result.push_back(-1);
        return result;
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
