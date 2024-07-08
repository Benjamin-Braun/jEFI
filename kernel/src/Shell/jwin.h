#pragma once
#include <stdint.h>
#include "gui.h"
#include "../Graphics/BasicRenderer.h"
#include "../UserInput/KBScancodeTranslation.h"
#include "../Misc/CStr.h"
#include "../System/Memory/Memory.h"
#include "../System/KernelUtil.h"
#include "../System/Scheduling/PIT/PIT.h"
#include "../System/PCI/PCI.h"
#include "../System/AHCI/AHCI.h"

class jWin_Window {
public:
    uint32_t SizeX;
    uint32_t SizeY;
    uint32_t PositionX;
    uint32_t PositionY;
    const char* title;
};

class jWin{
public:
    jWin();
    void DrawDesktop();
    void DrawWindows();
    void DrawAll();
    int AddWindow(jWin_Window* win);
    void LeftMouseButtonPressed();
    void MiddleMouseButtonPressed();
    void RightMouseButtonPressed();
    int WindowCount;
    jWin_Window* windows[8];
    bool active;
};

extern jWin* MainWin;