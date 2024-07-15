#include "jwin.h"

jWin* MainWin;

jWin::jWin(){
    this->WindowCount = 0;
    this->active = false;
    this->ActiveWindow = 0;
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
        if(ActiveWindow == i){
            GlobalRenderer->DrawRect(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeX, this->windows[i]->SizeY, 0x0000ff);
            //for(int y=0; y<this->windows[i]->SizeY-1; y++){
            //    for(int x=0; x<this->windows[i]->SizeX-1; x++){
            //        GlobalRenderer->PutPix(this->windows[i]->PositionX+1+x, this->windows[i]->PositionY+16+y, this->windows[i]->screen[(y*1920)+x]);
            //    }
            //}
            Point a = GlobalRenderer->CursorPosition;
            GlobalRenderer->CursorPosition = {this->windows[i]->PositionX, this->windows[i]->PositionY};
            GlobalRenderer->Print(this->windows[i]->title);
            GlobalRenderer->CursorPosition = a;
        }else{
            GlobalRenderer->DrawRect(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeX, this->windows[i]->SizeY, 0x000088);
            //for(int y=0; y<this->windows[i]->SizeY-1; y++){
            //    for(int x=0; x<this->windows[i]->SizeX-1; x++){
            //        GlobalRenderer->PutPix(this->windows[i]->PositionX+1+x, this->windows[i]->PositionY+16+y, this->windows[i]->screen[(y*1920)+x]);
            //    }
            //}
            Point a = GlobalRenderer->CursorPosition;
            uint32_t b = GlobalRenderer->Colour;
            GlobalRenderer->CursorPosition = {this->windows[i]->PositionX, this->windows[i]->PositionY};
            GlobalRenderer->Colour = 0x777777;
            GlobalRenderer->Print(this->windows[i]->title);
            GlobalRenderer->CursorPosition = a;
            GlobalRenderer->Colour = b;
        }
    }
    GlobalRenderer->DrawRect(this->windows[this->ActiveWindow]->PositionX, this->windows[this->ActiveWindow]->PositionY, this->windows[this->ActiveWindow]->SizeX, this->windows[this->ActiveWindow]->SizeY, 0x0000ff);
    //for(int y=0; y<this->windows[this->ActiveWindow]->SizeY-1; y++){
    //    for(int x=0; x<this->windows[this->ActiveWindow]->SizeX-1; x++){
    //        GlobalRenderer->PutPix(this->windows[this->ActiveWindow]->PositionX+1+x, this->windows[this->ActiveWindow]->PositionY+16+y, this->windows[this->ActiveWindow]->screen[(y*1920)+x]);
    //    }
    //}
    Point a = GlobalRenderer->CursorPosition;
    GlobalRenderer->CursorPosition = {this->windows[this->ActiveWindow]->PositionX, this->windows[this->ActiveWindow]->PositionY};
    GlobalRenderer->Print(this->windows[this->ActiveWindow]->title);
    GlobalRenderer->CursorPosition = a;
}

void jWin::DrawWindowBorders(bool removeOld){
    for(int i=0; i<this->WindowCount; i++){
        if(removeOld){
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeX, 0x008080);
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY+10, this->windows[i]->SizeX, 0x008080);
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeY, 0x008080, true);
        }else{
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeX, 0x777777);
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY+10, this->windows[i]->SizeX, 0x777777);
            GlobalRenderer->DrawStraightLine(this->windows[i]->PositionX, this->windows[i]->PositionY, this->windows[i]->SizeY, 0x777777, true);
        }
    }
    if(!removeOld){
        GlobalRenderer->DrawStraightLine(this->windows[this->ActiveWindow]->PositionX, this->windows[this->ActiveWindow]->PositionY, this->windows[this->ActiveWindow]->SizeX, 0xffffff);
        GlobalRenderer->DrawStraightLine(this->windows[this->ActiveWindow]->PositionX, this->windows[this->ActiveWindow]->PositionY+10, this->windows[this->ActiveWindow]->SizeX, 0xffffff);
        GlobalRenderer->DrawStraightLine(this->windows[this->ActiveWindow]->PositionX, this->windows[this->ActiveWindow]->PositionY, this->windows[this->ActiveWindow]->SizeY, 0xffffff, true);
    }
}

