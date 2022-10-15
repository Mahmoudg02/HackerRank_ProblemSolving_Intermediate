#include <stdio.h>
#include <math.h>
void swap(int*ptr1, int*ptr2);




int solve(int v[], int n) {

    long long ans = 0, M = 10e9 + 7;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && v[j - 1] > v[j]) {
            swap(&v[j], &v[j - 1]);
            j--;
        }
        for(int j = 0; j <= i; j++) {
            ans = ((ans + (v[j] *(1)) * (j + 1))) % M;
        }
        ans %= M;
    }
    return ans;
}



void swap(int *ptr1, int *ptr2){
	int temp;
		temp  = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++) {
        scanf("%d",& v[i]);
    }

//int v []={9,5,8} ;
    printf("%d", solve(v, n));
}