#include "gui.h"

Titlebar* MainTitle;

void Titlebar::Draw(){
    for(int i=0; i<GlobalRenderer->TargetFramebuffer->Width/8; i++){
        GlobalRenderer->Print("\a", COLOR_BLUE);
    }
    GlobalRenderer->CursorPosition = {0, 0};
    GlobalRenderer->Print("The J Operating System", COLOR_YELLOW);
}