#pragma once

#if defined(_WIN32) && defined(__linux__)
#error "Conflicting platform macros defined"
#endif

#if defined(_WIN32)
#define IS_WIN32 true
#define IS_LINUX false
#elif defined(__linux__)
#define IS_WIN32 false
#define IS_LINUX true
#endif
