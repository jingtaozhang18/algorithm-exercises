#include <bits/stdc++.h>
using namespace std;

class OfficialAccount;

class User {
 public:
  User(string name = "", OfficialAccount *accnt = nullptr)
      : name(name), account(accnt) {}
  virtual void msgUpdate() = 0;

 protected:
  string name;
  OfficialAccount *account;
};

class MaleUser : public User {
 public:
  MaleUser(OfficialAccount *accnt = nullptr) : User("男性用户", accnt) {}
  void msgUpdate();
};

class FemaleUser : public User {
 public:
  FemaleUser(OfficialAccount *accnt = nullptr) : User("女性用户", accnt) {}
  void msgUpdate();
};

class OfficialAccount {
 protected:
  vector<User *> users;

 public:
  string topic;
  virtual void attach(User *) = 0;
  virtual void notify() = 0;
};

class LecternOfAboriginal : public OfficialAccount {
  void attach(User *user) override { users.push_back(user); }

  void notify() override {
    cout << "本次推送主题：" << this->topic << endl;
    for (auto it = users.begin(); it != users.end(); it++) {
      (*it)->msgUpdate();
    }
  }
};

// 因为OfficialAccount的定义在后，所以这个方法要拎出来写
void MaleUser::msgUpdate() {
  cout << this->name << (account->topic == "汽车" ? " 马上阅读" : " 先放着")
       << endl;
}

void FemaleUser::msgUpdate() {
  cout << this->name << (account->topic == "化妆品" ? " 马上阅读" : " 先放着")
       << endl;
}

int main() {
  OfficialAccount *account = new LecternOfAboriginal();
  // 订阅
  User *user1 = new FemaleUser(account);
  User *user2 = new MaleUser(account);
  // 绑定
  account->attach(user1);
  account->attach(user2);
  // 公众号推送新文章
  account->topic = "汽车";
  account->notify();
  return 0;
}