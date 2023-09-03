#include "vk_oauth_handler.h"
#include <QDesktopServices>

VkOauthHandler::VkOauthHandler()
{

}


void VkOauthHandler::loginRequest() {
      QDesktopServices::openUrl(QUrl("http://172.26.64.1:8082/oauth2/authorization/vk"));
}
