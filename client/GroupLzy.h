//群组类：用于管理群聊，对应group表

#ifndef GROUPLZY_H
#define GROUPLZY_H

#include <QObject>
#include <QList>
#include <QDateTime>

enum class GroupType { QQ, WECHAT };

class GroupMemberLzy;

class GroupLzy : public QObject {
    Q_OBJECT

private:
    int groupId;
    QString name;
    GroupType type;
    QList<GroupMemberLzy*> members; // 群员列表
    QDateTime createTime;
    int ownerId;

public:
    GroupLzy(int g_id, const GroupType& t, const QString& grp_name, int owner_id, QObject *parent = nullptr)
        : QObject(parent), groupId(g_id), name(grp_name), type(t), members(), createTime(QDateTime::currentDateTime()), ownerId(owner_id) {}


    void addMember(GroupMemberLzy* member) {
        members.append(member);
    }

    QList<GroupMemberLzy*> getMembers() const {
        return members;
    }

    // Getters
    int getGroupId() const { return groupId; }
    QString getName() const { return name; }
    GroupType getType() const { return type; }
    int getOwnerId() const { return ownerId; } // Fixed variable name
    QDateTime getCreateTime() const { return createTime; }

    // Setters
    void setGroupId(int g_id) { groupId = g_id; }
    void setName(const QString& grp_name) { name = grp_name; }
    void setType(GroupType grp_type) { type = grp_type; }
    void setOwnerId(int own_id) { ownerId = own_id; } // Fixed variable name
    void setCreateTime(const QDateTime& c_time) { createTime = c_time; } // Fixed variable name
};

#endif // GROUPLZY_H
