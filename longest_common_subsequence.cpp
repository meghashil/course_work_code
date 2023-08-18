#include<bits/stdc++.h>
#include<string>

using namespace std;

void longestCommonSubsequence(char* s1,char* s2,int m, int n)
{
    int lcs[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0)
            {
                lcs[i][j]=0;
            }
            else if(s1[i-1] == s2[j-1])     // if row's and column's character are equal.
            {
                 lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
     
    int idx = lcs[m][n];
 
    // Create a character array to store the lcs string
    char LCS[idx + 1];
    LCS[idx] = '\0'; // Set the terminating character
 
    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (s1[i - 1] == s2[j - 1]) {
            LCS[index - 1]= s1[i - 1]; // Put current character in result
            i--;
            j--;
            idx--; // reduce values of i, j and index
        }
 
        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (lcs[i - 1][j] > lcs[i][j - 1])
            i--;
        else
            j--;
    }
 
    // Print the lcs
    cout<<"Size of Longest Common Subsequence = "<<lcs[m][n]<<endl;

    cout << "LCS of " << s1 << " and " << s2 << " is " << LCS;
    // return lcs[m][n];
}
main()
{
   char str1[30],str2[30];
   cout<<"Enter string 1 :- ";
   cin>>str1;
   cout<<endl;
   cout<<"Enter string 2 :- ";
   cin>>str2;
   int m = strlen(str1);
   int n = strlen(str2);
  
  longestCommonSubsequence(str1,str2,m,n);

   return 0;
}

