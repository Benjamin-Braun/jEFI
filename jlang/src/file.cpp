#include "file.h"

void File::ConvertFile(){
    if(this->ConvType == ConversionTypes::ToCpp) this->ConvertToCpp();
}

void File::ConvertToCpp(){
    cout << "Bruh" << endl;
}