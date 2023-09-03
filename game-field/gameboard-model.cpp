#include "gameboard-model.h"
#include <QDebug>
#include <math.h>

GameBoard::GameBoard(QObject *parent, size_t players_num) : m_players_num(players_num)
{

//    for(int i= 1; i<=players_num; i++) {
//        m_raw_board.append(QVariant::fromValue(Player(123, "ew")));
//    }
}



QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    qDebug() << role;
    if(!index.isValid()) {
        return {};
    }
    const auto index_row {static_cast<int>(index.row())};

    switch(role) {
        case Qt::DisplayRole: {
            if (!isPositionValid(index_row)) {
                qDebug() <<"^(";
                return {};
            }
            return QVariant(static_cast<int>(index_row));
        }
        case idRole: {
            return QVariant(m_raw_board[index_row].value<Player>().getId());
        }
        case nameRole: {
            return QVariant(m_raw_board[index_row].value<Player>().getName());

       }
        case cardsRole: {
            return QVariant(m_raw_board[index_row].value<Player>().getCards());

       }
    }
    qDebug() <<"^(";
    return QVariant{};
}
bool GameBoard::isPositionValid(const size_t position) const
{
    return position < m_raw_board.size();
}
int GameBoard::rowCount(const QModelIndex &) const
{
    return static_cast<int>(m_raw_board.size());
}
QHash<int,QByteArray> GameBoard::roleNames() const {
    auto result = QAbstractListModel::roleNames();
    result[nameRole] = "name";
    result[idRole] = "id";
    result[cardsRole] = "cards";
    return result;
}

bool GameBoard::move (int index) {
    return true;
}




void GameBoard::addPlayer(Player player) {
    beginResetModel();
    bool changed = false;

    if(!idToIndex.count(player.getId())) {
        changed = true;
        idToIndex[player.getId()] = m_raw_board.size();
        m_raw_board.append(QVariant::fromValue(player));
    }

    endResetModel();
    if(changed) {
        int index = m_raw_board.size() - 1;
        emit dataChanged(createIndex(index, 0), createIndex(index, 0));
    }
}

void GameBoard::removeCardFromPlayer(Card card, int playerId) {
    beginResetModel();

    if(idToIndex.count(playerId)) {

        Player player = m_raw_board[idToIndex[playerId]].value<Player>();
        player.removeCard(card);
        m_raw_board[idToIndex[playerId]].setValue(QVariant::fromValue(player));

    }
    endResetModel();
    emit dataChanged(createIndex(idToIndex[playerId], 0), createIndex(idToIndex[playerId], 0));

}

void GameBoard::addCardToPlayer(Card card, int playerId) {
    beginResetModel();
    qDebug()<<m_raw_board[idToIndex[playerId]].value<Player>().getCards().size();
    if(idToIndex.count(playerId)) {
        qDebug()<<"adding";
        Player player = m_raw_board[idToIndex[playerId]].value<Player>();
        player.addCard(card);
        m_raw_board[idToIndex[playerId]].setValue(QVariant::fromValue(player));

    }
    qDebug()<<m_raw_board[idToIndex[playerId]].value<Player>().getCards().size();

    endResetModel();
    emit dataChanged(createIndex(idToIndex[playerId], 0), createIndex(idToIndex[playerId], 0));

}



