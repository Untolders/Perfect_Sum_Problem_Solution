**************************************************************************************  Question  *************************************************************************************************
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10} are 
possible subsets.
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
{2, 3, 5} are possible subsets.
Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0<=arr[I]<=106



**************************************************************************************   Solution  *************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
          const int mod = 1e9 + 7;
       
  int dp[n+1][sum+1];
  
  for(int i=0;i<=sum;i++)
  {
    dp[0][i]=0;
  }
  
  dp[0][0]=1;
  
  for(int i=1;i<=n;i++){
     for(int j=0;j<=sum;j++){
          if(j>=arr[i-1])
               dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-arr[i-1]]%mod)%mod;
           else
              dp[i][j]=dp[i-1][j]%mod;
       }
  }
  
    return dp[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
