#include "System/KernelUtil.h"
#include "System/Memory/Heap.h"
#include "System/Scheduling/PIT/PIT.h"
#include "System/Panic.h"

extern "C" void KernelStart(BootInfo* BootInfo){
    KernelInfo KernelInfo = InitializeKernel(BootInfo);
    MainShell->Start();

    //MainWin->active = true;
    //jWin_Window newWin; newWin.title = "Hello World!";
    //newWin.SizeX = 800; newWin.SizeY = 600;
    //newWin.PositionX = 100; newWin.PositionY = 100;
    //MainWin->AddWindow(&newWin);
    //MainWin->DrawAll();

    //GlobalRenderer->Print("\nPress F1 to start Shell.\nPress F2 to start Graphical User Interface.\n");
    while(true){
        MainKernel->Loop();
    }
}