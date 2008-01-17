/***************************************************************************
 *   Copyright (C) 2008 by Lahiru Lakmal Priyadarshana                     *
 *   llahiru@gmail.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include <plexy.h>
#include "friendswidget.h"
#include "frienditem.h"
#include <QPixmap>
#include <QPaintEvent>
#include <QBitmap>

namespace PlexyDesk
{

FriendsWidget::FriendsWidget (const QRectF &rect, QWidget *widget):
DesktopWidget(rect,widget)
{
  shade == 0;

  setPath("/usr/share/plexy/skins/default/friendswidget/");
  setDockImage(QPixmap(prefix + "icon.png"));
  drawFriendsWidget();
}

void FriendsWidget::setPath(QString str)
{
  prefix  = str+"/";
}

void 
FriendsWidget::drawFriendsWidget()
{

   FriendItem* fitem = new FriendItem(this);
   fitem->setPos(18,20);

  _main_bg = QImage (prefix + "default.png");
}

FriendsWidget::~FriendsWidget ()
{

}

void
FriendsWidget::paintExtFace(QPainter *p, const QStyleOptionGraphicsItem * e , QWidget *)
{

  QRectF r  = e->exposedRect;

  p->setCompositionMode(QPainter::CompositionMode_Source);
  p->fillRect(rect(), Qt::transparent);

  p->drawImage (QRect(0,0,_main_bg.width(),_main_bg.height()),_main_bg);
  p->setCompositionMode(QPainter::CompositionMode_SourceOver);
  p->setBackgroundMode(Qt::TransparentMode);
  p->save ();
  p->setRenderHint (QPainter::SmoothPixmapTransform);
  if (shade == 0)
    {
      p->drawPixmap (_main_bg.rect (), QPixmap ().fromImage(_main_bg));
      shade = 1;
    }
  p->restore ();

  p->save ();

  p->restore ();

  p->setRenderHints(QPainter::SmoothPixmapTransform |QPainter::Antialiasing |QPainter::HighQualityAntialiasing);

  p->setPen(QColor(255,255,255));
  p->setFont(QFont("Bitstream Charter",10,QFont::Bold));
  p->drawText(QRect(70,130,64,64), Qt::AlignCenter ,"Friends" );
}


void
FriendsWidget::paintExtDockFace(QPainter *p, const QStyleOptionGraphicsItem * e , QWidget *)
{
 	/*p->setRenderHints(QPainter::SmoothPixmapTransform |QPainter::Antialiasing |QPainter::HighQualityAntialiasing);
		
	p->setPen(QColor(255,255,255));
	p->setFont(QFont("Bitstream Charter",15));
	p->drawText(QRect(8,5,64,64), Qt::AlignCenter ,"Cpu\n"+QString("%1").arg(percen)+"%" );*/
}

} // namespace PlexyDesk
#include "friendswidget.moc"