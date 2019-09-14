#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h> 

using namespace std;

class Anuncio{
	private:
		string tipo_carro, color_carro, nombre, user, dia, day; 
		int canpasajeros, cont, numero, hora, min;
		
	public:
		Anuncio(string, string, string, int, string, int, string, int, int);
		Anuncio(int, string, int, int);
		Anuncio(string);
		Anuncio(int);
		Anuncio();
		void crearAnuncio();
		void marcarEntrada();
		void crearHistorial();
		void mostarHistorial();
		void leerAnuncio ();	
	    void eliminarAnuncio();
};

Anuncio::Anuncio (string _nombre, string _tipo_carro, string _color_carro, int _canpasajeros, string _user, int _cont, string _dia, int _hora, int _min){
	nombre = _nombre;
	tipo_carro = _tipo_carro;
	color_carro = _color_carro;
	canpasajeros = _canpasajeros;
	user = _user;
	cont = _cont;
	dia = _dia;
	hora = _hora;
	min = _min;
}

Anuncio::Anuncio(int _numero, string _day, int _hora, int _min){
	numero = _numero;
	day = _day;
	hora = _hora;
	min = _min;
}

Anuncio::Anuncio(string _user){
	user = _user;
}

Anuncio::Anuncio(int _numero){
	numero = _numero;
}

Anuncio::Anuncio(){
}

void Anuncio::crearAnuncio(){
	ofstream archivo;
	archivo.open("Anuncios.txt",ios::app);
    
		
    if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo<<cont<<" ";
	archivo<<user<<" ";
	archivo<<nombre<<" ";
	archivo<<tipo_carro<<" ";
	archivo<<color_carro<<" ";
	archivo<<canpasajeros<<" ";
	archivo<<"No_Ingresado ";
	archivo<<dia<<" ";
	archivo<<hora<<":"<<min<<endl;

	archivo.close();
}

void Anuncio::marcarEntrada(){
	string in, hour;
	
	ifstream salida;
	salida.open("Anuncios.txt",ios::in);

	ofstream entrada;
	entrada.open("temp.txt",ios::out);
	if (salida.fail()){
		cout<<"hubo un error al abrir el archivo!";
		getch();
	}else{
		salida>>cont;
		
		while(!salida.eof()){
		
			salida>>user>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hour;
			
			if(numero == cont){
				entrada<<cont<<" "<<user<<" "<<nombre<<" "<<tipo_carro<<
				" "<<color_carro<<" "<<canpasajeros<<" "<<" Ingresado "<<day<<" "<<hora<<":"<<min<<endl;
				cout<<"\t\t\t\t\t\tLa visita ha ingresado!!"<<endl;
				getch ();
			}else{
				entrada<<cont<<" "<<user<<" "<<nombre<<" "<<tipo_carro<<
				" "<<color_carro<<" "<<canpasajeros<<" "<<in<<" "<<dia<<" "<<hour<<endl;
			}
			salida>>cont;
		}
		
		entrada.close();
		salida.close();
		
		remove("Anuncios.txt");
		rename("temp.txt","Anuncios.txt");
	}
}

void Anuncio::crearHistorial(){
	string in, hour;
	char usuario[40], nArchivo[40];
	
	ifstream salida;
	salida.open("Anuncios.txt",ios::in);
	
	char userNM[user.length()];
	for(int i=0; i<sizeof(userNM); i++){
		userNM[i] = user[i];
	}
	
	strcpy(nArchivo,userNM);
	strcat(nArchivo,".txt");

	ofstream entrada;
	entrada.open(nArchivo,ios::out);
	if (salida.fail()){
		cout<<"hubo un error al abrir el archivo!";
		getch();
	}else{
		salida>>cont;
		
		while(!salida.eof()){
		
			salida>>usuario>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hour;
			
			if(strcmp(userNM,usuario) == 0){
				entrada<<usuario<<" "<<nombre<<" "<<tipo_carro<<
				" "<<color_carro<<" "<<canpasajeros<<" "<<in<<" "<<dia<<" "<<hour<<endl;
			}
			salida>>cont;
		}
		entrada.close();
		salida.close();
	}
}

