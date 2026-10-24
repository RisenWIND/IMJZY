#ifndef SYSTEMUIJZY_H
#define SYSTEMUIJZY_H

#include <string>
#include <vector>
#include "AccountManagerJZY.h"
#include "BindingManagerJZY.h"
#include "FileManagerJZY.h"
#include "FriendManagerJZY.h"
#include "GroupManagerJZY.h"
#include "UserInfoJZY.h"

class SystemUIJZY {
public:
    SystemUIJZY();
    ~SystemUIJZY();

    void run();

private:
    std::string getCurrentTimeString() const;
    void loadData();
    void saveData();

    std::string getPlatformNameFromChoice(int choice) const;
    bool userHasPlatform(const std::string& platformName) const;
    void openPlatform(const std::string& platformName);

    void showMainMenu();
    void showPlatformMenu();
    void registerUser();
    void loginUser();
    void handlePlatformAction(const std::string& platformName);

    void showUserProfileMenu();
    void showCurrentUserInfo();
    void editCurrentUserInfo();

    void showFriendMenu();
    void showFriendList();
    void addFriendByID();
    void addFriendByRecommend();
    void queryFriend();
    void editFriend();

    void showGroupMenu();
    void showGroupList();
    void joinGroupByID();
    void quitGroup();
    void showGroupMembers();
    void showGroupDynamicMode();

    void showRecommendedFriends(const std::string& platformName);
    void showBindingMenu();

    AccountManagerJZY accountManager;
    BindingManagerJZY bindingManager;
    FriendManagerJZY friendManager;
    GroupManagerJZY groupManager;
    FileManagerJZY fileManager;

    std::vector<UserInfoJZY> users;
    std::vector<FriendInfoJZY> friends;
    std::vector<GroupInfoJZY> groups;

    UserInfoJZY currentUser;
    bool loggedIn;
};

#endif
