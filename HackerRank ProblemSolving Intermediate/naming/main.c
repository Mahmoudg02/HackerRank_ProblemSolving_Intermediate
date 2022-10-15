#include <stdio.h>
#include <string.h>
#include <math.h>


//int renameFile(char* newName,char* oldName)
//{
//    long long  mod  =10e9+7 ;
//    int n = strlen(newName);
//    int m = strlen(oldName);
//    int dp[10000];
//    int dpp[10000];
//    for (int z=0;z<m+1;z++)
//    {
//        dp[z]=1;
//    }
//    for (int i=0;i<n;i++)
//    {
//        for (int z=0;z<m+1;z++)
//        {
//            dpp[z]=0;
//        }
//        for (int j=i;j<m+1;j++)
//        {
//            dpp[j+1] = dpp[j ];
//            if (newName[i] == oldName[j])
//                dpp[j+1] += dp[j ];
//        }
//        for (int z=0;z<m+1;z++)
//        {
//            dp[z]=dpp[z];
//        }
//    }
//    return dpp[m]%mod;
//}

#define M 1000000007
int renameFile(char* newName,char* oldName){
    long long mod= 10e9+7 ;
    long n= strlen(newName) ;
    long o= strlen(oldName) ;
    long dp[1000000] ;
    long dpp[1000000] ;

    for (int i = 0 ;i<o+1 ;i++){
        dp[i]=1 ;
    }
    for(int i =0 ;i<n;i++){
        for(int j = 0 ;j< o+1 ;j++)
        {
            dpp[j]=0 ;
        }
        for(int j = i ;j<o+1 ;j++)
        {
            dpp[j+1]=dpp[j] ;
            if (newName[i]==oldName[j])
            {
                dpp[j+1]+=dp[j] ;
            }
        }
        for (int j = 0; j < o + 1; ++j) {
            dp[j]=dpp[j];
        }

    }
    return dp[o]%M ;
}

int main() {
    char* newName = "ccc";

    char* oldName = "cccc";

    int result = renameFile(newName, oldName);
    printf("%d",result);
    return 0;
}