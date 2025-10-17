#ifndef IFLYABLE_H
#define IFLYABLE_H

struct IFlyable {
    virtual void fly(int minutes = 5) = 0;
    virtual ~IFlyable() {}
};

#endif // IFLYABLE_H
