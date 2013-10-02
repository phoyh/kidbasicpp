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


#ifndef __BASICGRAPH_H
#define __BASICGRAPH_H

#include <stdio.h>

#include <QPainter>
#include <QKeyEvent>
#if QT_VERSION >= 0x05000000
	#include <QtWidgets/QWidget>
#else
	#include <QWidget>
#endif


#include "ViewWidgetIFace.h"
#include "BasicOutput.h"

#define GSIZE_INITIAL_WIDTH   300
#define GSIZE_INITIAL_HEIGHT   300

class BasicGraph : public QWidget, public ViewWidgetIFace
{
  Q_OBJECT
 public:
  BasicGraph();
  QImage *image;
  bool initActions(QMenu *, ToolBar *);
  // used to store current location of mouse
  // default value of -1 when no mouse recorded over graphic output
  int mouseX;
  int mouseY;
  int mouseB;
  // used to store location of last mouse click
  // default value of -1 when no click recorded
  int clickX;
  int clickY;
  int clickB;
  bool isVisibleGridLines();

 
 public slots:
  void resize(int, int);
  void slotGridLines(bool);
  void slotCopy();
  void slotPrint();
 
 protected:
  void paintEvent(QPaintEvent *);
  void keyPressEvent(QKeyEvent *);
  void mousePressEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  
 private:
  uchar *imagedata;
  unsigned int gwidth;
  unsigned int gheight;
  unsigned int gtop;	// position of image in basicgraph widget
  unsigned int gleft;
  bool gridlines;		// show the grid lines or not

};


#endif
