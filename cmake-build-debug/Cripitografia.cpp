#include "Criptografia.h"
#include <iostream>
#include <Windows.h>
#include <limits>

std::string Criptografia::cifraDeCesar(std::string texto, int deslocamento) {
    std::string criptografado;

    for (size_t i = 0; i < texto.length(); i++) {
        if (isalpha(texto[i])) {
            char verificacao = isupper(texto[i]) ? 'A' : 'a';
            criptografado += char((texto[i] + deslocamento - verificacao + 26) % 26 + verificacao);
        } else {
            criptografado += texto[i];
        }
    }

    return criptografado;
}

void Criptografia::entrada() {
    SetConsoleOutputCP(CP_UTF8);
    std::string texto;
    int deslocamento;
    std::cout << "Digite o texto a ser criptografado:  ";
    std::cin >> texto;
    std::cout << "Digite o número de posições de deslocamento:  ";
    std::cin >> deslocamento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string textoCriptografado = cifraDeCesar(texto, deslocamento);
    std::cout << "Texto criptografado: " << textoCriptografado << std::endl;
    std::cout << std::endl;
}

std::string Descriptografia::descriptografarCifraDeCesar(std::string texto, int deslocamento) {
    return cifraDeCesar(texto, -deslocamento);
}

void Descriptografia::entrada() {
    SetConsoleOutputCP(CP_UTF8);
    std::string texto;
    int deslocamento;
    std::cout << "Digite o texto a ser descriptografado:  ";
    std::cin >> texto;
    std::cout << "Digite o número de posições para voltar no deslocamento:  ";
    std::cin >> deslocamento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string textoDescriptografado = descriptografarCifraDeCesar(texto, deslocamento);
    std::cout << "Texto descriptografado: " << textoDescriptografado << std::endl;
    std::cout << std::endl;
}

void Menu::menu() {
    SetConsoleOutputCP(CP_UTF8);
    Criptografia cripto;
    Descriptografia descripto;
    int opcao;
    while (true) {
        std::cout << "Digite a opção para realizar os processos de criptografia: " << std::endl;
        std::cout << "1- Realizar a criptografia Cifra de Cesar" << std::endl;
        std::cout << "2- Realizar a descriptografia Cifra de Cesar" << std::endl;
        std::cout << "3- Sair do programa" << std::endl;
        std::cout << std::endl;
        std::cin >> opcao;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                cripto.entrada();
                break;
            case 2:
                descripto.entrada();
                break;
            case 3:
                return;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
        std::cout << std::endl;
    }
}
