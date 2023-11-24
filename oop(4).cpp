#include <iostream>
#include <chrono>
#include <vector>
//using namespace std::chrono;

class  Transaction
{
    double money;
    unsigned long int ww1;
    unsigned long int ww2;
    double number;

public:
   Transaction(double _money, double _ww1, double _ww2, double _number) {
        money = _money;
        ww1 = _ww1;
        ww2 = _ww2;
        number = _number;
        
    }
  
  

friend std::ostream& operator<<(std::ostream& os, const Transaction& t) {
    return os << "Summa:" << t.money << std::endl << "Person1:" << t.ww1 << std::endl << "Person2:" << t.ww2 << std::endl << "Number:" << t.number << std::endl << std::endl;


}
};

std::vector<Transaction> numbers;


struct Wallet {
    unsigned long int wn;
    double money;
    int number = 1;

public:
    Wallet(double _wn, double _money) {
        wn = _wn;
        money = _money;

    }
    void Transak(double money, Wallet& wallet2) {
        
        this->money = this->money - money;
        wallet2.money = wallet2.money +money;
        Transaction t(money, this->wn, wallet2.wn, number);
        number++;
        numbers.push_back(t);
        std::cout << t;
    }
};
std::ostream& operator<<(std::ostream& os, const Wallet& w) {
    return os << "Wallet number:" << w.wn << std::endl << "Money:" << w.money << std::endl << std::endl;


}


int main()
{
    Wallet Vovchik(228777666, 9876);
    std::cout << Vovchik;
    Wallet Kolyanchik(133766611, 1000);
    std::cout << Kolyanchik;
   // Transaction t1(-150,Vovchik.wn,Kolyanchik.wn,1);
   Vovchik.Transak(9000,  Kolyanchik);
   Vovchik.Transak(150,  Kolyanchik);
   Vovchik.Transak(1000,  Kolyanchik);
   
  std::cout << Vovchik;
  
  std::cout << Kolyanchik;
    return 0;
}
