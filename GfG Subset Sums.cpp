//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void sumvec(int i , int sum , vector<int> &sumA , vector<int> &arr , int N)
    {
        if(i == N)
        {
            sumA.push_back(sum);
            return;
        }
        sumvec(i+1,sum+arr[i],sumA,arr,N);
        sumvec(i+1,sum,sumA,arr,N);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumA;
        sumvec(0,0,sumA,arr,N);
        return sumA;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
