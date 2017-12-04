#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_startView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_startView() : TActionView() { }
  QString toString();
};

QString game_startView::toString()
{
  responsebody.reserve(170);
  tfetch(int, bar);
  responsebody += QLatin1String("\n<a href=\"#\"> ");
  responsebody += THttpUtility::htmlEscape(bar);
  responsebody += QLatin1String("</a><br>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_startView)

#include "game_startView.moc"
