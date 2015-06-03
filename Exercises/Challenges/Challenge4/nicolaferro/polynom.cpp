#include "polynom.hpp"
#include <cmath>
#include <string> 
#include <sstream>

Polynomial::Polynomial(std::vector<double> const & v): coefficients(v) {this->normalize();}

Polynomial Polynomial::operator-()const
{
  std::vector<double> aux;

  for(unsigned i=0; i<coefficients.size(); i++){
	aux.push_back(-coefficients[i]);
  }

  return Polynomial(aux);
}

Polynomial Polynomial::operator+()const
{
  return *this;
}

Polynomial &
Polynomial::operator +=(Polynomial const & r)
{
  auto l1=degree()+1;
  auto l2=r.degree()+1;
  if(l1<l2) coefficients.resize(l2);
  
  for(unsigned i=0; i<r.coefficients.size(); i++){
	coefficients[i]+=r.coefficients[i];
  }

  normalize();
  return *this;
}

Polynomial operator +(Polynomial const &l, Polynomial const & r)
{
  Polynomial temp(l);
  temp+=r;
  return temp;
}


Polynomial &
Polynomial::operator -=(Polynomial const & r)
{
  auto l1=degree()+1;
  auto l2=r.degree()+1;
  if(l1<l2) coefficients.resize(l2);
  
  for(unsigned i=0; i<r.coefficients.size(); i++){
	coefficients[i]-=r.coefficients[i];
  }

  normalize();
  return *this;
}

Polynomial operator -(Polynomial const &l, Polynomial const & r)
{
  Polynomial temp(l);
  temp-=r;
  return temp;
}

Polynomial &
Polynomial::operator *=(Polynomial const & r)
{
  auto degp = degree()+r.degree();
  coefficients.resize(degp+1);
  std::vector<double> aux(degp+1,0.);

  for(unsigned i=0; i<coefficients.size(); i++){
	for(unsigned j=0; j<r.coefficients.size(); j++){
		aux[i+j] += coefficients[i]*r.coefficients[j];
	}
  }
  
  coefficients = aux;
  normalize();

  return *this;
}

Polynomial operator *(Polynomial const &l, Polynomial const & r)
{
  Polynomial temp(l);
  temp*=r;
  return temp;
}

std::pair<Polynomial, Polynomial> operator /(Polynomial const &l, Polynomial const & r)
{
  std::pair<Polynomial, Polynomial> temp;
  auto degl = l.degree();
  auto degr = r.degree();
  int degd = degl - degr;

  if(degr>degl){
	temp.first.coefficients={0.};
	temp.second=l;
  }
  else{
  	temp.first.coefficients.resize(degd+1,0.);
	Polynomial aux = l;
	auto degaux = degl;

	while(degaux>=degr){
		
		std::vector<double> v(degaux-degr+1,0.);		

		temp.first.coefficients[degaux - degr]=aux.coefficients[degaux]/r.coefficients[degr];

		v[degaux-degr]=temp.first.coefficients[degaux - degr];
		Polynomial mono(v);		
		
		aux-=mono*r;
		aux.normalize();
		
		degaux = aux.degree();
	}

	temp.second=l-temp.first*r;
  }
  
  return temp;
}

std::ostream & operator << (std::ostream & str, Polynomial const & r)
{
  if((r.coefficients.size()==1 && r.coefficients[0]==0.) || r.coefficients.size()==0)
	str<< "0";
  else
	  for(int i=r.coefficients.size()-1; i>=0; i--){
		if(r.coefficients[i]!=0.){
			if(i>1){
				str<<std::showpos << r.coefficients[i]<<"x^";
				str<<std::noshowpos<<i;
			}
			else if(i!=0)
				str<<std::showpos << r.coefficients[i]<<"x";
			else
				str<<std::showpos << r.coefficients[i];
		}
	  }
 
  return str;
}

std::istream & operator >> (std::istream & str, Polynomial & r){

  std::string tmp;
  double n(0);
  std::vector<double> v;

  std::getline(str, tmp);
  std::stringstream ss(tmp);

  while (ss>>n) {

        v.push_back(n);
  }
  
  r=Polynomial(v);

  return str;
}


double Polynomial::operator()(double const & v){
	double result(0);
	for(auto i=0; i<coefficients.size(); i++){
		double pow(1);

		for(auto j=0; j<i; j++ )
			pow*=v;

		result+=coefficients[i]*pow;
	}
	return result;
}

void Polynomial::normalize()
{
  unsigned j(0);
  unsigned effective;

  if(coefficients.size()==1)
	j=0;
  else
	  for(int i=coefficients.size()-1; i>=0; i--){
		if(coefficients[i]==0.)
			j++;
		else
			break;
	  } 

  effective = degree() + 1 - j;
  coefficients.resize(effective);
}
