#ifndef CRATIONAL_H
#define CRATIONAL_H

class CRational {
public:
    CRational(int numerator = 0, int denominator = 1);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int numerator);
    void setDenominator(int denominator);

    CRational operator+(const CRational& other) const;
    CRational operator-(const CRational& other) const;
    CRational operator*(const CRational& other) const;
    CRational operator/(const CRational& other) const;
    bool operator==(const CRational& other) const;
    bool operator<(const CRational& other) const;
// ... другие операторы ...

bool operator!=(const CRational& other) const;

private:
    int m_numerator;
    int m_denominator;

    void normalize();
    int gcd(int a, int b) const;
};

#endif // CRATIONAL_H
