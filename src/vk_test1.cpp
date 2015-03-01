#include <stdio.h> // standard input / output functions
#include "vk_test1.h"

int bsearch(int const *v, int const x, int len, ...) {
    int left = 0, right = len, mid;
    int ret = -1;
    
    while (left <= right) 
    {
        mid = left + (right - left) / 2;
        if (x < v[mid]) {
            ret = mid;
            right = mid - 1;
        } else if (x >= v[mid])
            left = mid + 1;
    }

    return ret;
}

int main() {
    int tt1[] = {1, 2, 3, 4, 5, 6, 7, 22, 33, 55};
    int rez = -1;
    printf("%d ", bsearch(&tt1[0], -10, sizeof (tt1) / sizeof (tt1[0]))); //0  
    printf("%d ", bsearch(&tt1[0], 1, sizeof (tt1) / sizeof (tt1[0]))); //1
    printf("%d ", bsearch(&tt1[0], 5, sizeof (tt1) / sizeof (tt1[0]))); //5
    printf("%d ", bsearch(&tt1[0], 23, sizeof (tt1) / sizeof (tt1[0]))); //8
    printf("%d ", bsearch(&tt1[0], 55, sizeof (tt1) / sizeof (tt1[0]))); //-1
    printf("%d ", bsearch(&tt1[0], 100, sizeof (tt1) / sizeof (tt1[0]))); //-1
    return 0;
}
