//好友申请类：用于管理好友申请，对应friendship_request表

#ifndef FRIENDSHIPREQUESTLZY_H
#define FRIENDSHIPREQUESTLZY_H

#include<QObject>
#include<QDateTime>

class FriendshipLzy;

enum class RequestStatus { PENDING, REJECTED };

class FriendRequestLzy : public QObject {
    Q_OBJECT

private:
    FriendshipLzy* friendship;
    QDateTime requestTime;
    RequestStatus status;

public:
    FriendRequestLzy(FriendshipLzy* fs, const QDateTime& req_time, RequestStatus req_status, QObject *parent = nullptr)
        : QObject(parent), friendship(fs), requestTime(req_time), status(req_status) {}

    FriendshipLzy* getFriendship() const { return friendship; }
    QDateTime getRequestTime() const { return requestTime; }
    RequestStatus getStatus() const { return status; }

    void setFriendship(FriendshipLzy* fs) { friendship = fs; }
    void setRequestTime(const QDateTime& req_time) { requestTime = req_time; }
    void setStatus(RequestStatus req_status) { status = req_status; }
};

#endif // FRIENDSHIPREQUESTLZY_H
