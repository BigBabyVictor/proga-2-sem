#include "CRational.h"
#include <stdexcept>

int CRational::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

CRational::CRational(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    normalize();
}

int CRational::getNumerator() const {
    return m_numerator;
}

int CRational::getDenominator() const {
    return m_denominator;
}

void CRational::setNumerator(int numerator) {
    m_numerator = numerator;
    normalize();
}

void CRational::setDenominator(int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    m_denominator = denominator;
    normalize();
}

CRational CRational::operator+(const CRational& other) const {
    return CRational(m_numerator * other.m_denominator + m_denominator * other.m_numerator,
                     m_denominator * other.m_denominator);
}

CRational CRational::operator-(const CRational& other) const {
    return CRational(m_numerator * other.m_denominator - m_denominator * other.m_numerator,
                     m_denominator * other.m_denominator);
}

CRational CRational::operator*(const CRational& other) const {
    return CRational(m_numerator * other.m_numerator, m_denominator * other.m_denominator);
}

CRational CRational::operator/(const CRational& other) const {
    if (other.m_numerator == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return CRational(m_numerator * other.m_denominator, m_denominator * other.m_numerator);
}

bool CRational::operator==(const CRational& other) const {
    return m_numerator == other.m_numerator && m_denominator == other.m_denominator;
}

bool CRational::operator<(const CRational& other) const {
    return m_numerator * other.m_denominator < m_denominator * other.m_numerator;
}
// ... другие методы класса ...

bool CRational::operator!=(const CRational& other) const {
    return !(*this == other);
}

void CRational::normalize() {
    int gcdValue = gcd(m_numerator, m_denominator);
    m_numerator /= gcdValue;
    m_denominator /= gcdValue;
    if (m_denominator < 0) {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
}

