#ifndef FRANCO_H
#define FRANCO_H

#import <cstddef>

class ClipboardInterface
{
public:
    ClipboardInterface();

    size_t getLastChangeCount();
private:
    void* pasteboard;
};

#endif // FRANCO_H
