#include <stdio.h>
#include <stdlib.h>

void manipule_arr(int *);

int main(void)
{
    int array[] = {1, 2, 3 , 4 , 5};
    int *ptr = &array[4];
    printf("array[4] = %d\n", array[4]);
    printf("array[4] addres --> %p\n", &array[4]);
    printf("ptr addres --> %p\n", &ptr);
    manipule_arr(ptr);
    printf("array[4] = %d\n", array[4]);

}

void manipule_arr (int *array )
{
    *array = 69;
}