#ifndef CTRL_OBJECT_H
#define CTRL_OBJECT_H

#include "dev_serialnum.h"

class Ctrl_Object : public Dev_Object
{
    Q_OBJECT
public:
    explicit Ctrl_Object(QObject *parent = nullptr);

    virtual bool setCurTh(int i)=0;
    virtual bool setVolTh(int i)=0;
    virtual bool funClearEle(){return true;}
};

#endif // CTRL_OBJECT_H
