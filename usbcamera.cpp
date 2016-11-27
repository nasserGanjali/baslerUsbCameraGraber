#include "usbcamera.h"

usbCamera::usbCamera() : QObject()
{
    camera = NULL;
}

int usbCamera::connect()
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized.
    PylonInitialize();

    try
    {
        // Create an instant camera object with the camera device found first.
        camera = new CInstantCamera( CTlFactory::GetInstance().CreateFirstDevice());

        // Print the model name of the camera.
        cout << "Using device " << camera->GetDeviceInfo().GetModelName() << endl;

        // The parameter MaxNumBuffer can be used to control the count of buffers
        // allocated for grabbing. The default value of this parameter is 10.
        camera->MaxNumBuffer = 5;

        // Start the grabbing of c_countOfImagesToGrab images.
        // The camera device is parameterized with a default configuration which
        // sets up free-running continuous acquisition.

    }
    catch (const GenericException &e)
    {
        // Error handling.
        cerr << "An exception occurred." << endl
             << e.GetDescription() << endl;
        exitCode = 1;
    }

    return exitCode;
}

int usbCamera::terminateCameraConnection()
{
    int exitCode = 0;

    // Releases all pylon resources.
    PylonTerminate();
    camera = NULL;

    return exitCode;
}

int usbCamera::loadConfig()
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized.
    PylonInitialize();

    try
    {
        // Create an instant camera object with the camera device found first.
        camera = new CInstantCamera( CTlFactory::GetInstance().CreateFirstDevice());

        // Print the model name of the camera.
        cout << "Using device " << camera->GetDeviceInfo().GetModelName() << endl;

        // Open the camera.
        camera->Open();

        // Just for demonstration, read the content of the file back to the camera's node map with enabled validation.
        cout << "Reading file back to camera's node map..."<< endl;
        const char *fileName = stringModelIns.configFileName.toLocal8Bit().data();
        CFeaturePersistence::Load( fileName, &camera->GetNodeMap(), true );

        // Close the camera.
        camera->Close();
    }
    catch (const GenericException &e)
    {
        // Error handling.
        cerr << "An exception occurred." << endl
             << e.GetDescription() << endl;
        exitCode = 1;
    }

    // Comment the following two lines to disable waiting on exit

    // Releases all pylon resources.
    PylonTerminate();

    return exitCode;
}

int usbCamera::getFrame()
{
    camera->StartGrabbing(1);

    // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
    // when c_countOfImagesToGrab images have been retrieved.
    clock_t begin = clock();
    int counter = 0;
    while ( camera->IsGrabbing())
    {
        // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
        camera->RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);

        // Image grabbed successfully?
        if (ptrGrabResult->GrabSucceeded())
        {
            // Access the image data.
            counter ++;
//            cout << "SizeX: " << ptrGrabResult->GetWidth() << endl;
//            cout << "SizeY: " << ptrGrabResult->GetHeight() << endl;
            const uint8_t *pImageBuffer = (uint8_t *) ptrGrabResult->GetBuffer();

            emit frameIsReady(pImageBuffer, ptrGrabResult->GetImageSize());
        }
        else
        {
            cout << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
        }
    }
//    QFile file("/tmp/file");
//    file.open(QFile::WriteOnly);
//    file.write((const char *)ptrGrabResult->GetBuffer(),ptrGrabResult->GetImageSize());
//    file.close();
    clock_t end = clock();
    cout << "total time :" <<(double)(end - begin) / CLOCKS_PER_SEC << endl;
//    cout << counter / ((double)(end - begin) / CLOCKS_PER_SEC) << " fps"<<endl;
}
