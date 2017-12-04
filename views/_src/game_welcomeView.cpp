#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_welcomeView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_welcomeView() : TActionView() { }
  QString toString();
};

QString game_welcomeView::toString()
{
  responsebody.reserve(154);
  responsebody += QLatin1String("<div class=\"content\">\n    Knight Rider V II\n    <a href=\"http://localhost:8800/Game/start\">Play</a>\n\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_welcomeView)

#include "game_welcomeView.moc"
