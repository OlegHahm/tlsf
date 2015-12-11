#ifndef __TLSF_MALLOC_H
#define __TLSF_MALLOC_H

#include <stdbool.h>
#include <stddef.h>

#include "tlsf.h"

#ifndef TLSF_MALLOC_PREFIX
#   define TLSF_MALLOC_PREFIX
#endif
#define __TLSF_MALLOC_NAME(A, B) A ## B
#define _TLSF_MALLOC_NAME(A, B) __TLSF_MALLOC_NAME(A, B)
#define TLSF_MALLOC_NAME(NAME) _TLSF_MALLOC_NAME(TLSF_MALLOC_PREFIX, NAME)

void *TLSF_MALLOC_NAME(malloc)(size_t bytes);

void *TLSF_MALLOC_NAME(calloc)(size_t count, size_t bytes);

void *TLSF_MALLOC_NAME(memalign)(size_t align, size_t bytes);

void *TLSF_MALLOC_NAME(realloc)(void *ptr, size_t size);

void TLSF_MALLOC_NAME(free)(void *ptr);

#endif
