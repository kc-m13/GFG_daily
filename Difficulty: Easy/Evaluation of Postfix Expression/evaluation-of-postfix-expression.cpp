//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    private:
    
    bool isDigit(char c){
        if(c == '+' ||c == '-'||c == '/'||c == '*')
        return false;
        else return true;
    }
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        int n = S.length();
        
        for(int i = 0; i<n; i++){
            char ch = S[i];
            
            if(isDigit(ch)){
                st.push(ch - '0');
            }
            
            else{
                int no2 = st.top();
                st.pop();
                int no1 = st.top();
                st.pop();
                
                if(ch == '+'){
                    int result = no1+no2;
                    st.push(result);
                }
                else if(ch == '-'){
                    int result = no1-no2;
                    st.push(result);
                }
                else if(ch == '*'){
                    int result = no1*no2;
                    st.push(result);
                }
                else{
                    int result = no1/no2;
                    st.push(result);
                }
            }
            
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends