#include "System/KernelUtil.h"
#include "System/Memory/Heap.h"
#include "System/Scheduling/PIT/PIT.h"

extern "C" void KernelStart(BootInfo* BootInfo){
    KernelInfo KernelInfo = InitializeKernel(BootInfo);
    jWin_Window newWin;
    newWin.PositionX = 100;
    newWin.PositionY = 100;
    newWin.SizeX = 800;
    newWin.SizeY = 600;
    newWin.title = "Hello World!";
    MainWin->AddWindow(&newWin);
    MainWin->DrawAll();
    //MainShell->Start();
    //GlobalRenderer->Print("\nPress F1 to start Shell.\nPress F2 to start Graphical User Interface.\n");
    while(true){
        MainKernel->Loop();
    }
}