#include <QtCore>
#include <TreeFrogView>
#include "game.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT game_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_showView() : TActionView() { }
  QString toString();
};

QString game_showView::toString()
{
  responsebody.reserve(1313);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Game, game);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Game</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(game.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(game.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(game.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(game.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", game.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_showView)

#include "game_showView.moc"
