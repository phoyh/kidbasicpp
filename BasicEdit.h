/** Copyright (C) 2006, Ian Paul Larsen.
 **
 **  This program is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 2 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License along
 **  with this program; if not, write to the Free Software Foundation, Inc.,
 **  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 **/


#ifndef __BASICEDIT_H
#define __BASICEDIT_H


#if QT_VERSION >= 0x05000000
    #include <QtWidgets/QApplication>
    #include <QtWidgets/QPlainTextEdit>
    #include <QtWidgets/QMainWindow>
#else
    #include <QApplication>
    #include <QPlainTextEdit>
    #include <QMainWindow>
#endif
#include <QKeyEvent>

#include "ViewWidgetIFace.h"

class BasicEdit : public QPlainTextEdit, public ViewWidgetIFace
{
  Q_OBJECT
 public:
  BasicEdit();
  void loadFile(QString);
  void findString(QString, bool, bool);
  void replaceString(QString, QString, bool, bool, bool);
  bool codeChanged;
  QString getCurrentWord();
  void lineNumberAreaPaintEvent(QPaintEvent *event);
  int lineNumberAreaWidth();

 public slots:
  void newProgram();
  void saveProgram();
  void saveAsProgram();
  void loadProgram();
  void cursorMove();
  void goToLine(int);
  void highlightLine(int);
  void slotPrint();
  void beautifyProgram();
  void loadRecent0();
  void loadRecent1();
  void loadRecent2();
  void loadRecent3();
  void loadRecent4();
  void loadRecent5();
  void loadRecent6();
  void loadRecent7();
  void loadRecent8();

signals:
	void changeStatusBar(QString);
	void changeWindowTitle(QString);
 
 protected:
  void keyPressEvent(QKeyEvent *);
  void resizeEvent(QResizeEvent *event);

 private:
  QMainWindow *mainwin;
  int currentMaxLine;
  int currentLine;
  int startPos;
  int linePos;
  QString filename;
//  void changeFontSize(unsigned int);
  void addFileToRecentList(QString);
  void loadRecent(int);
  QWidget *lineNumberArea;

private slots:
  void updateLineNumberAreaWidth(int newBlockCount);
  void updateLineNumberArea(const QRect &, int);
  void highlightCurrentLine();

   
};


#endif
