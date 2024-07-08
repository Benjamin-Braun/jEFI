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
    int SizeX;
    int SizeY;
};

class jWin{
public:
    jWin();
    void DrawDesktop();
    void DrawWindows();
    void DrawAll();
    int AddWindow(jWin_Window* win);
    int WindowCount;
    jWin_Window* windows[8];
};

extern jWin* MainWin;