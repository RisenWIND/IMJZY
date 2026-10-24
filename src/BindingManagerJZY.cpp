#include "BindingManagerJZY.h"

BindingManagerJZY::BindingManagerJZY() = default;
BindingManagerJZY::~BindingManagerJZY() = default;

bool BindingManagerJZY::bindPlatform(UserInfoJZY& user, const std::string& platformName, bool createIfNotExists) {
    (void)createIfNotExists;

    if (platformName == "QQ") {
        user.setQQOpened(true);
        return true;
    }
    if (platformName == "WeChat" || platformName == "微信") {
        user.setWeChatOpened(true);
        return true;
    }
    if (platformName == "Weibo" || platformName == "微博") {
        user.setWeiboOpened(true);
        return true;
    }
    return false;
}

bool BindingManagerJZY::canBindToPlatform(const UserInfoJZY& user, const std::string& platformName) const {
    return !isPlatformOpened(user, platformName);
}

bool BindingManagerJZY::isPlatformOpened(const UserInfoJZY& user, const std::string& platformName) const {
    if (platformName == "QQ") return user.isQQOpened();
    if (platformName == "WeChat" || platformName == "微信") return user.isWeChatOpened();
    if (platformName == "Weibo" || platformName == "微博") return user.isWeiboOpened();
    return false;
}
