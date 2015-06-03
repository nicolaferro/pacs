#include "polynom.hpp"

int main(){
	std::vector<double> a{1., 1.};
	std::vector<double> b{-1., 1.};
	std::vector<double> c{-1., 1., 2.};

	Polynomial p1(a);
	Polynomial p2(b);
	Polynomial p3(c);
	Polynomial p4; //Default construction

	std::cout<<"p1(x) = ";
	std::cout<<p1<<std::endl;
	std::cout<<"p1(5) = ";
	std::cout<<p1(5.)<<std::endl;

	std::cout<<std::endl;

	std::cout<<"p2(x) = ";
	std::cout<<p2<<std::endl;
	std::cout<<"p2(3) = ";
	std::cout<<p2(3.)<<std::endl;

	std::cout<<std::endl;

	std::cout<<"p3(x) = ";
	std::cout<<p3<<std::endl;
	std::cout<<"p3(4) = ";
	std::cout<<p3(4.)<<std::endl;

	std::cout<<std::endl;

	std::cout<<"Default construction:"<<std::endl;
	std::cout<<p4<<std::endl;

	std::cout<<std::endl;

	p4 = p3; //Copy assignment
	std::cout<<"Copy assignment:"<<std::endl;
	std::cout<<p4<<std::endl;

	std::cout<<std::endl;

	Polynomial p5(p3);
	std::cout<<"Copy construction:"<<std::endl;
	std::cout<<p5<<std::endl;

	std::cout<<std::endl;

	std::cout<<"p1+p2 = ";
	std::cout<<p1+p2<<std::endl;

	std::cout<<std::endl;

	std::cout<<"p1-p3 = ";
	std::cout<<p1-p3<<std::endl;

	std::cout<<std::endl;

	std::cout<<"p1*p3 = ";
	std::cout<<p1*p3<<std::endl;

	std::cout<<std::endl;
	
	std::cout<<"p3/p1 = "<<std::endl;
	std::cout<<"Quoziente: "<<std::endl;
	std::cout<<(p3/p1).first<<std::endl;
	std::cout<<"Resto: "<<std::endl;
	std::cout<<(p3/p1).second<<std::endl;

	std::cout<<std::endl;
	std::cout<< "Inserisci i coefficienti del polinomio in ordine crescente di grado (zeri inclusi)." <<std::endl;
	std::cin>>p4;
	std::cout<<p4<<std::endl;

	return 0;
}
