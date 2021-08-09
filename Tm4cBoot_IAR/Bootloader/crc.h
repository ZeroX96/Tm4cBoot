#ifndef CRC_H
#define CRC_H

#include <stdlib.h>
#include <stdint.h>

#define CRC_ALGO_TABLE_DRIVEN 1


/**
 * The type of the CRC values.
 *
 * This type must be big enough to contain at least 32 bits.
 */
typedef uint_fast32_t crc_t;

static inline crc_t crc_init(void)
{
    return 0xffffffff;
}

crc_t crc_update(crc_t crc, const void *data, size_t data_len);

static inline crc_t crc_finalize(crc_t crc)
{
    return crc ^ 0xffffffff;
}


#endif      /* CRC_H */
