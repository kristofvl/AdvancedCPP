/** Example of the Strategy Pattern, which defines encapsulated algorithms
    (strategies) to make them interchangeable. Strategy lets the algorithm
    vary independently from the clients that use it.

    */

#include <iostream>
#include <iomanip> // for std::setprecision

template <class Currency>
struct PaymentStrategy {
    virtual void pay(Currency amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategies
template <class Currency>
struct CreditCardPayment : public PaymentStrategy<Currency> {
    void pay(Currency amount) override {
      std::cout << "Paid ";
      if constexpr (std::is_integral<Currency>::value) {
        std::cout << amount << " (int) Euro";
      } else if constexpr (std::is_floating_point<Currency>::value) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << amount << " (float) Euro";
      } else {
        std::cout << " something with an unsupported type";
      }
      std::cout <<" using Credit Card.\n";
    }
};

// The shopping cart class contains a unique strategy smart pointer, which
// can be set to any of the above payment strategies. The checkout function
// will then call the strategies' pay method (polymorphism). This is the
// Strategy Context.
template <class Currency>
class ShoppingCart {
  std::unique_ptr<PaymentStrategy<Currency>> strategy;  // smart pointer
 public:
  void setPaymentStrategy(std::unique_ptr<PaymentStrategy<Currency>> ps) {
    strategy = std::move(ps);
  }
  void checkout(Currency total) {
    if (strategy) strategy->pay(total);
    else std::cout << "No payment method selected.\n";
  }
};


int main() {
  ShoppingCart<int> cart1;
  cart1.setPaymentStrategy(std::make_unique<CreditCardPayment<int>>());
  cart1.checkout( 100 );

  ShoppingCart<double> cart2;
  cart2.setPaymentStrategy(std::make_unique<CreditCardPayment<double>>());
  cart2.checkout( 123.4512 );
}
