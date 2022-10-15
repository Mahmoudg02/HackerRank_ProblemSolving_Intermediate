#include "stdio.h"



long long maxSubarrayValue(int arr_count, int * arr ){

    long long  odd =0 ;
    long long even = 0 ;
    long long sum = 0;
    long long result ;
    int max=0 ;
    long long mod =10e9+7;
    for (int i =0 ;i<arr_count ;i++ )
    {
        for (int j = i ; j < arr_count ; j++)
        {
            for(int k = i ; k<=j ;k++)
            {
                if (i%2) // odd
                {
                    if (k%2) //
                    {
                        even+=arr[k] ;
                    }else{ //
                        odd+=arr[k] ;
                    }

                }else{ // even

                    if (k%2) //
                    {
                        odd+=arr[k] ;
                    }else{ //
                        even+=arr[k] ;
                    }
                }
            }
            sum = even -odd ;
            result =sum*sum%mod ;
            even =0 ;
            odd = 0 ;

            if (result>max)
            {
                max =result ;
            }
        }
    }

    return max;

}



int main(void){

    int n ;
    scanf("%d",&n);
    int arr[n] ;
    for(int i=0 ;i< n ; i ++){
        scanf("%d",&arr[i]) ;
    }
//int n =5 ;
//int arr[6]={
//        3,
//        -1,
//        -1,
//        -1,
//        5,
//        1
//};
    printf("%d", maxSubarrayValue(n,arr));


    return  0;
}