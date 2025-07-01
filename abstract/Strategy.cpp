/** Example of the Strategy Pattern, which defines encapsulated algorithms
    (strategies) to make them interchangeable. Strategy lets the algorithm
    vary independently from the clients that use it.

    */

#include <iostream>

template <class Currency>
struct PaymentStrategy {
    virtual void pay(Currency amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategies
template <class Currency>
struct CreditCardPayment : public PaymentStrategy<Currency> {
    void pay(Currency amount) override {
        std::cout << "Paid " << amount << " Euro using Credit Card.\n";
    }
};
template <class Currency>
struct PayPalPayment : public PaymentStrategy<Currency> {
    void pay(Currency amount) override {
        std::cout << "Paid " << amount << " Euro using PayPal.\n";
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
  ShoppingCart<double> cart;

  // std::make_unique<CreditCardPayment>() is a function (C++14 and above), which
  // creates a std::unique_ptr smart pointer to a new CreditCardPayment object:
  cart.setPaymentStrategy(std::make_unique<CreditCardPayment<double>>());
  cart.checkout( 123.45 );

  cart.setPaymentStrategy(std::make_unique<PayPalPayment<double>>());
  cart.checkout( 67.89 );
}