void Anuncio::leerAnuncio(){
	ifstream archivo;
	string in, hour;
        
    archivo.open("Anuncios.txt",ios::in);
        
    if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo>>cont;
		
	while(!archivo.eof()){
		archivo>>user>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hour;
		
		cout<<"\t\t\t\tAnuncio numero: "<<cont<<endl;
		cout<<"\t\t\t\tAnuncio hecho por: "<<user<<endl;
		cout<<"\t\t\t\tNombre de visita: "<<nombre<<endl;
		cout<<"\t\t\t\tTipo de carro: "<<tipo_carro<<endl;
		cout<<"\t\t\t\tColor de carro: "<<color_carro<<endl;
		cout<<"\t\t\t\tCantidad de pasajeros: "<<canpasajeros<<endl;
		cout<<"\t\t\t\tEstado: "<<in<<endl;
		cout<<"\t\t\t\tEl "<<dia<<" a las: "<<hour<<endl;
		
		cout<<"\t\t\t\t\t-----"<<endl;
		
		archivo>>cont;
	}
		
	archivo.close();
}

void Anuncio::mostarHistorial(){
	ifstream archivo;
	string in, hour;
    char nArchivo[40];
    
    char usuario[user.length()];
	for(int i=0; i<sizeof(usuario); i++){
		usuario[i] = user[i];
	}
	
	strcpy(nArchivo,usuario);
	strcat(nArchivo,".txt");
        
    archivo.open(nArchivo,ios::in);
        
    if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}else{
	
		archivo>>user;
		
		while(!archivo.eof()){
			archivo>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hour;
			
			cout<<"\t\t\t\tAnuncio hecho por: "<<user<<endl;
			cout<<"\t\t\t\tNombre de visita: "<<nombre<<endl;
			cout<<"\t\t\t\tTipo de carro: "<<tipo_carro<<endl;
			cout<<"\t\t\t\tColor de carro: "<<color_carro<<endl;
			cout<<"\t\t\t\tCantidad de pasajeros: "<<canpasajeros<<endl;
			cout<<"\t\t\t\tEstado: "<<in<<endl;
			cout<<"\t\t\t\tAnuncio hecho el "<<dia<<" a las : "<<hour<<endl;
			
			cout<<"\t\t\t\t\t-----"<<endl;
			
			archivo>>user;
		}
		archivo.close();
	}
}

void Anuncio::eliminarAnuncio(){
	string in, hour;
	
	ifstream salida;
	salida.open("Anuncios.txt",ios::in);

	ofstream entrada;
	entrada.open("temp.txt",ios::out);
	if (salida.fail()){
		cout<<"hubo un error al abrir el archivo!";
		getch();
	}else{
		
		salida>>cont;
		
		while(!salida.eof()){
		
			salida>>user>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hour;
			
			if(numero == cont){
				cout<<"\t\t\t\t\t\tEl Anuncio ha sido eliminado"<<endl;
				getch ();
			}else if(numero<cont){
				entrada<<(cont-1)<<" "<<user<<" "<<nombre<<" "<<tipo_carro<<
				" "<<color_carro<<" "<<canpasajeros<<" "<<in<<" "<<dia<<" "<<hour<<endl;
			}else if(numero>cont){
				entrada<<cont<<" "<<user<<" "<<nombre<<" "<<tipo_carro<<
				" "<<color_carro<<" "<<canpasajeros<<" "<<in<<" "<<dia<<" "<<hour<<endl;
			}
			salida>>cont;
		}
		
		entrada.close();
		salida.close();
		
		remove("Anuncios.txt");
		rename("temp.txt","Anuncios.txt");
	}
}

int contador(){
	string nombre, tipo_carro, color_carro, user, in, dia, hora;
	int canpasajeros, cont;
	
	ifstream salida;
	salida.open("Anuncios.txt",ios::in);
	
	if (salida.fail()){
		cont=0;
		return cont;
	}else{
		
		while(!salida.eof()){
			salida>>cont>>user>>nombre>>tipo_carro>>color_carro>>canpasajeros>>in>>dia>>hora;
		}
		return cont;
	}
}
