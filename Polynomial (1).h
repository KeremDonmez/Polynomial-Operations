#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>

class Polynomial {
private:
    std::vector<float> coefficients;

public:
    Polynomial();
    explicit Polynomial(const std::vector<float>& coeffs);
    explicit Polynomial(const std::list<float>& coeffs);

    std::vector<float> getCoefficients() const;

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator*(float scalar) const;

    float operator[](size_t index) const;

    float evaluate(float x) const;
    std::vector<float> evaluateRoots() const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
};

class PolynomialException : public std::exception {
public:
    explicit PolynomialException(const char* message) : msg_(message) {}
    explicit PolynomialException(const std::string& message) : msg_(message) {}
    virtual ~PolynomialException() noexcept {}
    virtual const char* what() const noexcept { return msg_.c_str(); }

protected:
    std::string msg_;
};

class IndexOutOfRangeException : public PolynomialException {
public:
    IndexOutOfRangeException() : PolynomialException("Index out of range") {}
};

class InvalidArgumentException : public PolynomialException {
public:
    InvalidArgumentException() : PolynomialException("Invalid argument") {}
};

#endif 
