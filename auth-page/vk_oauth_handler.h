#ifndef VKOAUTHHANDLER_H

#define VKOAUTHHANDLER_H

#include "auth_handler.h"
class VkOauthHandler : public AuthHandler
{


public:
    Q_INVOKABLE void loginRequest() override;
public:
    VkOauthHandler();
    ~VkOauthHandler() override = default;
};

#endif // VKOAUTHHANDLER_H
