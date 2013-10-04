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


#ifndef __RUNCONTROLLER_H
#define __RUNCONTROLLER_H
 
#if QT_VERSION >= 0x05000000
	#include <QtWidgets/QTextEdit>
	#include <QtWidgets/QPushButton>
	#include <QtWidgets/QStatusBar>
#else
	#include <QTextEdit>
	#include <QPushButton>
	#include <QStatusBar>
#endif

#include "BasicEdit.h"
#include "BasicOutput.h"
#include "BasicGraph.h"
#include "DocumentationWin.h"
#include "Interpreter.h"
#include "ReplaceWin.h"

using namespace std;

class RunController : public QObject
{
  Q_OBJECT
 public:
  RunController();
  ~RunController();
  ReplaceWin *replacewin;
  DocumentationWin *docwin;

 signals:
  void debugStarted();
  void runStarted();
  void runHalted();
  void runPaused();
  void runResumed();
 
 public slots:
  void speakWords(QString);
  void executeSystem(QString);
  void playWAV(int,QString,int);
  void stopWAV(int);
  void waitWAV(int);
  void inputEntered(QString text);
  void outputReady(QString text);
  void outputClear();
  void goutputReady();
  void mainWindowsResize(int, int, int);
  void startDebug();
  void startRun();
  void stopRun();
  void pauseResume();
  void saveByteCode();
  void stepThrough();
  void showDocumentation();
  void showContextDocumentation();
  void showOnlineDocumentation();
  void showOnlineContextDocumentation();
  void showPreferences();
  void showReplace();
  void showFind();
  void findAgain();
  void mainWindowsVisible(int, bool);
  void dialogAlert(QString);
  void dialogConfirm(QString, int);
  void dialogPrompt(QString, QString);
  void dialogFontSelect();

  void exitOnEndMode();

 private:
  Interpreter *i;
  bool paused;
  int maxChannel;
  map<string,Mix_Chunk*> soundFilePathToChunk;
  run_status oldStatus;
  QString bytefilename;
};



#endif
