//Given an integer n, generate a square matrix 
//filled with elements from 1 to n2 in spiral order.

//For example,
//Given n = 3,
//You should return the following matrix:
/*
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k=1;
        int i=0;
        vector< vector<int> > a(n,vector<int>(n) );
        
        while(k<=n*n){
            int j=i;

            while(j<n-i)
                a[i][j++]=k++;
                
            j=i+1;
            while(j<n-i)
                a[j++][n-i-1]=k++;
                
            j=n-i-2;
            while(j>i)
                a[n-i-1][j--]=k++;
            
            j=n-i-1;
            while(j>i)
                a[j--][i]=k++;
            i++;
        }
        return a;
    }
};
