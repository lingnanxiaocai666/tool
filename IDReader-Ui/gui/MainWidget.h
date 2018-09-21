#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

/**
 * 主要逻辑与调用说明:
 *
 * 点击 “初始化” 按钮调用 loadRoomInformation() 加载考试的初始化信息，然后选择 “考期” “考点”，
 * 选择 “考场” 的时候调用 loadRoomEnrollment() 加载此考点学生的刷卡签到数据
 * 点击 “详情” 调用 xxx() 可视化显示此考点学生的刷卡签到数据
 * 点击 “开始读卡” 连接身份证读卡器，启动线程 ReadThread 循环的读取身份证信息
 * ReadThread 读取到身份证信息后发出信号 personReady()，然后调用 signIn() 发送学生身份证信息到服务器签到
 * 签到成功则 “已刷卡” 数加 1，“未刷卡” 数减 1
 *
 * 调用 showInfo() 显示信息到界面上
 * 信号槽连接放在 handleEvents() 里创建
 */
class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
