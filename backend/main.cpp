#include "screenshot_system/x11ScreenShotSystem/x11ScreenShotSystem.h"
#include <X11/Xlib.h>

int main()
{
    x11ScreenShotSystem ssystem;
    ssystem.Init();
    XImage* ximage = ssystem.GetActiveWinShot();

    ssystem.End();
    return 0;
}
