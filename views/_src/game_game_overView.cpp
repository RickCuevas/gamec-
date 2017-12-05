#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT game_game_overView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_game_overView() : TActionView() { }
  QString toString();
};

QString game_game_overView::toString()
{
  responsebody.reserve(176);
  responsebody += QLatin1String("<div class=\"content\">\n    GAME OVER..\n    \n    <a href=\"http://localhost:8800/Game/randomize_things_to_map\">New Game</a>\n\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_game_overView)

#include "game_game_overView.moc"
