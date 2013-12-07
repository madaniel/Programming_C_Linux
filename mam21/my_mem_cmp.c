/*
 * my_mem_cmp.c
 *
 *  Created on: Nov 22, 2011
 *      Author: student
 */

#include <stdio.h>

int my_memcmp(const void *p1, const void *p2, int count);

int main() {    

    char arr11[] = {0, '1', '5', '6', '9'};
    char arr12[] = {0, '1', '2', '6', '9'};

    char arr21[] = {0, 1, '\0', 4, 5};
    char arr22[] = {0, 1, 'a', 'b', 'c'};

    char arr31[] = {0, 1, 2, 3, 4};
    char arr32[] = {0, 1, 2, 3, 4};

    printf("arr11[]={\\0,1,5,6,9} \narr12[]={\\0,1,2,6,9} \nmy_memcmp()=%d\n\n", my_memcmp(arr11, arr12, 5));
    printf("arr21[]={\\0,1,\\0,4,5} \narr22[]={\\0,1,a,b,c} \nmy_memcmp()=%d\n\n", my_memcmp(arr21, arr22, 5));
    printf("arr31[]={\\0,1,2,3,4} \narr32[]={\\0,1,2,3,4} \nmy_memcmp()=%d\n\n", my_memcmp(arr31, arr32, 5));


    return 0;
}

int my_memcmp(const void *p1, const void *p2, int count) {
    int i;
    char *s1 = (char*) p1, *s2 = (char*) p2;

    for (i = 0; i < count; i++, s1++, s2++) {
        if (*s1 < *s2)
            return -1;
        if (*s1 > *s2)
            return 1;
    }

    return 0;
}

