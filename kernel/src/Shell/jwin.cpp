#include "jwin.h"

jWin* MainWin;

jWin::jWin(){
    this->WindowCount = 0;
    this->active = false;
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
    active = true;
    GlobalRenderer->ClearColour = 0x008080;
    GlobalRenderer->Clear();
    MainTitle->Draw();
}

void jWin::DrawWindows(){
    for(int i=0; i<this->WindowCount; i++){
        GlobalRenderer->DrawRect(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeX, this->windows[i]->SizeY, 0x0000ff);
        GlobalRenderer->DrawRect(this->windows[i]->PositionX+1, this->windows[i]->PositionY+16, this->windows[i]->SizeX-1, this->windows[i]->SizeY-1, 0x000000);
        Point a = GlobalRenderer->CursorPosition;
        GlobalRenderer->CursorPosition = {this->windows[i]->PositionX, this->windows[i]->PositionY};
        GlobalRenderer->Print(this->windows[i]->title);
        GlobalRenderer->CursorPosition = a;
    }
}

void jWin::DrawAll(){
    this->DrawDesktop();
    this->DrawWindows();
}

void jWin::LeftMouseButtonPressed(){
    for(int i=0; i<this->WindowCount; i++){
        if(MousePosition.X >= this->windows[i]->PositionX && MousePosition.X <= this->windows[i]->PositionX + this->windows[i]->SizeX){
            if(MousePosition.Y >= this->windows[i]->PositionY && MousePosition.Y <= this->windows[i]->PositionY + 10){
                this->windows[i]->PositionX = MousePosition.X - (MousePosition.X - this->windows[i]->PositionX);
                this->windows[i]->PositionY = MousePosition.Y - (MousePosition.Y - this->windows[i]->PositionY);
                this->DrawWindows();
            }
        }
    }
}

void jWin::MiddleMouseButtonPressed(){

}

void jWin::RightMouseButtonPressed(){

}