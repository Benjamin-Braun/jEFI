#pragma once

#include "main.h"

enum ConversionTypes {
    ToCpp,
    ToLua,
    ToPython
};

class File {
public:
    string input_filename;
    string output_filename;
    ConversionTypes ConvType;

    void ConvertFile();
private:
    void ConvertToCpp();
    void ConvertToLua();
    void ConvertToPython();
};