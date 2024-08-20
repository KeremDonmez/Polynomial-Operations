#include "Polynomial.h"
#include <cmath>
#include <algorithm>

Polynomial::Polynomial() : coefficients({ 0.0f }) {}

Polynomial::Polynomial(const std::vector<float>& coeffs) : coefficients(coeffs) {}

Polynomial::Polynomial(const std::list<float>& coeffs) : coefficients(coeffs.begin(), coeffs.end()) {}

std::vector<float> Polynomial::getCoefficients() const {
    return coefficients;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<float> result(maxSize, 0.0f);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        result[i] += coefficients[i];
    }
    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        result[i] += other.coefficients[i];
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<float> result(maxSize, 0.0f);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        result[i] += coefficients[i];
    }
    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        result[i] -= other.coefficients[i];
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    std::vector<float> result(coefficients.size() + other.coefficients.size() - 1, 0.0f);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator*(float scalar) const {
    std::vector<float> result(coefficients.size());

    for (size_t i = 0; i < coefficients.size(); ++i) {
        result[i] = coefficients[i] * scalar;
    }

    return Polynomial(result);
}

float Polynomial::operator[](size_t index) const {
    if (index >= coefficients.size()) {
        throw IndexOutOfRangeException();
    }
    return coefficients[index];
}

float Polynomial::evaluate(float x) const {
    float result = 0.0f;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

std::vector<float> Polynomial::evaluateRoots() const {
    if (coefficients.size() == 3) { // Quadratic case
        float a = coefficients[2];
        float b = coefficients[1];
        float c = coefficients[0];
        float discriminant = std::pow(b, 2) - 4 * a * c;
        if (discriminant >= 0) {
            float root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            float root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            return { root1, root2 };
        }
        else {
            throw InvalidArgumentException();
        }
    }
    throw InvalidArgumentException();
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (size_t i = 0; i < poly.coefficients.size(); ++i) {
        if (i > 0 && poly.coefficients[i] >= 0) {
            os << "+";
        }
        os << poly.coefficients[i] << "x^" << i << " ";
    }
    return os;
}
