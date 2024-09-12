/* This may look like nonsense, but really is -*- mode: C -*- */
#include <stdlib.h>                                    /*@\label{include-stdlib}*/
#include <stdio.h>
#include <stdbool.h>                                     /*@\label{include-stdio}*/

/* The main thing that this program does. */           /*@\label{C-comment}*/
int main(int argc, [[maybe_unused]] char* argv[argc+1]) { /*@\label{main-start}*/
  // Declarations
  double A[5] = {                                      /*@\label{array-declaration}*/
    [0] = 3.0,                                         /*@\label{designated-init}*/
    [1] = 2.9,
    [4] = 3.E+25,                                      /*@\label{scientific-notation}*/
    [3] = -.00007,
    [2] = -4                                      /*@\label{comma-terminate}*/
  };

  // Count positive and negative
  size_t sign[2] = {0, 0};                                   /*@\label{CPP-comment}*/
  for (size_t i = 0; i <5 ; ++i) {  
    sign[A[i]>0] += 1;                        /*@\label{printf-end}*/
  }                                                    /*@\label{for-end}*/

  printf("True values: %zu\nFalse values: %zu\n", sign[true], sign[false]);
  return EXIT_SUCCESS;                                 /*@\label{main-return}*/
}                                                      /*@\label{main-end}*/ 