#ifndef INCLUDED_tlsf
#define INCLUDED_tlsf

/*
** Two Level Segregated Fit memory allocator, version 3.0.
** Written by Matthew Conte, and placed in the Public Domain.
**	http://tlsf.baisoku.org
**
** Based on the original documentation by Miguel Masmano:
**	http://rtportal.upv.es/rtmalloc/allocators/tlsf/index.shtml
**
** Please see the accompanying Readme.txt for implementation
** notes and caveats.
**
** This implementation was written to the specification
** of the document, therefore no GPL restrictions apply.
*/

#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* Create/destroy a memory pool. */
void tlsf_create(void* mem);
void tlsf_create_with_pool(void* mem, size_t bytes);

/* Add/remove memory pools. */
int tlsf_add_pool(void* mem, size_t bytes);

/* malloc/memalign/realloc/free replacements. */
void* tlsf_malloc(size_t bytes);
void* tlsf_memalign(size_t align, size_t bytes);
void* tlsf_realloc(void* ptr, size_t size);
void tlsf_free(void* ptr);

#ifdef DEVELHELP
void tlsf_walk_pool(void *pool);
#endif

#if defined(__cplusplus)
};
#endif

#endif
