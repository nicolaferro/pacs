#ifndef __POLYNOM_HPP__
#define __POLYNOM_HPP__

#include <vector>
#include <iostream>

class Polynomial
{
public:
  
  Polynomial(std::vector<double> const &);

  Polynomial() = default;
  Polynomial(Polynomial const &)=default;
  
  Polynomial &operator +=(Polynomial const &);
  Polynomial &operator -=(Polynomial const &);
  Polynomial &operator *=(Polynomial const &);

  Polynomial operator-() const;
  Polynomial operator+() const;

  double operator()(double const &);
  
  friend Polynomial operator+(Polynomial const &,Polynomial const &);
  friend Polynomial operator-(Polynomial const &,Polynomial const &);
  friend Polynomial operator*(Polynomial const &,Polynomial const &);
  friend std::pair<Polynomial,Polynomial> operator/(Polynomial const &,Polynomial const &);
  
  friend std::ostream & operator << (std::ostream &, Polynomial const &);
  friend std::istream & operator >> (std::istream &, Polynomial &);

  inline int degree() const {return this->coefficients.size()-1;}

private:
  std::vector<double> coefficients;
  void normalize();
};

#endif
