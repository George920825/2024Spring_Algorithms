#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int monotoneIncreasingDigits(int n) {
    char s[11];
    sprintf(s, "%d", n);
    int len = strlen(s);

    int flag = len;
    for (int i = len - 1; i > 0; i--) {
        if (s[i - 1] > s[i]) {
        // TODO (A)
        s[i - 1]--;
        flag = i;
        }
    }

    for (int j = flag; j < len; j++) {
        //s[j] = // TODO (B)
        s[j] = '9';
    }
    return atoi(s);
}

int main(){
    printf("%d\n", monotoneIncreasingDigits(10));
    printf("%d\n", monotoneIncreasingDigits(1234));
    printf("%d\n", monotoneIncreasingDigits(332));
    return 0;
}