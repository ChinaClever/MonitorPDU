#include "serialstatuswid.h"
#include "ui_serialstatuswid.h"
//#include "ad_config.h"

SerialStatusWid::SerialStatusWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialStatusWid)
{
    ui->setupUi(this);
    mEnable = false;

    QGridLayout *gridLayout = new QGridLayout(parent);
    gridLayout->setContentsMargins(0, 10, 0, 0);
    gridLayout->addWidget(this);
}

SerialStatusWid::~SerialStatusWid()
{
    delete ui;
}


bool SerialStatusWid::checkSerial()
{
    SerialPort *serial = mSerialDlg->getSerialPort();
    bool ret = serial->isOpened();
    if(!ret) {
        ret = MsgBox::question(this, tr("请先打开串口!!"));
        if(ret) {
            on_comBtn_clicked();
        }
    }
    //mEnable = serial->isOpened();

    return ret;
}

void SerialStatusWid::on_comBtn_clicked()
{
    if(mEnable != true) {
        mSerialDlg->exec();
        updateSerialWid();
    } else {
        MsgBox::critical(this, tr("请先停止！！！"));
    }
}


/**
 * @brief 初始化串口
 * @return
 */
SerialPort *SerialStatusWid::initSerialPort(const QString &str)
{
    bool ret = false;
    ui->comBtn->setText(str);
    mSerialDlg = new SerialPortDlg(this);
    SerialPort *serial = getSerialPort();

    //////////===============
//    QString com = Ad_Config::bulid()->getSerialName(str);
//    if(!com.isEmpty())
//    {
//        ret = serial->isContains(com);
//        if(ret) {
//            QString br = Ad_Config::bulid()->getSerialBr(com);
//            if(!br.isEmpty()) {
//                qint32 baudRate = br.toInt();
//                ret = serial->open(com, baudRate);
//                mSerialDlg->updateBaudRate(baudRate);
//                updateSerialWid();
//            }
//        }
//    }

    return serial;
}



/**
 * @brief 更新串口窗口
 */
void SerialStatusWid::updateSerialWid()
{
    QPalette pe;
    SerialPort *serial = mSerialDlg->getSerialPort();
    QString str = serial->getSerialName();
    if(serial->isOpened()) {
        QString com = ui->comBtn->text();
        ////////////=============
//        Ad_Config::bulid()->setSerialName(str, com);
        str += tr(" 已打开");
        pe.setColor(QPalette::WindowText,Qt::black);
    } else {
        str += tr(" 未打开");
        pe.setColor(QPalette::WindowText,Qt::red);
    }

    ui->serialLab->setText(str);
    ui->serialLab->setPalette(pe);
}

