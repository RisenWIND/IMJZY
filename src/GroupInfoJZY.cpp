#include "GroupInfoJZY.h"
#include <algorithm>
#include <iostream>

GroupInfoJZY::GroupInfoJZY() : groupID(""), groupName(""), platform(""), ownerID("") {}
GroupInfoJZY::~GroupInfoJZY() = default;

void GroupInfoJZY::setGroupID(const std::string& id) { groupID = id; }
std::string GroupInfoJZY::getGroupID() const { return groupID; }

void GroupInfoJZY::setGroupName(const std::string& name) { groupName = name; }
std::string GroupInfoJZY::getGroupName() const { return groupName; }

void GroupInfoJZY::setPlatform(const std::string& platformName) { platform = platformName; }
std::string GroupInfoJZY::getPlatform() const { return platform; }

void GroupInfoJZY::setOwnerID(const std::string& owner) { ownerID = owner; }
std::string GroupInfoJZY::getOwnerID() const { return ownerID; }

void GroupInfoJZY::addMember(const std::string& userID) {
    if (!hasMember(userID)) {
        members.push_back(userID);
    }
}

void GroupInfoJZY::removeMember(const std::string& userID) {
    auto it = std::remove(members.begin(), members.end(), userID);
    members.erase(it, members.end());
}

bool GroupInfoJZY::hasMember(const std::string& userID) const {
    return std::find(members.begin(), members.end(), userID) != members.end();
}

std::vector<std::string> GroupInfoJZY::getMembers() const { return members; }

void GroupInfoJZY::showInfo() const {
    std::cout << "群ID: " << groupID << "\n";
    std::cout << "群名: " << groupName << "\n";
    std::cout << "平台: " << platform << "\n";
    std::cout << "群主: " << ownerID << "\n";
    std::cout << "成员数: " << members.size() << "\n";
}
