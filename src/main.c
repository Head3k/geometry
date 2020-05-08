#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int function(float x1, float y1, float r1, float x2, float y2, float r2)
{
    float d, sr;
    int f = 0;
    if ((x1 == x2) && (y1 == y2)) {
        f = 1;
    } else {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        sr = r1 + r2;
        if ((d <= sr) && (d >= fabs(r1 - r2))) {
            f = 1;
        } else {
            f = 0;
        }
    }
    return f;
}

float circle(float x, float y, float r, float* p, float* s)
{
    float r2;
    *p = 2 * 3.14 * r;
    r2 = pow(r, 2);
    *s = 3.14 * r2;
    return 0;
}
*/
int main()
{
    int count, i, j;
    printf("Enter count figure\n");
    scanf("%d", &count);
    float x[count], y[count], r[count], p, s;
    int inter[count][count];
    for (i = 0; i < count; i++) {
        printf("Enter center(x y), radius(r):\n");
        printf("X = ");
        scanf("%f", &x[i]);
        printf("Y = ");
        scanf("%f", &y[i]);
        printf("R = ");
        scanf("%f", &r[i]);
        printf("\n");
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            inter[i][j] = 0;
            if (i != j) {
                inter[i][j] = function(x[i], y[i], r[i], x[j], y[j], r[j]);
            }
        }
    }
    for (i = 0; i < count; i++) {
        circle(x[i], y[i], r[i], &p, &s);
        printf("%d. circle(%.2f %.2f, %.2f)\n", i + 1, x[i], y[i], r[i]);
        printf("    perimeter = %.3f \n", p);
        printf("    area = %.3f \n", s);
        printf("    intersects:\n");
        for (j = 0; j < count; j++) {
            if (inter[i][j] == 1) {
                printf("     %d. circle\n", j + 1);
            }
        }
    }
}
