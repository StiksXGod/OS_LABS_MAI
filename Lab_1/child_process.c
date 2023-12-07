#include <stdio.h>
#include <stdlib.h>


int main(){
    float res, x;
    char c;
    int i = 0;
      while (scanf("%f%c", &x, &c) > 0) {
        if(i == 0) {
            res = x;
            i++;
        } else {
            if(x == 0) {
                perror("Delet on zero");
                exit(EXIT_FAILURE);
            } else {
                res /= x;
                if (c == '\n') {
                    printf("%f", res);
                    i = 0;
                }
            }
        }
    }
    return 0;
}
