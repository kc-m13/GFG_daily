//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


// } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Loop through the array with a step of 2
        for(int i = 0; i < n; i += 2){
            // Check if the current index is not the last index
            if (i != n - 1) {
                // Swap the current element with the next element
                swap(arr[i], arr[i + 1]);
            }
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        sort(a.begin(),a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
// } Driver Code Ends