#include "code/utilities/random/rand_impls/mwc1616.hpp"

static ulong mwc1616_x = 1;
static ulong mwc1616_y = 2;

void seed_rand_mwc1616(ulong seed) {
    mwc1616_x = seed | 1;   /* Can't seed with 0 */
    mwc1616_y = seed | 2;
}

ulong rand_mwc1616(void) {
    mwc1616_x = 18000 * (mwc1616_x & 0xffff) + (mwc1616_x >> 16);
    mwc1616_y = 30903 * (mwc1616_y & 0xffff) + (mwc1616_y >> 16);
    return (mwc1616_x<<16)+(mwc1616_y&0xffff);
}
