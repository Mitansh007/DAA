#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
	string b;
	cout<<"Enter the string a"<<endl;
	cin>>a;
	cout<<"Enter the string b"<<endl;
	cin>>b;
	int n= a.size();
	int m= b.size();
	int K[n+1][m+1];
	  
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<=m;j++)
      {
          if(i==0||j==0)
          {
              K[i][j]=0;
          }
          else if(a[i-1]==b[j-1])
          {
              K[i][j]=K[i-1][j-1]+1;
          }
          else
          {
              K[i][j]=max(K[i - 1][j], K[i][j - 1]);
          }
      }
  }
  
  for (int i = 0; i <= n; i++)
{
   for (int j = 0; j <= m; j++)
   {
      cout << K[i][j] << " ";
   }
   cout << endl;
}
  cout<<"\nSize of LCS is "<<K[n][m];
  int l=K[n][m];
  char lcs[l+1];
  lcs[l]='\0';
  
  int i=n,j=m;
  while(i>0 && j>0)
  {
  	if(a[i-1]==b[j-1])
  	{
  	    lcs[--l]=a[i-1];
  		i--;
  		j--;
	  }
	  else if(K[i-1][j]>K[i][j-1])
	  {
	  	i--;
	  }
	  else
	  {
	  	j--;
	  }
  }
  cout<<"\nSubseq : "<<lcs<<endl;  
  return 0;
}