void jWin::DrawAll(){
    this->DrawDesktop();
    this->DrawWindows();
}

void jWin::LeftMouseButtonPressed(){
    
}

void jWin::MiddleMouseButtonPressed(){

}

void jWin::RightMouseButtonPressed(){

}

void jWin::HandleKeyPress(uint8_t Scancode){
    //if(MainKernel->BootState < 3) return;
    switch (Scancode){
        case KEY_F1:
            this->active = false;
            MainShell->Start();
            MainShell->RunShell();
            return;

        case KEY_F2:
            MainWin->active = true;
            MainWin->DrawAll();
            return;

        //if(MainKernel->BootState < 4) return;

        case KEY_LEFT_SHIFT:
            this->IsLeftShiftPressed = true;
            return;
        case KEY_LEFT_SHIFT + 0x80:
            this->IsLeftShiftPressed = false;
            return;
        case KEY_RIGHT_SHIFT:
            this->IsRightShiftPressed = true;
            return;
        case KEY_RIGHT_SHIFT + 0x80:
            this->IsRightShiftPressed = false;
            return;
        case KEY_ENTER:
            // //
            return;
        case KEY_SPACEBAR:
            // //
            return;
        case KEY_BACKSPACE:
           // //
           return;
        case KEY_LEFT_ALT:
            if(!this->IsAltPressed){
                this->DrawDesktop();
                this->DrawWindowBorders();
            }
            this->IsAltPressed = true;
            return;
        case KEY_LEFT_ALT + 0x80:
            this->IsAltPressed = false;
            this->DrawAll();
            return;

        case KEY_F12:
            // //
            return;
    }

    //if(MainKernel->BootState < 4) return;
    char ASCII = QWERTYKeyboard::Translate(Scancode, IsLeftShiftPressed | IsRightShiftPressed);
    if (ASCII != 0){
        if(this->IsAltPressed){
            uint32_t tmp = 5;
            if(this->IsLeftShiftPressed && this->windows[ActiveWindow]->resizable || this->IsRightShiftPressed && this->windows[ActiveWindow]->resizable){
                if(ASCII == 'd' || ASCII == 'D'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->SizeX += tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 'a' || ASCII == 'A'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->SizeX -= tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 'w' || ASCII == 'W'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->SizeY -= tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 's' || ASCII == 'S'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->SizeY += tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
            }else{
                if(ASCII == 'd' || ASCII == 'D'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->PositionX += tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 'a' || ASCII == 'A'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->PositionX -= tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 'w' || ASCII == 'W'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->PositionY -= tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
                if(ASCII == 's' || ASCII == 'S'){
                    this->DrawWindowBorders(true);
                    this->windows[ActiveWindow]->PositionY += tmp;
                    this->DrawWindowBorders();
                    tmp++;
                }
            }

            if(ASCII == 'e' || ASCII == 'E'){
                if(this->ActiveWindow < this->WindowCount-1) this->ActiveWindow++;
                this->DrawWindowBorders();
            }
            if(ASCII == 'q' || ASCII == 'Q'){
                if(this->ActiveWindow > 0) this->ActiveWindow--;
                this->DrawWindowBorders();
            }
        }
    }
}

void jWin::HandleMouse(){
    uint32_t OldAW = this->ActiveWindow;
    for(int i=0; i<this->WindowCount; i++){
        if(MousePosition.X >= this->windows[i]->PositionX && MousePosition.X <= this->windows[i]->PositionX + this->windows[i]->SizeX){
            if(MousePosition.Y >= this->windows[i]->PositionY && MousePosition.Y <= this->windows[i]->PositionY + this->windows[i]->SizeY){
                this->ActiveWindow = i;
                if(OldAW != this->ActiveWindow) this->DrawAll();
            }
        }
    }
}