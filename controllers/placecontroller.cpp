#include "placecontroller.h"
#include "place.h"


void PlaceController::index()
{
    auto placeList = Place::getAll();
    texport(placeList);
    render();
}

void PlaceController::show(const QString &id)
{
    auto place = Place::get(id.toInt());
    texport(place);
    render();
}

void PlaceController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto place = httpRequest().formItems("place");
        auto model = Place::create(place);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(place);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void PlaceController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Place::get(id.toInt());
        if (!model.isNull()) {
            session().insert("place_lockRevision", model.lockRevision());
            auto place = model.toVariantMap();
            texport(place);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("place_lockRevision").toInt();
        auto model = Place::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto place = httpRequest().formItems("place");
        model.setProperties(place);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(place);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void PlaceController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto place = Place::get(id.toInt());
    place.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(PlaceController)
