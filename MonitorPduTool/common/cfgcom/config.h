#ifndef CONFIGBASH
#define CONFIGBASH
#include "cfgcom.h"
#include "serialstatuswid.h"

enum eDevTypes {
    PDU=0,
    ZPDU,
    MPDU,
    RPDU,     // RPDU 执行板
    RPDU_Mc, // RPDU 主控
    SI_PDU,
    IP_PDU,
    BM_PDU,

    AC = 1, // 交流
    DC,     // 直流

    Sum=0,
    Transformer, // 互感器
    Mn    // 锰铜
};

struct sCfgDev {
    uchar type; // 0 不设置， 1 32安  2 16安， 3 63安  4 自定义
    uchar enModify;
    ushort vol_min;
    ushort vol_max;
    ushort cur_min;
    ushort cur_max;
    uchar si_mod;

    QString ip_addr;
    uchar ip_version;
    uchar ip_log;
};


/**
 * RTU传输统计结构体
 */
struct sCount
{
    sCount() {all=ok=err =0;}

    int all;
    int ok;
    int err;
};

struct sErrRange
{
    ushort volErr;
    ushort curErr;
    ushort powErr;
};

struct sSerial
{
    sSerial() {source=ser1=ser2=nullptr;}
    SerialPort *source; // 标准源
    SerialPort *ser1; // 串口对象
    SerialPort *ser2; // 串口对象
};

struct sCfgItem
{
    sErrRange err; // 电流误差
    sCfgDev cTh;

    sCount cnt;
    int logCount;

    uchar pcNum;
    QString user; // 客户名称
    sSerial coms;
};


class Cfg
{
    Cfg();
public:
    static Cfg *bulid();

    sCfgItem *item;

    QString getSerialBr(const QString &com);
    QString getSerialName(const QString &key);
    void setSerialBr(const QString &com, const QString &br);
    void setSerialName(const QString &key, const QString &v);

    QString getLoginName();
    void setLoginName(const QString &name);

    int initAddr();
    void writeCnt();
    void writeErrData();
    void writeCfgDev();
    void setAddr(int addr);

    void write(const QString &key, const QVariant& v, const QString &g="Cfg");
    QVariant read(const QString &key, const QVariant &v = QVariant(), const QString &g="Cfg");

protected:
    void initCnt();
    void initErrData();
    void initCfgDev();

private:
    CfgCom *mCfg;
};

#endif // CONFIGBASH
