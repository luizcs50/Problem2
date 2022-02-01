#include <stdio.h>
#include <cs50.h>

bool valid_triangle (float a, float b, float c);

int main(void)
{
    float side_a = get_float("LADO A: ");
    float side_b = get_float("LADO B: ");
    float side_c = get_float("LADO C: ");

    if (valid_triangle(side_a, side_b, side_c))
    {
        printf("VALID!!!\n");
    }
    else
    {
        printf("INVALID!\n");
    }
}

bool valid_triangle (float a, float b, float c)
{
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }
    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }

    return true;
}