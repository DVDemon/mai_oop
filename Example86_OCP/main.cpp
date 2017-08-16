#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class ConnectionEnded {
};

class IAddress{
public:
    virtual const char* ToString() = 0;
};

class AddressPhone : public IAddress{
protected:
    std::string value;
public:
    AddressPhone(const char *phone) : value(phone){}
    const char* ToString() override  {
       return value.c_str(); 
    }
};
class AddressIP : public IAddress{
protected:
    std::shared_ptr<unsigned char> value;
public:
    AddressIP(std::initializer_list<unsigned char> param) : value(new unsigned char[param.size()]) {
        //value = new unsigned char[param.size()];
        int i=0;
        unsigned char *ptr=value.get();
        for(auto a:param) ptr[i++]=a;
        
    }
    const char* ToString() override  {
       static std::string str;
       unsigned char *ptr=value.get();
       str = std::to_string((int)ptr[0])+"."+std::to_string((int)ptr[1])+"."+std::to_string((int)ptr[2])+"."+std::to_string((int)ptr[3]);
       return str.c_str(); 
    }

};


class IConnection {
protected:
    bool connected;
    std::shared_ptr<IAddress> number;
public:
    IConnection() : connected(false), number(nullptr) {
    }

    virtual bool Deal(std::shared_ptr<IAddress> value) {
        number = value;
        connected = true;
        std::cout << "Dialing:" << number->ToString() << std::endl;
        return connected;
    }

    virtual bool Connected() {
        return connected;
    }

    virtual void Hangup() {
        std::cout << "Hungup:" << number->ToString() << std::endl;
        number.reset();
        connected = false;
    }

};

template <class T> class Channel {
protected:
    std::vector<T> buffer;
public:

    void Send(T Data) {
        std::cout << "Send:" << Data << std::endl;
        buffer.push_back(Data);
    }

    bool NotEmpty() {
        return !buffer.empty();
    }

    T Receive() {
        if (buffer.empty()) throw ConnectionEnded();
        T res = buffer.front();
        buffer.erase(buffer.begin());
        std::cout << "Recv:" << res << std::endl;
        return res;
    }
};

template <class T> class IModem {
public:
    void Send(T Data, Channel<T> &output_channel) {
        // do something
        output_channel.Send(Data);
    }
    char Receive(Channel<T> &input_channel) {
        // do something
        return input_channel.Receive();
    }
};

bool Connect(IConnection *connection,std::shared_ptr<IAddress> address) {
    connection->Deal(address);
    if (!connection->Connected()) {
        std::cout << "Error: not connected" << std::endl;
        return false;
    }
    return true;
}

void Test(IModem<char> *modem, Channel<char> &input_channel, Channel<char> &output_channel) {
    char test_message[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    std::vector<char> test_answer;

    for (auto i : test_message) modem->Send(i, input_channel);

    try {
        while (true) test_answer.push_back(modem->Receive(output_channel));
    } catch (ConnectionEnded ex) {}
    
    bool equal = (test_answer.size() == 12);
    for (int i = 0; i < 12; i++) if (test_message[i] != test_answer[i]) equal = false;
    if (!equal) std::cout << "Error: wrong answer" << std::endl;
           else std::cout << "Ok" << std::endl;
}

void Disconnect(IConnection *connection) {
    connection->Hangup();
}

class Modem : public IConnection, public IModem<char> {
};

int main(int argc, char** argv) {

    Modem modem;
    Channel<char> channel;
    
    if (Connect(&modem,std::make_shared<AddressIP>(AddressIP{127,0,0,1}))){//Phone("8-800-8888888")))) {
        Test(&modem, channel, channel);
        Disconnect(&modem);
    }

    return 0;
}

