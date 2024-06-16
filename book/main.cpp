#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

class PriceBook {
private:
  struct Offer {
    int position;
    double value;
    int amount;
  };
  std::vector<Offer> offers;

  PriceBook(const PriceBook &rhs) { *this = rhs; }

  PriceBook &operator=(const PriceBook &rhs) {
    if (this != &rhs) {
      for (int i = 0; i < offers.size(); ++i) {
        this->offers[i] = rhs.offers[i];
      }
    }
    return *this;
  }

public:
  PriceBook() {}
  ~PriceBook() {}

  void insertOffer(int position, double value, int amount) {
    Offer newOffer = {position, value, amount};

    offers.insert(offers.begin() + position - 1, newOffer);
    for (size_t i = position; i < offers.size(); ++i) {
      offers[i].position++;
    }
  }

  void modifyOffer(int position, double value, int amount) {
    if (offers.empty()) {
      throw std::invalid_argument("Primeiro devemos criar, depois modificar.");
    }
    if (value != 0) {
      offers[position - 1].value = value;
    }
    if (amount != 0) {
      offers[position - 1].amount = amount;
    }
  }

  void deletOffer(int position) {
    if (position < 1) {
      throw std::invalid_argument("O posicao precisa ser maior que zero.");
    } else if (offers.empty()) {
      throw std::invalid_argument("Nao tem o que deletar, o livro esta vazio!");
    }
    offers.erase(offers.begin() + position - 1);
    for (size_t i = position; i < offers.size(); ++i) {
      offers[i].position++;
    }
  }

  void printPrinceBook() const {
    std::cout << std::setw(10) << std::setfill(' ') << "Posicao" << "|"
              << std::setw(10) << std::setfill(' ') << "Valor" << "|"
              << std::setw(10) << std::setfill(' ') << "Quantidade"
              << std::endl;
    for (size_t i = 0; i < offers.size(); ++i) {
      std::cout << std::setw(10) << std::setfill(' ') << offers[i].position
                << "|" << std::setiosflags(std::ios::right) << std::setw(10)
                << std::setiosflags(std::ios::right) << std::setfill(' ')
                << offers[i].value << "|" << std::setw(10)
                << std::setiosflags(std::ios::right) << std::setfill(' ')
                << offers[i].amount << std::endl;
    }
  }
};

enum { INSERT, MOD, DEL };

int main(void) {
  int notifications;

  std::cout << "Insira a quantidade de notificacoes" << std::endl;
  std::cin >> notifications;

  try {
    PriceBook book;

    for (int i = 0; i < notifications; ++i) {
      int position, action, amount;
      double value;
      char comma;
      std::cout << "Insira os valores na seguinte ordem" << std::endl;
      std::cout << "Posicao: valores positivos diferente de 0." << std::endl;
      std::cout << "Acao: 0 = INSERIR, 1 = MODIFICAR, 2 = DELETAR" << std::endl;
      std::cout << "Valores: Qualquer valor positivos diferente de 0."
                << std::endl;
      std::cout << "Quantidade: valor positivos diferente de 0." << std::endl;

      std::cin >> position >> comma >> action >> comma >> value >> comma >>
          amount;

      switch (action) {
      case INSERT:
        book.insertOffer(position, value, amount);
        break;
      case MOD:
        book.modifyOffer(position, value, amount);
        break;
      case DEL:
        book.deletOffer(position);
        break;
      default:
        std::cerr << "Acao invalida: " << action << std::endl;
        break;
      }
      book.printPrinceBook();
    }

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
