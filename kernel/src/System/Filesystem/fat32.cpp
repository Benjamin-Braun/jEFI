#include "fat32.h"

namespace FAT32 {
    FAT32_BootSector bootSector;

    void ReadBootSector(){
       bootSector.bytes_per_sec = GlobalAHCI->ReadPort(0, 3);
    }

    void PrintBootSector(){
        MainShell->Print("LOL");
    }
}