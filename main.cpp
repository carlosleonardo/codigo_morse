#include <iostream>
#include <limits>
constexpr char codigos[][5] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

void codificarMorse();

void decodificarMorse();

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    std::cout << "Código Morse!" << std::endl;
    bool sair = false;

    do {
        std::cout << "1 - Codificar" << std::endl;
        std::cout << "2 - Decodificar" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        int opcao;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        if (std::cin.fail()) {
            std::cin.clear(); // Limpa o estado de falha
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a entrada inválida
            std::cout << "Entrada inválida. Por favor, tente novamente." << std::endl;
            continue;
        }
        switch (opcao) {
            case 1:
                codificarMorse();
                break;
            case 2:
                decodificarMorse();
                break;
            case 0:
                sair = true;
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, tente novamente." << std::endl;
                break;
        }
    } while (!sair);
    return 0;
}

void codificarMorse() {
    std::string texto;
    std::cout << "Texto a codificar(somente Maiúsculas): ";
    std::cin.ignore(); // Limpa o buffer de entrada
    std::getline(std::cin, texto);
    std::cout << "Texto codificado em Morse: ";
    for (const char c: texto) {
        if (c >= 'A' && c <= 'Z') {
            std::cout << codigos[c - 'A'] << " ";
        } else if (c == ' ') {
            std::cout << "/ ";
        }
    }
    std::cout << std::endl;
}

void decodificarMorse() {
    std::string morse;
    std::cout << "Texto para decodificar: ";
    std::cin.ignore(); // Limpa o buffer de entrada
    std::getline(std::cin, morse);
    std::cout << "Texto decodificado: ";
    std::string codigoAtual;

    // percorre a string morse caractere por caractere e separa os códigos por espaços
    // quando encontra um espaço, verifica o código atual e imprime a letra correspondente
    for (size_t i = 0; i <= morse.length(); ++i) {
        if (i < morse.length() && morse[i] != ' ') {
            codigoAtual += morse[i];
        } else {
            if (codigoAtual == "/") {
                std::cout << " ";
            } else {
                for (size_t j = 0; j < 26; ++j) {
                    if (codigoAtual == codigos[j]) {
                        std::cout << static_cast<char>('A' + j);
                        break;
                    }
                }
            }
            codigoAtual.clear();
        }
    }
    std::cout << std::endl;
}
