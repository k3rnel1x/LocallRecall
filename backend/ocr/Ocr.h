#ifndef OCR_H
#define OCR_H
#include <X11/Xlib.h>

class Ocr {
    void Init();
    char* getText(XImage ximage);
    void End();
};


#endif //OCR_H
