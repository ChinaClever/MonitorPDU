#ifndef HOME_ENVTABWID_H
#define HOME_ENVTABWID_H

#include "home_thresholdtabwid.h"

class Home_EnvTabWid : public ComTableWid
{
    Q_OBJECT
public:
    explicit Home_EnvTabWid(QWidget *parent = nullptr);

signals:

protected:
    void initWid();
    void setDataUnit(int id, sDataUnit &unit);
    void setHum(sDataUnit &unit);
    void appendItem();

protected slots:
    void timeoutDone();

private:
    sEnvData *mEnv;
};

#endif // HOME_ENVTABWID_H
