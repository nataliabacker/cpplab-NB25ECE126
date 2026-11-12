#include <iostream>
using namespace std;

class MathError {};
class DivideByZero : public MathError {};

int main() {
  
    try {
        throw DivideByZero();
    } catch (MathError&) {
        cout << "Caught MathError (DivideByZero is hidden!)\n";
    } catch (DivideByZero&) {
        cout << "Caught DivideByZero\n";  
    }

   
    try {
        throw DivideByZero();
    } catch (DivideByZero&) {
        cout << "Caught DivideByZero\n";
    } catch (MathError&) {
        cout << "Caught MathError\n";
    }
}
