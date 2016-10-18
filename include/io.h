#ifndef IO_H
#define IO_H

#include <stdbool.h>

static void outb(uint16_t port, uint8_t val);

static uint8_t inb(uint16_t port);

static inline bool irq_enabled()
{
    unsigned long flags;
    asm volatile ( "pushf\n\t"
                   "pop %0"
                   : "=g"(flags) );
    return flags & (1 << 9);
}

#endif//IO_H
