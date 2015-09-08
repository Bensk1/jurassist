#include "ClipboardInterface.h"
#import <iostream>
#import <Cocoa/Cocoa.h>

ClipboardInterface::ClipboardInterface()
{
    pasteboard = [NSPasteboard generalPasteboard];
}

size_t ClipboardInterface::getLastChangeCount() {
    return static_cast<NSPasteboard*>(pasteboard).changeCount;
}

