#include "roommodel.h"
using json = nlohmann::json;


bool inline isValidIndex(int i, QStringList& list) {
    return i < list.size();
}


RoomModel::RoomModel() {

}
void RoomModel::addRoomToModel(Room room) {


    int index;
    beginResetModel();

    bool newRoom = true;

    for(int i = 0; i < _model.size(); i++) {
        if(_model[i].getId() == room.getId()) {
            _model[i] = room;
            newRoom = false;
            index = i;
            break;
        }
    }

    if(newRoom) {
        _model.push_back(room);
        index = _model.size()-1;
    }
    QVector<int> qvector = { capacityRole, countRole, nameRole, idRole, hostIdRole};

    endResetModel();

    emit dataChanged(createIndex(index, 0), createIndex(index, 0));

}
void RoomModel::setModel(std::vector<Room> rooms) {
    _model = rooms;
}

QHash<int,QByteArray> RoomModel::roleNames() const {
    auto result = QAbstractListModel::roleNames();
    result[capacityRole] = "capacity";
    result[nameRole] = "name";
    result[idRole] = "id";
    result[hostIdRole] = "hostId";
    result[countRole] = "count";
    return result;
}
int RoomModel::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(_model.size());
}

QVariant RoomModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) {
        return {};
    }
    const auto index_row {static_cast<size_t>(index.row())};
    if (!isPositionValid(index_row)) {
        return {};
    }
    //qDebug() << _model.at(roomId).getCapacity();
    Room room = _model[index_row];

    switch(role) {

        case capacityRole:
        {
           return QVariant(static_cast<int>(room.getCapacity()));
        }
        case nameRole: {
           return QVariant(static_cast<QString>(room.getName()));
        }
        case idRole: {
           return QVariant(static_cast<int>(room.getId()));
        }
        case hostIdRole: {
           return QVariant(static_cast<int>(room.getHostId()));
        }
        case countRole: {
           return QVariant(static_cast<int>(room.getCount()));
        }
        case Qt::DisplayRole: {
            return QVariant::fromValue(room);
        }
    }
    return QVariant{};
}
bool RoomModel::isPositionValid(const size_t position) const
{
    return position < _model.size();
}


RoomModel::~RoomModel() {
    qDebug() << "room model terminated!";
}
