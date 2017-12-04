#include <QtCore>
#include <TreeFrogView>
#include "item.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT item_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  item_showView() : TActionView() { }
  QString toString();
};

QString item_showView::toString()
{
  responsebody.reserve(1685);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Item, item);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Item</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Space</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.space());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Url</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.url());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(item.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", item.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(item_showView)

#include "item_showView.moc"
