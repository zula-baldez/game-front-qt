#include "card.h"

Card::Card(int strenght, QString suit, int id, QString imgUrl)
    : _strenght(strenght), _suit(suit), _id(id), _imgUrl(imgUrl) {
}
int Card::getStrenght() {
   return _strenght;
}
QString Card::getSuit() {
    return _suit;
}
int Card::getId(){
    return _id;

}
QString Card::getImgUrl() {
    return _imgUrl;
}
