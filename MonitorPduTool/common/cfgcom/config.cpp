/*
 * 配置文件公共基类
 *
 *  Created on: 2018年1月1日
 *      Author: Lzy
 */
#include "config.h"

Cfg::Cfg()
{
    mCfg = CfgCom::bulid();
    item = new sCfgItem();

    initCnt();
    initErrData();
    initCfgDev();
}

Cfg *Cfg::bulid()
{
    static Cfg* sington = nullptr;
    if(sington == nullptr)
        sington = new Cfg();
    return sington;
}


int Cfg::initAddr()
{
    return read("addr", 1,"Sys").toInt();
}

void Cfg::setAddr(int addr)
{
    write("addr", addr, "Sys");
}

void Cfg::initErrData()
{
    item->err.volErr = read("vol", 1,"Err").toInt();
    item->err.curErr = read("cur", 1,"Err").toInt();
    item->err.powErr = read("pow", 15,"Err").toInt();
}

void Cfg::writeErrData()
{
    write("vol", item->err.volErr, "Err");
    write("cur", item->err.curErr, "Err");
    write("pow", item->err.powErr, "Err");
}

void Cfg::initCnt()
{
    item->cnt.all = read("all", 0, "Count").toInt();
    item->cnt.ok = read("ok", 0, "Count").toInt();
    item->cnt.err = read("err", 0, "Count").toInt();
}

void Cfg::writeCnt()
{
    write("all", item->cnt.all, "Count");
    write("ok", item->cnt.ok, "Count");
    write("err", item->cnt.err, "Count");
}



void Cfg::initCfgDev()
{
    item->user = read("user", "", "User").toString();
    item->cTh.ip_addr = read("ip_addr", "192.168.1.163").toString();

    item->cTh.type = read("cth_type", 1).toInt();
    item->cTh.vol_min = read("vol_min", 80).toInt();
    item->cTh.vol_max = read("vol_max", 276).toInt();
    item->cTh.cur_min = read("cur_min", 0).toInt();
    item->cTh.cur_max = read("cur_max", 320).toInt();
    item->cTh.enModify = read("en_modify", 0).toInt();
    item->cTh.si_mod = read("si_mod", 0).toInt();
    item->cTh.ip_version = read("ip_version", 1).toInt();
    item->cTh.ip_log = read("log_en", 0).toInt();
}

void Cfg::writeCfgDev()
{
    write("user", item->user, "User");
    write("ip_addr", item->cTh.ip_addr);

    write("cth_type", item->cTh.type);
    write("vol_min", item->cTh.vol_min);
    write("vol_max", item->cTh.vol_max);
    write("cur_min", item->cTh.cur_min);
    write("cur_max", item->cTh.cur_max);
    write("en_modify", item->cTh.enModify);
    write("ip_version", item->cTh.ip_version);
    write("log_en", item->cTh.ip_log);
}


/**
 * @brief 获取串口名称
 * @return 串口名
 */
QString Cfg::getSerialName(const QString &key)
{
    return mCfg->read(key, "", "Serial").toString();
}

/**
 * @brief 设置串口名
 * @param name
 */
void Cfg::setSerialName(const QString &key, const QString &v)
{
    mCfg->write(key, v, "Serial");
}

QString Cfg::getSerialBr(const QString &com)
{
    QString key = QString("BR_%1").arg(com);
    return mCfg->read(key, "", "Serial").toString();
}

void Cfg::setSerialBr(const QString &com, const QString &br)
{
    QString key = QString("BR_%1").arg(com);
    mCfg->write(key, br, "Serial");
}


/**
 * @brief 根据名称获取配置文件数值
 * @return 对应的配置文件数值
 */
QVariant Cfg::read(const QString &key, const QVariant &v, const QString &g)
{
    return mCfg->read(key, v, g);
}

/**
 * @brief 设置对应名称的配置文件数值
 * @param value
 * @param name
 */
void Cfg::write(const QString &key, const QVariant& v, const QString &g)
{
    mCfg->write(key, v, g);
}

/**
 * @brief 获取当前用户名称
 * @return 用户名
 */
QString Cfg::getLoginName()
{
    return mCfg->read("name", "admin", "Login").toString();
}

/**
 * @brief 设置当前用户名
 * @param name
 */
void Cfg::setLoginName(const QString &name)
{
    mCfg->write("name", name, "Login");
}
