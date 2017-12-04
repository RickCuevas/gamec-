#include "itemcontroller.h"
#include "item.h"


void ItemController::index()
{
    auto itemList = Item::getAll();
    texport(itemList);
    render();
}

void ItemController::show(const QString &id)
{
    auto item = Item::get(id.toInt());
    texport(item);
    render();
}

void ItemController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto item = httpRequest().formItems("item");
        auto model = Item::create(item);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(item);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ItemController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Item::get(id.toInt());
        if (!model.isNull()) {
            session().insert("item_lockRevision", model.lockRevision());
            auto item = model.toVariantMap();
            texport(item);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("item_lockRevision").toInt();
        auto model = Item::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto item = httpRequest().formItems("item");
        model.setProperties(item);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(item);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ItemController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto item = Item::get(id.toInt());
    item.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ItemController)
