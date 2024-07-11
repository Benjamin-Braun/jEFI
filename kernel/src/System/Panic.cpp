#include "Panic.h"
#include "../Graphics/BasicRenderer.h"

void Panic(const char* PanicMessage){
    GlobalRenderer->ClearColour = 0x00ff0000;
    GlobalRenderer->Clear();

    GlobalRenderer->CursorPosition = {0, 0};

    for(int y=0; y<GlobalRenderer->TargetFramebuffer->Height/16; y++){
        for(int i=0; i<GlobalRenderer->TargetFramebuffer->Width/4/8; i++){
            GlobalRenderer->Print(" :( ", 0xbb0000);
        }
    }

    GlobalRenderer->CursorPosition = {0, 0};

    GlobalRenderer->Colour = 0xffffffff;

    GlobalRenderer->Print("Kernel Panic! Everything is wrecked!");

    GlobalRenderer->Next();
    GlobalRenderer->Next();

    GlobalRenderer->Print("Want some infos? Here ya go:\n");

    GlobalRenderer->Print(PanicMessage);

    while(true) asm("hlt");
}