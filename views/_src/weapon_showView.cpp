#include <QtCore>
#include <TreeFrogView>
#include "weapon.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT weapon_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  weapon_showView() : TActionView() { }
  QString toString();
};

QString weapon_showView::toString()
{
  responsebody.reserve(2097);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Weapon, weapon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Weapon</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Space</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.space());
  responsebody += QLatin1String("</dd><br />\n<dt>Attack</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.attack());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Equipped</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.equipped());
  responsebody += QLatin1String("</dd><br />\n<dt>Main</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.main());
  responsebody += QLatin1String("</dd><br />\n<dt>Url</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.url());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(weapon.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", weapon.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(weapon_showView)

#include "weapon_showView.moc"
