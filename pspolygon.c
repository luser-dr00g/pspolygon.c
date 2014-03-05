#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void emitpoly (double x, double y, int n, double r, int up) {
    int i;
    double a;
    printf("%f %f moveto\n", x+r*cos(up?M_PI/2.0:0.0), y+r*sin(up?M_PI/2.0:0.0));
    for(i=1; i<n; i++){
        a=(double)i*(2*M_PI)/n;
        if (up) a += M_PI/2.0;
        printf("%f %f lineto\n", x+r*cos(a), y+r*sin(a));
    }
    printf("stroke\n");
}

void emitpolyweb (double x, double y, int n, double r, int up) {
    int i,j;
    double a,b;
    for(i=0; i<n; i++){
        a=(double)i*(2*M_PI)/n;
        if (up) a += M_PI/2.0;
        printf("%f %f moveto\n", x+r*cos(a), y+r*sin(a));
        for(j=0; j<n; j++){
            b=(double)j*(2*M_PI)/n;
            if (up) b += M_PI/2.0;
            printf("%f %f lineto\n", x+r*cos(b), y+r*sin(b));
            printf("closepath\n");
        }
    }
    printf("stroke\n");
}

int main(int argc, char**argv) {
    int up = 0, n = 3;
    double x = 0.0, y = 0.0, r = 1.0;
    if (argc>1) x = strtod(argv[1],NULL);    // set x from 1st arg, if present
    if (argc>2) y = strtod(argv[2],NULL);    // set y from 2nd arg, if present
    if (argc>3) n = strtol(argv[3],NULL,10); // set n from 3rd arg, if present
    if (argc>4) r = strtod(argv[4],NULL);    // set r from 4th arg, if present
    if (argc>5) up = strcmp(argv[5],"up") == 0;  // rotate 90-degrees if 5th arg is "up"

    //emitpoly(x,y,n,r,up);
    emitpolyweb(x,y,n,r,up);
    printf("showpage\n");
    return 0;
}

