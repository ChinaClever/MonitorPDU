#ifndef DEV_SOURCETHREAD_H
#define DEV_SOURCETHREAD_H

#include "dev_iprtu.h"

class Dev_Source : public Dev_SiRtu
{
    Q_OBJECT
    explicit Dev_Source(QObject *parent = nullptr);
public:
    static Dev_Source *bulid(QObject *parent = nullptr);
    bool read();

protected:
    void init();

protected slots:
    void initFunSlot();

};

#endif // DEV_SOURCETHREAD_H
