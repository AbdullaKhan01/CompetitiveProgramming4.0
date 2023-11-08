//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101];
    int sum(int i,int j,int freq[]){
        int sum = 0;
        for(int k=i;k<=j;k++){
            sum+=freq[k];   
        }
        return sum;
    }
    int solve(int i,int j,int freq[]){
        if(i>j){
            return 0;
        }
        if(j==i){
            return dp[i][j] = freq[j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int w = sum(i,j,freq);
        
        int ans = INT_MAX;
        for(int k=i;k<=j;k++){
            int other = solve(i,k-1,freq) + solve(k+1,j,freq);
            ans = min(ans,other);
        }
        return dp[i][j] = ans + w;
        
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1;
            }
        }
        return solve(0,n-1,freq);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends