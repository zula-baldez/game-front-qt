#include "player.h"
Player::Player(int id, QString name) : _id(id), _name(name) {
//    _cards.push_back(QVariant::fromValue( Card()));
}
int Player::getId() const {
    return _id;
}
QString Player::getName() const {
    return _name;
}
QVariantList Player::getCards() const {
    return _cards;
}
void Player::addCard(Card& card) {
    _cards.removeAll(QVariant::fromValue(card));
    _cards.append(QVariant::fromValue(card));
}
void Player::removeCard(Card& card) {
    _cards.removeAll(QVariant::fromValue(card));
}
