#include "irq.h"
#include "tlsf-malloc.h"

#include <string.h>

void *TLSF_MALLOC_NAME(malloc)(size_t bytes)
{
    unsigned old_state = irq_disable();
    void *result = tlsf_malloc(bytes);
    irq_restore(old_state);
    return result;
}

void *TLSF_MALLOC_NAME(calloc)(size_t count, size_t bytes)
{
    unsigned old_state = irq_disable();
    void *result = tlsf_malloc(count * bytes);
    if (result) {
        memset(result, 0, count * bytes);
    }
    irq_restore(old_state);
    return result;
}

void *TLSF_MALLOC_NAME(memalign)(size_t align, size_t bytes)
{
    unsigned old_state = irq_disable();
    void *result = tlsf_memalign(align, bytes);
    irq_restore(old_state);
    return result;
}

void *TLSF_MALLOC_NAME(realloc)(void *ptr, size_t size)
{
    unsigned old_state = irq_disable();
    void *result = tlsf_realloc(ptr, size);
    irq_restore(old_state);
    return result;
}

void TLSF_MALLOC_NAME(free)(void *ptr)
{
    unsigned old_state = irq_disable();
    tlsf_free(ptr);
    irq_restore(old_state);
}
