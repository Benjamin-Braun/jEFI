#pragma once
#include <stdint.h>
#include "../Graphics/BasicRenderer.h"
#include "../UserInput/KBScancodeTranslation.h"
#include "../Misc/CStr.h"
#include "../System/Memory/Memory.h"
#include "../System/KernelUtil.h"
#include "../System/Scheduling/PIT/PIT.h"
#include "../System/PCI/PCI.h"
#include "../System/AHCI/AHCI.h"

#define JGUI_VERSION "0.1.0"

class Titlebar {
public:
    void Draw();
};

extern Titlebar* MainTitle;