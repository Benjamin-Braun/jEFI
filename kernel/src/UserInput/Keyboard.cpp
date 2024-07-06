#include "Keyboard.h"

    bool IsLeftShiftPressed;
    bool IsRightShiftPressed;

void HandleKeyboard(uint8_t Scancode){

    switch (Scancode){
        case KEY_LEFT_SHIFT:
            IsLeftShiftPressed = true;
            return;
        case KEY_LEFT_SHIFT + 0x80:
            IsLeftShiftPressed = false;
            return;
        case KEY_RIGHT_SHIFT:
            IsRightShiftPressed = true;
            return;
        case KEY_RIGHT_SHIFT + 0x80:
            IsRightShiftPressed = false;
            return;
        case KEY_ENTER:
            GlobalRenderer->Next();
            return;
        case KEY_SPACEBAR:
            GlobalRenderer->PutChar(' ');
            return;
        case KEY_BACKSPACE:
           GlobalRenderer->ClearChar();
           return;
    }

    char ASCII = QWERTYKeyboard::Translate(Scancode, IsLeftShiftPressed | IsRightShiftPressed);

    if (ASCII != 0){
        GlobalRenderer->PutChar(ASCII);
    }

}