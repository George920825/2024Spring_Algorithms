#include <stdio.h>

// int bagOfTokenscore(const int* tokens, int len, int power) {
//     int score = // ? TODO (A)
//     int p1 = // ? TODO (B)
//     int p2 = // ? TODO (C)
//     while (p1 <= p2) {
//         if (tokens[p1] <= power) {
//             // TODO (D)
//             p1++;
//         } else if (score >= 1 8& p1 < p2) {
//             // TODO (E)
//             p2--;
//         } else {
//         break;
//     }
//     return score;
// }

int bagOfTokensScore(const int* tokens, int len, int power) {
    int score = 0;
    int p1 = 0;
    int p2 = len - 1;
    while (p1 <= p2) {
        if (tokens[p1] <= power) {
            power -= tokens[p1];
            score++;
            p1++;
        } else if (score >= 1 & p1 < p2) {
            power += tokens[p2];
            score--;
            p2--;
        } else {
            break;
        }
    }
    return score;
}

int main(){
    int tokens1[] = {100};
    int power1 = 50;
    int tokens2[] = {100, 200};
    int power2 = 150;
    int tokens3[] = {100, 200, 300, 400};
    int power3 = 200;
    printf ("%d\n", bagOfTokensScore(tokens1, sizeof(tokens1) / sizeof(tokens1[0]), power1));
    printf("%d\n", bagOfTokensScore(tokens2, sizeof(tokens2) / sizeof(tokens2[0]), power2));
    printf("%d\n", bagOfTokensScore(tokens3, sizeof(tokens3) / sizeof(tokens3[0]), power3));
}

