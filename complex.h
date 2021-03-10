#include <cmath>

using namespace std;

class Complex {
    double re;
    double im;


public:
    Complex(double real, double imag) {
        re = real;
        im = imag;
    }
    explicit Complex(double real) {
        re = real;
        im = 0;
    }

    Complex operator + (Complex other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator + (double d) const {
        return Complex(re + d, im);
    }

    friend Complex operator + (double d, Complex c);

    Complex operator - (Complex other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator - (double d) const {
        return Complex(re - d, im);
    }

    friend Complex operator - (double d, Complex c);

    Complex operator * (Complex other) const {
        return Complex(
                re * other.re - im * other.im,
                re * other.im + im * other.re);
    }

    Complex operator * (double d) const {
        return Complex(re * d, im * d);
    }

    friend Complex operator * (double d, Complex c);

    Complex operator / (Complex other) const {
        return Complex(
                (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im),
                (other.re * im - re * other.im) / (other.re * other.re + other.im * other.im));
    }

    Complex operator / (double d) const {
        return Complex(re / d, im / d);
    }

    friend Complex operator / (double d, Complex c);

    Complex operator + () const {
        return *this;
    }

    Complex operator - () const {
        return Complex(-re, -im);
    }

    bool operator == (Complex other) const {
        return re == other.re && im == other.im;
    }

    bool operator != (Complex other) const {
        return re != other.re || im != other.im;
    }

    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }
};

Complex operator + (double d, Complex c) {
    return Complex(c.re + d, c.im);
}

Complex operator - (double d, Complex c) {
    return Complex(d - c.re, -c.im);
}

Complex operator * (double d, Complex c) {
    return Complex(c.re * d, c.im * d);
}

Complex operator / (double d, Complex c) {
    return Complex(c.re / d, c.im / d);
}

double Abs(Complex c) {
    return sqrt(c.Re() * c.Re() + c.Im() * c.Im());
}
