#include "../AHCI/AHCI.h"

struct BootSector {
    uint32_t bytes_per_sec;
    uint32_t sectors_per_cluster;
    uint32_t reserved_sectors;
};