//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
     int circularSubarraySum(int arr[], int num){
        vector<int>v;
        for(int i=0; i<2*num-1; i++){
            v.push_back(arr[(i%num)]);
        }
        int mx=INT_MIN, flag=1;
        for(int i=0; i<num; i++){
            if(arr[i]>0) flag=0;
            mx=max(mx, arr[i]);
        }
        if(flag) return mx;
        if(v[0]<0) v[0]=0;
        for(int i=1; i<2*num-1; i++){
            if(v[i]+v[i-1]>=0) v[i]+=v[i-1];
            else v[i]=0;
        }
        
         vector<int> result;
    deque<int> window;

    for (int i = 0; i < 2*num-1; ++i) {
        while (!window.empty() && window.front() <= i - num)
            window.pop_front();

        while (!window.empty() && v[i] <= v[window.back()])
            window.pop_back();

        window.push_back(i);

        if (i >= num - 1)
            result.push_back(v[window.front()]);
    }

        
        int maxi=INT_MIN;
        for(int i=0; i<num; i++){
          maxi=max(maxi, v[i]);
        }
        for(int i=num; i<2*num-1; i++){
            maxi=max(maxi, v[i]-result[i-num]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends