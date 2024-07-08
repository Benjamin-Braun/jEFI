#include "jwin.h"

jWin* MainWin;

jWin::jWin(){
    this->WindowCount = 0;
}

int jWin::AddWindow(jWin_Window* win){
    if(this->WindowCount >= 7){
        return 1;
    }
    this->windows[this->WindowCount] = win;
    this->WindowCount++;
    return 0;
}

void jWin::DrawDesktop(){
    GlobalRenderer->ClearColour = 0x008080;
    GlobalRenderer->Clear();
    MainTitle->Draw();
}

void jWin::DrawWindows(){
    for(int i=0; i<this->WindowCount; i++){
        for(int y=0; y<this->windows[i]->SizeY; y++){
            for(int x=0; x<this->windows[i]->SizeX; x++){
                GlobalRenderer->PutPix(x, y, 0xffffff);
            }
        }
    }
}

void jWin::DrawAll(){
    this->DrawDesktop();
    this->DrawWindows();
}