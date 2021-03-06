#ifndef TEST_CORETHREAD_H
#define TEST_CORETHREAD_H

#include "test_errrange.h"

class Test_CoreThread : public Test_Object
{
    Q_OBJECT
public:
    explicit Test_CoreThread(QObject *parent = nullptr);

protected slots:
    void initFunSlot();

protected:
    void run();    
    void workDown();

    bool initDev();
    bool hubPort();
    bool volErrRange(int i);
    bool curErrRange(int i);
    bool powErrRange(int i);
    bool eleErrRange(int i);
    bool envErrRange();
    bool checkErrRange();
    bool oneLineCheck();

    bool volAlarmErr(int i);
    bool curAlarmErr(int i);
    bool checkAlarmErr();
    bool envAlarmErr();

    bool volAlarmWrite(int i);
    bool curAlarmWrite(int i);
    bool writeAlarmTh();

    bool factorySet();
    void workResult(bool);

private:
    Test_Logs *mLogs;
    Test_ErrRange *mErr;
    Test_DevRead *mRead;
    Test_DevCtrl *mCtrl;
    Test_NetWork *mNetWork;
};

#endif // TEST_CORETHREAD_H
