#include <iostream>
#include <string>

class Mailer{
protected:
    virtual const char* Greeting() = 0;
    virtual const char* Sign() = 0;  
    
    std::string from;
    std::string to;
    std::string msg;
public:
    Mailer(const char* from_cs, const char* to_cs,
            const char *msg_cs) : 
    from(from_cs),to(to_cs),msg(msg_cs) {}
    
    // template method
    const char* ComposeMail(){
        static std::string mail;
        
        mail = Greeting();
        mail += msg;
        mail += Sign();
        
        return mail.c_str();
    }
};

class WorkMail : public Mailer {
protected:
    const char* Greeting() override{
        static std::string value;
        value = "Dear ";
        value += to;
        value +="!";
        value += "\n";
        
        return value.c_str();;
    }
    
    const char* Sign() override {
        static std::string value;
        value = "\nWith best regards,";
        value += from;
        value += "\n\n";
        
        return value.c_str();;
    } 
public:
    WorkMail(const char* from, const char*to,const char *msg) : Mailer(from,to,msg) {}
};

class JokeMail : public Mailer {
protected:
    const char* Greeting() override{
        static std::string value;
        value = "Hi there!\n";
        return value.c_str();;
    }
    
    const char* Sign() override {
        static std::string value;
        value = "\nSee you later, ";
        value += to;
        value += "\n\n";
        
        return value.c_str();
    } 
public:
    JokeMail(const char* from, const char*to,const char *msg) : Mailer(from,to,msg) {}    
};

void PrintMail(Mailer *mailer){
    std::cout << mailer->ComposeMail();
}
int main(int argc, char** argv) {

    WorkMail mail1("Dmitriy V Dzuuba","Bill Gates","What's up?");
    JokeMail mail2("Dmitriy V Dzuuba","Bill Gates","What's up?");

    PrintMail(&mail1);
    PrintMail(&mail2);
    return 0;
}

