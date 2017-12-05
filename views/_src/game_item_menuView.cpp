#include <QtCore>
#include <TreeFrogView>
#include "item.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT game_item_menuView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  game_item_menuView() : TActionView() { }
  QString toString();
};

QString game_item_menuView::toString()
{
  responsebody.reserve(1005);
    responsebody += QLatin1String("\n\n\n");
  int item_length = Item::count();
  QList<Item> items = Item::getAll();
  responsebody += QLatin1String("\n\n\n    <tr>\n        ");
  for(int i = 0; i < item_length; i++) {
  responsebody += QLatin1String("\n            ");
  if( items[i].space() == 1) {
  responsebody += QLatin1String("\n                <a href=\"http://localhost:8800/Game/use_item?key=");
  responsebody += THttpUtility::htmlEscape(items[i].name());
  responsebody += QLatin1String("\"><img src=\"");
  responsebody += THttpUtility::htmlEscape(items[i].url());
  responsebody += QLatin1String("\" alt=\"\" ></a>\n            ");
  };
  responsebody += QLatin1String("\n        ");
  };
  responsebody += QLatin1String("\n\n\n\n\n    </tr>\n    <tr>\n      <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n          <a href=\"#\">....Select item</a><br>\n          <a href=\"http://localhost:8800/Game/loop\">> Return</a><br>\n\n\n        </div></td>\n    </tr>\n");

  return responsebody;
}

T_DEFINE_VIEW(game_item_menuView)

#include "game_item_menuView.moc"
