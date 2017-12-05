#include <QtCore>
#include <TreeFrogView>
#include "place.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT place_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  place_showView() : TActionView() { }
  QString toString();
};

QString place_showView::toString()
{
  responsebody.reserve(1696);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Place, place);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Place</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Space</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.space());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Url</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.url());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(place.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", place.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(place_showView)

#include "place_showView.moc"
