#ifndef USBCAMERA_H
#define USBCAMERA_H

// Include files to use the PYLON API.
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif
#include <QFile>
#include <QObject>
#include "time.h"
#include "stringmodel.h"
//#include "mainwindow.h"

#define BUFFERSIZE 256
#define WIDTH 1600
#define HEIGHT 1200

//class MainWindow;

// Namespace for using pylon objects.
using namespace Pylon;

// Namespace for using cout.
using namespace std;

class usbCamera : public QObject
{
    Q_OBJECT
public:
    usbCamera();
    int connect();
    int saveConfig();
    int loadConfig();
    int getFrame();
    int terminateCameraConnection();

    // Number of images to be grabbed.
    static const uint32_t c_countOfImagesToGrab = 100;
    uint8_t sharedData[BUFFERSIZE][WIDTH * HEIGHT];
    int circularSharedBufferPtr = -1;

private:
    stringModel stringModelIns;
    CInstantCamera *camera;

    // This smart pointer will receive the grab result data.
    CGrabResultPtr ptrGrabResult;

signals:
    void frameIsReady(const u_int8_t *data, int imageSize);

};

#endif // USBCAMERA_H
