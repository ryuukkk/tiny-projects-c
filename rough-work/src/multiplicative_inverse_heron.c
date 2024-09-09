#include <stdlib.h>
#include <stdio.h>

static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1]) {
    for (int i=1; i<argc; ++i) {
        double const a = strtod(argv[i], 0);
        double x = 1.0;

        for (;;) {
            double prod = a*x;
            printf("power a: %e\t power x: %e\tpower prod: %e\n\n", a, x, prod);
            if (prod<eps1m01) {
                x *= 2;
            } else if (prod>eps1p01) {
                x *= 0.5;
            } else {
                break;
            }
        }

        for (;;) {
            double prod = a*x;
            printf("heron a: %e\t heron x: %e\theron prod: %e\n\n", a, x, prod);
            if (prod > eps1p24 || prod < eps1m24) {
                x *= (2 - prod);
            } else {
                break;
            }
        }
        
        printf("final a: %e\tfinal x: %e\n\n", a, x);
    }
    return 0;
}