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
    bool resizable;
    //uint32_t screen[1920*1080];

    void Start();
    void Update();
    void OnExit();
};

class jWin{
public:
    jWin();
    void DrawDesktop();
    void DrawWindows();
    void DrawWindowBorders(bool removeOld = false);
    void DrawAll();
    int AddWindow(jWin_Window* win);
    void LeftMouseButtonPressed();
    void MiddleMouseButtonPressed();
    void RightMouseButtonPressed();
    void HandleKeyPress(uint8_t Scancode);
    void HandleMouse();
    uint32_t WindowCount;
    uint32_t ActiveWindow;
    jWin_Window* windows[8];
    bool active;
private:
    bool IsLeftShiftPressed;
    bool IsRightShiftPressed;
    bool IsAltPressed;
};

extern jWin* MainWin;