#include <stdio.h>

int isramanujan(int cube_sum, int a, int b) {
    int c = 0;
    int d = 0;
    int other_cube_sum = 0;

    while (1) {
        ++c;
        other_cube_sum = c * c * c + d * d * d;
        if (other_cube_sum == cube_sum && c != a && c != b && a * b * c * d != 0)
        printf("The number %d is a Ramanujan Number, because it is [(%d)cube + (%d)cube] and [(%d)cube + (%d)cube]\n", cube_sum, a, b, c, d);

        if (other_cube_sum > cube_sum) {
        if (c == d + 1)
        return 0;
        c = ++d;
        } 
    }
}

int main(void)
{
    int a = 0;
    int b = 0;
    int cube_sum = 0;
    

    while (1) {
        ++a;
        cube_sum = a * a * a + b * b * b;
        // Check only numbers that can be expressed as sum of cubes.
        isramanujan(cube_sum, a, b);
        if (cube_sum > 100000) {
            if (a == b + 1)
            return 0;
            a = ++b;        
        }
        //printf("The numbers %d and %d are\n" , a, b);
    }
}