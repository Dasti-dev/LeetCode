//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
        int solve(int arr1[], int arr2[], int n, int m, int k)
        {
            int latest;
            int count = 1;
            int i=0;
            int j=0;
            while(i<=n && j<=m)
            {
                if(i<n && j<m && arr1[i]<arr2[j])
                {
                    latest = arr1[i];
                    i++;
                }
                else if(i<n && j<m && arr1[i]>arr2[j])
                {
                    latest = arr2[j];
                    j++;
                }
                else if(i<n && j<m && arr1[i]==arr2[j])
                {
                    latest = arr1[i];
                    i++;
                }
                else if(i<n && j>=m)
                {
                    latest = arr1[i];
                    i++;
                }
                else if(j<m && i>=n)
                {
                    latest = arr2[j];
                    j++;
                }
                if(count==k)
                {
                    return latest;
                }
                count++;
            }
        }
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans = INT_MIN;
        ans = solve(arr1,arr2,n,m,k);
        if(ans != INT_MIN)
            return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
