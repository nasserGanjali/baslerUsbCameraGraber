#ifndef USBCAMERA_H
#define USBCAMERA_H

// Include files to use the PYLON API.
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif
#include "time.h"
#include <QFile>

// Namespace for using pylon objects.
using namespace Pylon;

// Namespace for using cout.
using namespace std;

class usbCamera
{
public:
    usbCamera();
    int main();

    // Number of images to be grabbed.
    static const uint32_t c_countOfImagesToGrab = 100;

};

#endif // USBCAMERA_H
