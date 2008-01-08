#ifndef PLEXY_DESKTOP_VIEW_H
#define PLEXY_DESKTOP_VIEW_H

#include <QtCore>
#include <QtGui>
#include <plexy.h>


namespace
{

class VISIBLE_SYM  DesktopView : public QGraphicsView
{
    Q_OBJECT
    public:
        DesktopView ( QGraphicsScene * scene, QWidget * parent = 0 );
        virtual ~DesktopView();

        void addWallpaper(const QString& path);

        void addRender(QGraphicsScene * scene);

        void addDesktopWidget(QWidget * widget);

        void addDesktopItem (QGraphicsItem * item);

    private:
            class Private;
            Private * const d ;

};


} // namespace #ifndef
#endif