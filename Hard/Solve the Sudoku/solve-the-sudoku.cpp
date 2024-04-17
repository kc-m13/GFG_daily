//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

class Solution {
    public:
    bool isValid(int row, int col, int val, int a[N][N]) {
        for(int i=0;i<9;i++) {
            if(a[row][i]==val) return 0;
            if(a[i][col]==val) return 0;
            if(a[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val) return 0;
        }
        return 1;
    }
    bool SolveSudoku(int a[N][N])  { 
       for(int i=0;i<N;i++) {
           for(int j=0;j<N;j++) {
               if(a[i][j]==0) {
                   for(int c=1;c<=9;c++) {
                       if(isValid(i, j, c, a)) {
                           a[i][j]=c;
                           if(SolveSudoku(a) == true) return 1;
                           else
                           a[i][j]=0;
                       }
                   }
                   return 0;
               }
           }
       }
       return 1;
    }
    void printGrid (int a[N][N]) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout<<a[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends