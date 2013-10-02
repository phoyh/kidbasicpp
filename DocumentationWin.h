/** Copyright (C) 2010, J.M.Reneau.
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



#if QT_VERSION >= 0x05000000
	#include <QtWidgets/QWidget>
	#include <QtWidgets/QDialog>
	#include <QtWidgets/QVBoxLayout>
	#include <QtWidgets/QToolBar>
	#include <QtWidgets/QTextBrowser>
#else
	#include <QWidget>
	#include <QDialog>
	#include <QVBoxLayout>
	#include <QToolBar>
	#include <QTextBrowser>
#endif

#ifndef DOCUMENTATIONWINH

#define DOCUMENTATIONWINH

class DocumentationWin : public QDialog
{
  Q_OBJECT
  public:
	DocumentationWin(QWidget * parent);
	void resizeEvent(QResizeEvent *e);
	void closeEvent(QCloseEvent *);
	void go(QString);

  public slots:

  private:
	QVBoxLayout* layout;
	QToolBar* toolbar;
	QTextBrowser* docs;
	QString indexfile;
	QString localecode;
};

#endif

