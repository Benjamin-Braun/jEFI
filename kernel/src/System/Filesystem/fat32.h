#pragma once

#include "../AHCI/AHCI.h"
#include "../../Graphics/BasicRenderer.h"
#include "../../Shell/Shell.h"

namespace FAT32 {
    struct FAT32_BootSector {
        char jump[3]; // 3-Bytes we don't use
        char oem_identifier[8];
        uint32_t bytes_per_sec;
        uint32_t sectors_per_cluster;
        uint32_t reserved_sectors;
        uint32_t fat_count;
        uint32_t dir_entry_count;
        uint32_t total_sectors;
        uint32_t mdia_descriptor_type;
        uint32_t sectors_per_fat;
        uint32_t sectors_per_track;
        uint32_t heads;
        uint32_t hidden_sectors;
        uint32_t large_sector_count;
    };

    void ReadBootSector();
    void PrintBootSector();
}