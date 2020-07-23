#include <boost/bind/bind.hpp>
#include <iostream>
#include <cstdio>

using namespace boost::placeholders;

void function(int a,int b){
		std::cout << "arg1 = " << a << "|" << "arg2 = " << b << std::endl;
}




int main(){

		// Bind é útil para chamar funções com diferentes arranjos de argumentos

		// Nesse exemplo, 'f0' é usado de forma idêntica à função original.Os placeholders _1 e _2 indicam que o primeiro e segundo argumento de 'f0' serão REPASSADOS para 'function', na ordem em que são especificados
		auto f0 = boost::bind(function,_1,_2);

		f0(1,2);

		//Poderiamos, por exemplo, reordenar os argumentos
		auto f1 = boost::bind(function,_2,_1);


		f1(1,2);
	

		// Podemos gerar uma nova função que recebe apenas um argumento
		auto f2 = boost::bind(function,_1,_1);

		f2(5);

		// Podemos tambem fixar alguns argumentos
		auto f3 = boost::bind(function,0,_1);

		f3(1);
	

		//TODO criar uma classe que 
		// 1) Instancia um objeto que recebe via template o tipo de argumento
		// 2) possibilite o registro da função de vários argumentos
		// 3) permita que a função registrada seja chamada pelo objeto
		/* Ex:
		 * void soma(int,int){}
		 *
		 *
		 * Class A;
		 * A.registra (soma)  ... OU
		 * A.registra(boost::bind(soma,_1,_2))
		 * A.call()
		 *	
		 *
		 *
		*/


}
