#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    try {
        Polynomial p1;
        Polynomial p2(std::vector<float>{1.0f, 0.0f, 3.0f});

        Polynomial sum = p1 + p2;
        Polynomial diff = p1 - p2;
        Polynomial prod = p1 * p2;

        cout << "Polynomial 1: " << p1 << endl;
        cout << "Polynomial 2: " << p2 << endl;
        cout << "Sum: " << sum << endl;
        cout << "Difference: " << diff << endl;
        cout << "Product: " << prod << endl;

        cout << "Evaluating p1 at x=2: " << p1.evaluate(2.0f) << endl;

        try {
            cout << "Accessing index 10 of p1: " << p1[10] << endl;
        }
        catch (const IndexOutOfRangeException& ex) {
            cout << "Caught exception: " << ex.what() << endl;
        }

        try {
            vector<float> roots = p2.evaluateRoots();
            cout << "Roots of p2: ";
            for (float root : roots) {
                cout << root << " ";
            }
            cout << endl;
        }
        catch (const InvalidArgumentException& ex) {
            cout << "Caught exception: " << ex.what() << endl;
        }

    }
    catch (const PolynomialException& ex) {
        cout << "Caught polynomial exception: " << ex.what() << endl;
    }
    catch (const std::exception& ex) {
        cout << "Caught exception: " << ex.what() << endl;
    }

    return 0;
}
