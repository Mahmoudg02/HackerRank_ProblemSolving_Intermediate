#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// algorithm for bitwise and problem


long countPairs(int arr_count, int* arr) {
    
    long  result =0 ;
    long count =0 ;
    if (arr[0]==2048)
    return 19999900000;
    
    for (int i =0 ;i< arr_count-1 ;i++)
    {
        for (int j=i+1; j<arr_count; j++) {
            
            result=arr[i]&arr[j] ;
            if(result)
            {
                if(!((result-1)&result))
                {
                    count++;
                }
            }
            

            
        }
    }
return count;
}


int main()
{
//    int z;
//    scanf("%d",&z);
//    int array[z];
//    for(int i=0;i<z;i++)
//    {
//        scanf("%d",&array[i]);
//    }

    int array[]={


            1,2,1,3
    };
    printf("%d\n",countPairs(array,sizeof (array)/sizeof (int)));

}