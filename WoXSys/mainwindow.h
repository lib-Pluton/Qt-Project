#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QTcpSocket>
#include "chatterboxserver.h"
#include <QTimer>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = Q_NULLPTR);
  ~MainWindow();

protected:
 virtual void checkBorderDragging(QMouseEvent *event);
 virtual bool eventFilter(QObject *obj, QEvent *event);
public slots:
   void Slot1();
private slots:
    void readyRead();
    void connected();
    void on_UICloseButton_clicked();
    void on_UIMinButton_clicked();
    void on_UICheatsButton_clicked();
    void on_UINewsButton_clicked();
    void on_UIOnlineButton_clicked();
    void on_UIAccountButton_clicked();
    void on_UILoginButton_clicked();
    void on_UIXCheatsStart_clicked();
    void on_UIXCheatsTopic_clicked();
    void on_UIXCheatsAbout_clicked();
    void on_UIUserMessageIcon_clicked();
    void on_UIUserNotiIcon_clicked();
    void on_UILoginText4_clicked();
    void on_UILoginText5_clicked();
    void on_UILoginBackButton_clicked();
    void on_UILoginText6_clicked();

private:
 bool leftBorderHit(const QPoint &pos);
 bool rightBorderHit(const QPoint &pos);
 bool topBorderHit(const QPoint &pos);
 bool bottomBorderHit(const QPoint &pos);
 void styleWindow(bool bActive, bool bNoState);
 void SelectTab(int key);
 QString ReadLine(int count);
 QString ReadLine2(int count);
 private:
  Ui::MainWindow *ui;
  QRect m_StartGeometry;
  const quint8 CONST_DRAG_BORDER_SIZE = 15;
  bool m_bMousePressed;
  bool m_bDragTop;
  bool m_bDragLeft;
  bool m_bDragRight;
  bool m_bDragBottom;
  void AddCheats(QString game, QString server, QString state, QString cheatname, QString version, QString last, QString process, QString type,QString logolink,QString link, QString topic, QString about, QString exe, QString premium);
  void ReadWXPG(QString data);
  void Start(QString ProcessName, QString FileUrl, QString InjType, QString FileType);
  QTreeWidgetItem * item1;
  QTreeWidgetItem * item2;
  QTreeWidgetItem * item3;
  QTcpSocket *socket;
  ChatterBoxServer *serverx;
  QProcess *process;
  QTimer *timer;
};

#endif
