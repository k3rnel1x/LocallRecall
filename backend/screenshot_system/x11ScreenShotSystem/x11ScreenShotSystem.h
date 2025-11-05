#ifndef SCREENSHOT_H
#define SCREENSHOT_H
#include <X11/Xlib.h>

// текущая реализация - создание скриншота окна в фокусе
class x11ScreenShotSystem {
private:
    bool _init = false;                 // ready for screenshot
    Display* global_display = NULL;
    XImage* ximage = NULL;
    Window root_win = 0;
    Window target_window = 0;
    XWindowAttributes attributes = {0};

    Window getActiveWindow(Display *display, Window root);

public:
    int Init();                 // returns is init complete
    XImage* GetActiveWinShot();
    void End();                 // cleanup resources
};

#endif //SCREENSHOT_H
