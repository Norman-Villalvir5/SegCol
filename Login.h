#include <fstream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <string>


class Login{
	private:
		string user, password, nombre;
		int numero;
		
	public:
		Login(string, string, string, int);
		Login(string, string);
		void crearUserRes();
		void crearUserGuard();
		bool loginRes();
		bool loginGuard();
		void leerResidentes();
		void leerGuardias();			
};

Login::Login(string _user, string _password, string _nombre, int _numero){
	user = _user;
	password = _password;
	nombre = _nombre;
	numero = _numero;
}

Login::Login(string _user, string _password){
	user = _user;
	password = _password;
}

void Login::crearUserRes(){
	ofstream archivo;
	
	archivo.open("Usuarios_Residentes.txt",ios::app);
	
	if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo<<user<<" "<<password<<" "<<nombre<<" "<<numero<<endl;
	
	archivo.close();
}

void Login::crearUserGuard(){
	ofstream archivo;
	
	archivo.open("Usuarios_Guardias.txt",ios::app);
	
	if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo<<user<<" "<<password<<" "<<nombre<<" "<<numero<<endl;
	
	archivo.close();
}

bool Login::loginRes(){
	bool confirm=false;
	string nombre, apellido;
	char contra[30], usr[30];
	
	ifstream archivo;
	archivo.open("Usuarios_Residentes.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!"<<endl;
		exit(1);
	}
	
	char usuario[user.length()];
	for(int i=0; i<sizeof(usuario); i++){
		usuario[i] = user[i];
	}
	
	char pass[password.length()];
	for(int i=0; i<sizeof(password); i++){
		pass[i] = password[i];
	}
	
	while(!archivo.eof()){
		
		archivo>>usr>>contra>>nombre>>apellido>>numero;
		
		if((strcmp(usr,usuario)==0)&&(strcmp(contra,pass)==0)){
			confirm=true;
		}
	}
	
	archivo.close();
	return confirm;
}

bool Login::loginGuard(){
	bool confirm=false;
	string nombre, apellido;
	char contra[30], usr[30];
	
	ifstream archivo;
	archivo.open("Usuarios_Guardias.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!"<<endl;
		exit(1);
	}
	
	char usuario[user.length()];
	for(int i=0; i<sizeof(usuario); i++){
		usuario[i] = user[i];
	}
	
	char pass[password.length()];
	for(int i=0; i<sizeof(password); i++){
		pass[i] = password[i];
	}
	
	archivo>>usr;
	
	while(!archivo.eof()){
		
		archivo>>contra>>nombre>>apellido>>numero;
		
		if((strcmp(usr,usuario)==0)&(strcmp(contra,pass)==0)){
			confirm=true;
		}
		archivo>>usr;
	}
	
	archivo.close();
	return confirm;
}

void leerResidentes(){
	ifstream archivo;
    string user, password, nombre, apellido;
    int numero;
        
    archivo.open("Usuarios_Residentes.txt",ios::in);
        
    if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo>>user;
	
	do{
		archivo>>password>>nombre>>apellido>>numero;
		cout<<"\t\t\t\t\tUsuario: "<<user<<endl;
		cout<<"\t\t\t\t\tContrasenia: "<<password<<endl;
		cout<<"\t\t\t\t\tNombre: "<<nombre<<" "<<apellido<<endl;
		cout<<"\t\t\t\t\tNumero: "<<numero<<endl;
		cout<<"\t\t\t\t\t   -------"<<endl;
		
		archivo>>user;
	}while(!archivo.eof());
	
	archivo.close();
}

void leerGuardias(){
	ifstream archivo;
    string user, password, nombre, apellido;
    int numero;
        
    archivo.open("Usuarios_Guardias.txt",ios::in);
        
    if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo>>user;
		
	do{
		archivo>>password>>nombre>>apellido>>numero;
		cout<<"\t\t\t\t\tUsuario: "<<user<<endl;
		cout<<"\t\t\t\t\tContrasenia: "<<password<<endl;
		cout<<"\t\t\t\t\tNombre: "<<nombre<<" "<<apellido<<endl;
		cout<<"\t\t\t\t\tNumero: "<<numero<<endl;
		cout<<"\t\t\t\t\t   -------"<<endl;
		
		archivo>>user;
	}while(!archivo.eof());
		
	archivo.close();
}
