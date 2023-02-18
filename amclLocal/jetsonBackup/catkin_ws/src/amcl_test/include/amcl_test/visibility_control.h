#ifndef AMCL_TEST__VISIBILITY_CONTROL_H_
#define AMCL_TEST__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AMCL_TEST_EXPORT __attribute__ ((dllexport))
    #define AMCL_TEST_IMPORT __attribute__ ((dllimport))
  #else
    #define AMCL_TEST_EXPORT __declspec(dllexport)
    #define AMCL_TEST_IMPORT __declspec(dllimport)
  #endif
  #ifdef AMCL_TEST_BUILDING_LIBRARY
    #define AMCL_TEST_PUBLIC AMCL_TEST_EXPORT
  #else
    #define AMCL_TEST_PUBLIC AMCL_TEST_IMPORT
  #endif
  #define AMCL_TEST_PUBLIC_TYPE AMCL_TEST_PUBLIC
  #define AMCL_TEST_LOCAL
#else
  #define AMCL_TEST_EXPORT __attribute__ ((visibility("default")))
  #define AMCL_TEST_IMPORT
  #if __GNUC__ >= 4
    #define AMCL_TEST_PUBLIC __attribute__ ((visibility("default")))
    #define AMCL_TEST_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AMCL_TEST_PUBLIC
    #define AMCL_TEST_LOCAL
  #endif
  #define AMCL_TEST_PUBLIC_TYPE
#endif
#endif  // AMCL_TEST__VISIBILITY_CONTROL_H_
// Generated 12-Feb-2023 15:27:43
// Copyright 2019-2020 The MathWorks, Inc.
