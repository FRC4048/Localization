//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: mandelbrot_populate.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

// Include Files
#include "mandelbrot_populate.h"
#include "Subscriber.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void mandelbrot_populate()
{
  coder::ros::Subscriber sub;
  sub.init();
  while (1) {
    float scan_AngleMin;
    scan_AngleMin = sub.receive();
    //          fprintf("OUTPUT=%",scan);
    printf("ANGLE MIN = %f\n", scan_AngleMin);
    fflush(stdout);
  }
}

//
// File trailer for mandelbrot_populate.cpp
//
// [EOF]
//
