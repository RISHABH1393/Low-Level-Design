#include <iostream>
#include<list>
using namespace std;

class Isubscribe{
public:
virtual void notify(string msg) = 0;
};

class User : public Isubscribe{
private: 
    int userId;
public:
    User(int userId){
        this->userId = userId;
    }
    void notify(string msg){
        cout<<"user:"<<userId<<" msg :"<<msg<<endl;
    }

};

class Group{
    private:
    list<Isubscribe*>users;
    public:
    void subscribe(Isubscribe* user){
        users.push_back(user);
    }

    void unsubscribe(Isubscribe* user){
        users.remove(user);
    }
    void notify(string msg){
        for(auto user : users){
            user->notify(msg);
        }
    }
    
    
};

int main(){
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new mag");

    group->unsubscribe(user1);
    group->notify("new new msg");

    return 0;

}