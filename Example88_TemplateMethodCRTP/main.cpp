#include <iostream>
#include <string>

template <class T> class Mailer {
protected:
    std::string from;
    std::string to;
    std::string msg;
public:

    Mailer(const char* from_cs, const char* to_cs, const char *msg_cs) :
    from(from_cs), to(to_cs), msg(msg_cs) {
    }

    // template method

    const char* ComposeMail() {
        static std::string mail;

        mail = ((T*)this)->Greeting();
        mail += msg;
        mail += ((T*)this)->Sign();

        return mail.c_str();
    }

};

class WorkMail : public Mailer<WorkMail> {
protected:

    const char* Greeting() {
        static std::string value;
        value = "Dear ";
        value += to;
        value += "!";
        value += "\n";

        return value.c_str();
        ;
    }

    const char* Sign() {
        static std::string value;
        value = "\nWith best regards,";
        value += from;
        value += "\n\n";

        return value.c_str();
        
    }
    friend class Mailer<WorkMail>;
public:

    WorkMail(const char* from, const char*to, const char *msg) : Mailer<WorkMail>(from, to, msg) {
    }
};

class JokeMail : public Mailer<JokeMail> {
protected:

    const char* Greeting() {
        static std::string value;
        value = "Hi there!\n";
        return value.c_str();
        ;
    }

    const char* Sign() {
        static std::string value;
        value = "\nSee you later, ";
        value += to;
        value += "\n\n";

        return value.c_str();
        ;
    }
    friend class Mailer<JokeMail>;
public:

    JokeMail(const char* from, const char*to, const char *msg) : Mailer<JokeMail>(from, to, msg) {
    }
};

int main(int argc, char** argv) {

    WorkMail mail1("Dmitriy V Dzuuba", "Bill Gates", "What's up?");
    JokeMail mail2("Dmitriy V Dzuuba", "Bill Gates", "What's up?");

    std::cout << mail1.ComposeMail();
    std::cout << mail2.ComposeMail();

    return 0;
}

