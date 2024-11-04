//群员表：对应group_member表

#ifndef GROUPMEMBERLZY_H
#define GROUPMEMBERLZY_H

#include <QObject>

enum class MemberRole { OWNER, ADMIN, MEMBER };

class GroupLzy;
class UserLzy;

class GroupMemberLzy : public QObject {
    Q_OBJECT

private:
    GroupLzy* group; // 聚合关系
    UserLzy* user;
    MemberRole role;

public:
    GroupMemberLzy(GroupLzy* grp, UserLzy* usr, MemberRole r, QObject *parent = nullptr)
        : QObject(parent), group(grp), user(usr), role(r) {}

    // Getters
    GroupLzy* getGroup() const { return group; }
    UserLzy* getUser() const { return user; }
    MemberRole getRole() const { return role; }

    // Setters
    void setGroup(GroupLzy* grp) { group = grp; }
    void setUser(UserLzy* usr) { user = usr; }
    void setRole(MemberRole r) { role = r; }
};

#endif // GROUPMEMBERLZY_H
