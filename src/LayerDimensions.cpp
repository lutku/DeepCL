#include <iostream>
#include <ostream>

#include "stringhelper.h"

#include "LayerDimensions.h"

using namespace std;

ostream &operator<<( ostream &os, const LayerDimensions &dim ) {
    os << "LayerDimensions{";
    os << " inputPlanes=" << dim.inputPlanes;
    os << " inputBoardSize=" << dim.inputBoardSize;
    os << " numFilters=" << dim.numFilters;
    os << " filterSize=" << dim.filterSize;
    os << " outputBoardSize=" << dim.outputBoardSize;
    os << " padZeros=" << dim.padZeros;
    os << " biased=" << dim.biased;
    os << " skip=" << dim.skip;
    os << "}";
    return os;
}

string LayerDimensions::buildOptionsString() {
    string options = "";
    if( biased ) {
         options += " -D BIASED";
    }
    options += " -D gNumInputPlanes=" + toString(inputPlanes);
    options += " -D gInputPlanes=" + toString(inputPlanes);
    options += " -D gInputBoardSize=" + toString(inputBoardSize);
    options += " -D gInputBoardSizeSquared=" + toString(square(inputBoardSize));
    options += " -D gNumFilters=" + toString(numFilters);
    options += " -D gFilterSize=" + toString(filterSize);
    options += " -D gHalfFilterSize=" + toString( filterSize >> 1 );
    options += " -D gFilterSizeSquared=" + toString(square(filterSize));
    options += " -D gNumOutputPlanes=" + toString(numFilters);
    options += " -D gOutputPlanes=" + toString(numFilters);
    options += " -D gOutputBoardSize=" + toString(outputBoardSize);
    options += " -D gOutputBoardSizeSquared=" + toString(square(outputBoardSize));
    options += " -D gPadZeros=" + toString(padZeros ? 1 : 0);
    options += " -D gMargin=" + toString(padZeros ? filterSize >> 1 : 0);
    options += " -D gEven=" + toString(filterSize % 2 == 0 ? 1 : 0);
    options += " -D gSkip=" + toString(skip);
    return options;
}

