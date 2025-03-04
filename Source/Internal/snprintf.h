#ifndef _PORTABLE_SNPRINTF_H_
#define _PORTABLE_SNPRINTF_H_

#ifdef __GNU_LIBRARY__ //We already have these features in GCC
#include <stdio.h>
#else

#define PORTABLE_SNPRINTF_VERSION_MAJOR 2
#define PORTABLE_SNPRINTF_VERSION_MINOR 2

#ifdef HAVE_SNPRINTF
#include <stdio.h>
#else
extern "C" {
extern int snprintf(char *, size_t, const char *, /*args*/ ...);
}
#ifndef NEED_SNPRINTF_ONLY
extern "C" {
extern int vsnprintf(char *, size_t, const char *, va_list);
}
#endif
#endif

#if defined(HAVE_SNPRINTF) && defined(PREFER_PORTABLE_SNPRINTF)
extern "C" {
extern int portable_snprintf(char *str, size_t str_m, const char *fmt, /*args*/ ...);
extern int portable_vsnprintf(char *str, size_t str_m, const char *fmt, va_list ap);
}
#define snprintf  portable_snprintf
#define vsnprintf portable_vsnprintf
#endif

extern "C" {
extern int asprintf  (char **ptr, const char *fmt, /*args*/ ...);
extern int vasprintf (char **ptr, const char *fmt, va_list ap);
extern int asnprintf (char **ptr, size_t str_m, const char *fmt, /*args*/ ...);
extern int vasnprintf(char **ptr, size_t str_m, const char *fmt, va_list ap);
}

#endif
#endif
