#pragma once

#include "main.h"

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

enum ConversionTypes {
    ToCpp,
    ToLua,
    ToPython
};