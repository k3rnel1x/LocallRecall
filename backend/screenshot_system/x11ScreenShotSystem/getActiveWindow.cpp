#include <X11/Xlib.h>
#include "x11ScreenShotSystem.h"


Window x11ScreenShotSystem::getActiveWindow(Display *display, Window root)
{
    Atom actual_type;
    int actual_format;
    unsigned long nitems, bytes_after;
    unsigned char *data = NULL;
    Window active_window = 0;

    // Получение атома _NET_ACTIVE_WINDOW
    Atom net_active_window = XInternAtom(display, "_NET_ACTIVE_WINDOW", False);

    // Запрос свойства активного окна из корневого окна
    XGetWindowProperty(
        display,
        root_win,
        net_active_window,
        0, 1, // Смещение и количество элементов
        False,
        AnyPropertyType,
        &actual_type, &actual_format, &nitems, &bytes_after, &data
    );

    if (data && nitems > 0) {
        active_window = *((Window *)data);
    }

    if (data)
        XFree(data);

    return active_window;
}

