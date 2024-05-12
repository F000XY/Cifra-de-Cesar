#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#include <string>

class Criptografia {
public:
    std::string cifraDeCesar(std::string texto, int deslocamento);
    virtual void entrada();
};

class Descriptografia : public Criptografia {
public:
    std::string descriptografarCifraDeCesar(std::string texto, int deslocamento);
    void entrada() override;
};

class Menu {
public:
    void menu();
};

#endif // CRIPTOGRAFIA_H
