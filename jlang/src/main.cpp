#include "main.h"

void PrintVersion(){
    cout << "JLC v" << VERSION << "\n\nCopyright (c) 2024 Benjamin Braun\nLicensed under MIT" << endl;
}

void ParseArgs(int argc, char* argv[]){
    File file;
    bool conversion = false;
    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) PrintVersion();
        if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--convert") == 0) conversion = true;
        if(strcmp(argv[i], "--cpp") == 0 && conversion) file.ConvType = ConversionTypes::ToCpp;
    }
}

int main(int argc, char* argv[]){
    ParseArgs(argc, argv);
    return 0;
}