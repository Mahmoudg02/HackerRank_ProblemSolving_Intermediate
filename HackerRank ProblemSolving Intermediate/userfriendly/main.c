#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define  P          (131)
#define  MOD        (1000000007)


int setPassword(char* password)
{
    long res = 0;

    for (int i = 0; password[i]; i++)
    {
        res *= P;
        res %= MOD;
        res += password[i];
        res %= MOD;
    }

    return res;
}
int authorize(long currhash,long newhash){

    if (currhash==newhash)
    {
        return 1 ;
    }
    currhash*=P ;
    currhash%=MOD ;

    for (int i = 'a'; i <='z' ; ++i) {
        if ((currhash+i)==newhash)
            return 1 ;
    }
    for (int i = 'A'; i <='Z' ; ++i) {
        if ((currhash+i)==newhash)
            return 1 ;
    }
    for (int i = '0'; i <='9' ; ++i) {
        if ((currhash+i)==newhash)
            return 1 ;
    }
    return 0;
}
int *authEvents(int events_rows, int events_columns, char ***events, int *result_count)
{
    int *res = malloc(events_rows *sizeof (int)) ;
    long currhash;
    int resindex =0 ;
    for (int i = 0; i < events_rows; i++) {

        switch (events[i][0][0]) {

            case 's':
                currhash = setPassword(events[i][1]);
                break;
            case 'a':
                res[resindex]= authorize(currhash, atoi(events[i][1]));
                resindex ++ ;
                break;
        }
    }
    *result_count =resindex ;
    return res;
}