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
 **  You should have received a copy of the GNU General Public License
 **  along with this program; if not, write to the Free Software
 **  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 **/
 
 
#if QT_VERSION >= 0x05000000
	#include <QtWidgets/QDockWidget>
#else
	#include <QDockWidget>
#endif
 
class DockWidget : public QDockWidget
{
	Q_OBJECT
	
public:
	DockWidget( const QString & title, QWidget * parent = 0, Qt::WindowFlags flags = 0 );
	DockWidget( QWidget * parent = 0, Qt::WindowFlags flags = 0 );

	void setWidget( QWidget * vpWidget );

private:
	QWidget * m_pWidget;
};
