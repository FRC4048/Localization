#ifndef MANDELBROT_POPULATE__VISIBILITY_CONTROL_H_
#define MANDELBROT_POPULATE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MANDELBROT_POPULATE_EXPORT __attribute__ ((dllexport))
    #define MANDELBROT_POPULATE_IMPORT __attribute__ ((dllimport))
  #else
    #define MANDELBROT_POPULATE_EXPORT __declspec(dllexport)
    #define MANDELBROT_POPULATE_IMPORT __declspec(dllimport)
  #endif
  #ifdef MANDELBROT_POPULATE_BUILDING_LIBRARY
    #define MANDELBROT_POPULATE_PUBLIC MANDELBROT_POPULATE_EXPORT
  #else
    #define MANDELBROT_POPULATE_PUBLIC MANDELBROT_POPULATE_IMPORT
  #endif
  #define MANDELBROT_POPULATE_PUBLIC_TYPE MANDELBROT_POPULATE_PUBLIC
  #define MANDELBROT_POPULATE_LOCAL
#else
  #define MANDELBROT_POPULATE_EXPORT __attribute__ ((visibility("default")))
  #define MANDELBROT_POPULATE_IMPORT
  #if __GNUC__ >= 4
    #define MANDELBROT_POPULATE_PUBLIC __attribute__ ((visibility("default")))
    #define MANDELBROT_POPULATE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MANDELBROT_POPULATE_PUBLIC
    #define MANDELBROT_POPULATE_LOCAL
  #endif
  #define MANDELBROT_POPULATE_PUBLIC_TYPE
#endif
#endif  // MANDELBROT_POPULATE__VISIBILITY_CONTROL_H_
// Generated 06-Dec-2022 20:28:46
// Copyright 2019-2020 The MathWorks, Inc.
