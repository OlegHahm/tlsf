#include "irq.h"
#include "tlsf-malloc.h"

#include <string.h>

void *TLSF_MALLOC_NAME(malloc)(size_t bytes)
{
    unsigned old_state = disableIRQ();
    void *result = tlsf_malloc(bytes);
    restoreIRQ(old_state);
    return result;
}

void *TLSF_MALLOC_NAME(calloc)(size_t count, size_t bytes)
{
    void *result = tlsf_malloc(count * bytes);
    if (result) {
        memset(result, 0, count * bytes);
    }
    return result;
}

void *TLSF_MALLOC_NAME(memalign)(size_t align, size_t bytes)
{
    unsigned old_state = disableIRQ();
    void *result = tlsf_memalign(align, bytes);
    restoreIRQ(old_state);
    return result;
}

void *TLSF_MALLOC_NAME(realloc)(void *ptr, size_t size)
{
    unsigned old_state = disableIRQ();
    void *result = tlsf_realloc(ptr, size);
    restoreIRQ(old_state);
    return result;
}

void TLSF_MALLOC_NAME(free)(void *ptr)
{
    unsigned old_state = disableIRQ();
    tlsf_free(ptr);
    restoreIRQ(old_state);
}
