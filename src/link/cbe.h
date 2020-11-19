#if __STDC_VERSION__ >= 199901L
// C99 or newer
#include <stdbool.h>
#else
#define bool unsigned char
#define true 1
#define false 0
#endif

#if __STDC_VERSION__ >= 201112L
#define zig_noreturn _Noreturn
#elif __GNUC__
#define zig_noreturn __attribute__ ((noreturn))
#elif _MSC_VER
#define zig_noreturn __declspec(noreturn)
#else
#define zig_noreturn
#endif

#if __GNUC__
#define zig_unreachable() __builtin_unreachable()
#else
#define zig_unreachable()
#endif

