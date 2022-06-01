#include <Windows.h>

using namespace std;

#pragma comment(lib, "gdi32.lib") // these to line is important for loading the libraries.
#pragma comment(lib, "user32.lib")

LPCWSTR windowClassName = (LPCWSTR) "SimpleWindow";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCMDLine, int nCMDShow)
{
    // Making a Class
    WNDCLASSEXW windowClass = {0};
    windowClass.cbClsExtra = 0;                                               // Any other information for class.
    windowClass.cbSize = sizeof(windowClass);                                 // The size of class to allocate in memory
    windowClass.cbWndExtra = 0;                                               // Any other information about the hWND handler.
    windowClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255)); // Background Color of the Class
    windowClass.hCursor = LoadCursor(hInstance, IDC_ARROW);                   // Defining the cursor for window.
    windowClass.hIcon = LoadIcon(hInstance, IDI_HAND);                        // Defining Icon for Task Bar.
    windowClass.hIconSm = LoadIcon(hInstance, IDI_ERROR);                     // Defining Icon for Window.
    windowClass.hInstance = hInstance;                                        // Default Argument.
    windowClass.lpfnWndProc = DefWindowProc;                                  // Defining Procedure for Window Class.
    windowClass.lpszClassName = windowClassName;                              // Defining the Specific class name for application.
    windowClass.lpszMenuName = 0;                                             // Giving any information about menu.
    windowClass.style = CS_VREDRAW | CS_HREDRAW;                              // Giving the Style for all windows that was in this class.

    RegisterClassExW(&windowClass); // Registring the Class in Memory.

    // Making a Window -> HWND

    HWND hWndWindow = CreateWindowExW(WS_EX_APPWINDOW,                  // Window Type
                                      windowClassName,                  // Window Class That that we define above.
                                      (LPCWSTR) "Application Name",     // Window Name that appear in the title bar.
                                      WS_OVERLAPPEDWINDOW | WS_VISIBLE, // Giving style to the window.
                                      200,                              // X position of the window
                                      200,                              // y position of the window.
                                      800,                              // width of the window.
                                      600,                              // height of the window.
                                      NULL,                             // Parent window. We have no parent window.
                                      NULL,                             // Menu of the window.
                                      hInstance,                        // HINSTANCE that we define above
                                      NULL                              // LPARAM but we have no lparam because it is parent window.
    );

    // Defining Event or Message Handler
    MSG msg;

    while (GetMessage(&msg, hWndWindow, 0, 0))
    {
        TranslateMessage(&msg); // Translate the message and give it to window procedure
        DispatchMessage(&msg); // dispatch the message and clear the memory.
    }

    return 0;
}
