#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include "Anuncio.h"
#include "Login.h"
#include "Tiempo.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int opcion, op, opMenu, numero;
	string user, password, nombre;
	char ch, resp;
	//User y contraseña de Administrador
	string userAd="admin", contraAd="0000";
	                                                                                                                                             
	cout<<"\n\n\n\n";
	cout<<"\t\t\t---Bienvenido a SegCol---"<<endl;
	cout<<"\n";
	cout<<"\t\t\t\t---Login---"<<endl;
	cout<<"\t\t\t1. Ingresar al sistema."<<endl;
	cout<<"\t\t\t2. Crear Usuario."<<endl;
	cout<<"\t\t\t3. Salir del sistema."<<endl;
	cout<<"\t\t\t";
	cin>>op;
	    
	if(op==1){
	    cout<<"\t\t\tIngrese su usuario: ";
	   	cin>>user;
	  	cout<<"\t\t\tIngrese su contrasenia: ";
	    ch = _getch();
	   	while(ch != 13){
	    	if(ch != 8){
	    		password.push_back(ch);
	    		cout<<'*';
			}else{
				if(password.length() > 0){
					cout<<"\b \b";
					password = password.substr(0, password.length() -1);
				}
			}
			ch = _getch();
		}
		cout<<endl;
	    Login log = Login(user, password);
	    log.loginRes();
	    log.loginGuard();
	    if(log.loginRes()==true){
	       	cout<<"\t\t\tSe ha ingresado correctamente!"<<endl;
	       	getch();
	       	system("cls");
	       	opcion = 1;
			}else if(log.loginGuard()==true){
				cout<<"\t\t\tSe ha ingresado correctamente!"<<endl;
				getch();
	       		system("cls");
	        	opcion = 2;
				}else if(user==userAd && password==contraAd){
					cout<<"\t\t\tSe ha ingresado correctamente!"<<endl;
					getch();
					system("cls");
					opcion = 3;
					}else{
						cout<<"\t\t\tUsuario o contrasenia incorrectos!!"<<endl;
						getch();
						system("cls");
						return main();
					}
	}else if(op == 2){
	   	system("cls");
	   	cout<<"\n\n\n\n";
	    cout<<"\t\t\t---------------------"<<endl;
		cout<<"\t\t\t----Crear Usuario----"<<endl;
		cout<<"\t\t\t---------------------"<<endl;
	    cout<<"\t\t\tIngrese su usuario: "<<endl;
	    cout<<"\t\t\t";
	    cin>>user;
	    cout<<"\t\t\tIngrese su contrasenia: "<<endl;
	    cout<<"\t\t\t";
	    cin>>password;
	    cout<<"\t\t\tIngrese su primer nombre y primer apellido: "<<endl;
	    cout<<"\t\t\t";
	    cin.ignore();
	    getline(cin,nombre);
	    cout<<"\t\t\tIngrese su numero: "<<endl;
	    cout<<"\t\t\t";
	    cin>>numero;
	    Login log = Login(user, password, nombre, numero);
	    log.crearUserRes();
	    cout<<"\t\t\tUsuario creado correctamente!!"<<endl;
		getch();
	    system("cls");
	    return main();
	}else if (op == 3){
		return 0;
	}else{
		cout<<"\t\t\tIngrese una de las dos opciones!!"<<endl;
		getch();
	    system("cls");
	    return main();
	}
	   
	switch(opcion){
	   	case 1:
	    	do{
	    		cout<<"\n\n\n\n";
	    		cout<<"\t\t\t---Seleccione una opcion: "<<endl;
	    		cout<<"\t\t\t1. Anunciar a un visitante."<<endl;
	    		cout<<"\t\t\t2. Ver historial de anuncios."<<endl;
	    		cout<<"\t\t\t3. Salir al menu principal."<<endl;
	    		cout<<"\t\t\t4. Salir del sistema."<<endl;
	    		cout<<"\t\t\t";
	    		cin>>opMenu;
	    
		    	if(opMenu==1){
		    		string nombre, color_carro, tipo_carro, day;
					int canpasajeros, cont=contador();
					int hour, min;
					
					do{
						cont++;
						hour = hora();
						min = mins();
						day = dia();
						
						
						cout<<"\t\t\tNombre del visitante: "<<endl;
						cout<<"\t\t\t";
						cin.ignore();
						getline(cin,nombre);
						
						cout<<"\t\t\tTipo de carro: "<<endl;
						cout<<"\t\t\t";
			    		getline(cin,tipo_carro);
			    		
			   		 	cout<<"\t\t\tColor del carro: "<<endl;
			   		 	cout<<"\t\t\t";
			   		 	getline(cin,color_carro);
			    		
			    		cout<<"\t\t\tCantidad de pasajeros: "<<endl;
			    		cout<<"\t\t\t";
			    		cin>>canpasajeros;
			    		
			    		Anuncio anu = Anuncio(nombre, tipo_carro, color_carro, canpasajeros, user, cont, day, hour, min);
			    		anu.crearAnuncio();
			    		
						cout<<"\t\t\tSi desea hacer mas anuncios escriba (S) o (s): "<<endl;
						cout<<"\t\t\t";
						cin>>resp;
					}while(resp=='S' || resp=='s');
					system("cls");
				}else if(opMenu==2){
					
		       		Anuncio anu = Anuncio(user);
		       		anu.crearHistorial();
		       		anu.mostarHistorial();
		       		
			   	}else if(opMenu==3){
			   		system("cls");
			   		return main();
			   	}else if(opMenu==4){
					return 0;
				}
		
				cout<<"\n\n";
				cout<<"\t\t\tDesea regresar al menu principal? ingrese (S) para regresar: "<<endl;
				cout<<"\t\t\t";
				cin>>resp;
				system("cls");
			}while(resp!='S');
			return main();
	   	break;
	
	   	case 2:
	    	do{
		   		cout<<"\n\n\n\n";
			   	cout<<"\t\t\t---Seleccione una opcion: "<<endl;
			   	cout<<"\t\t\t1. Anuncios."<<endl;
			   	cout<<"\t\t\t2. Ver Residentes Registrados."<<endl;
			   	cout<<"\t\t\t3. Marcar la Entrada de Visita."<<endl;
			   	cout<<"\t\t\t4. Eliminar Anuncio."<<endl;
		    	cout<<"\t\t\t";
			   	cin>>opMenu;
			    	
		    	if(opMenu==1){
		        
			       	Anuncio anu = Anuncio();
		        	anu.leerAnuncio();
			       	getch();
			       
			   	}else if(opMenu==2){
		        	leerResidentes();
		    	}else if(opMenu==3){
		    		Anuncio anu = Anuncio();
		        	anu.leerAnuncio();
		    		cout<<"\t\t\tIngrese el numero de anuncio de la persona a ingresar: ";
		    		cin>>numero;
		    		int hour = hora(), min = mins();
					string day = dia();
		    		Anuncio anuE = Anuncio(numero, day, hour, min);
		        	anuE.marcarEntrada();
		    	}else if(opMenu==4){
		    		cout<<"\t\t\tIngrese el numero de anuncio que desea eliminar: "<<endl;
					cout<<"\t\t\t";
					cin>>numero;
					Anuncio anu = Anuncio(numero);
		    		anu.eliminarAnuncio();
				}else{
					cout<<"\t\t\tIngrese una opcion valida!"<<endl;
				}
		    	
		    	cout<<"\t\t\tDesea regresar al menu principal? ingrese (S) para regresar: "<<endl;
		    	cout<<"\t\t\t";
				cin>>resp;
				system("cls");
	    	}while(resp!='S');
	    	return main();
	   	break;
    
    	case 3:
	    	do{
	    		cout<<"\n\n\n\n";
		    	cout<<"\t\t\t---Seleccione una opcion---"<<endl;
		    	cout<<"\t\t\t1. Ver registro de anunciados."<<endl;
		    	cout<<"\t\t\t2. Ver datos de residentes."<<endl;
		    	cout<<"\t\t\t3. Ver datos de guardias."<<endl;
		    	cout<<"\t\t\t4. Crear Usuario para Guardia."<<endl;
		    	cout<<"\t\t\t5. Eliminar Anuncios."<<endl;
		    	cout<<"\t\t\t";
		    	cin>>opMenu;
		    	if(opMenu==1){
		    		Anuncio anu = Anuncio();
		        	anu.leerAnuncio();
				}else if(opMenu==2){
					leerResidentes();
				}else if(opMenu==3){
					leerGuardias();
				}else if(opMenu==4){
		    		cout<<"\t\t\t-----------------------------"<<endl;
					cout<<"\t\t\t----Crear Usuario Guardia----"<<endl;
					cout<<"\t\t\t-----------------------------"<<endl;
		        	cout<<"\t\t\tIngrese su usuario: "<<endl;
		        	cout<<"\t\t\t";
		        	cin>>user;
		        	cout<<"\t\t\tIngrese su contrasenia: "<<endl;
		        	cout<<"\t\t\t";
		        	cin>>password;
		        	cout<<"\t\t\tIngrese su primer nombre y primer apellido: "<<endl;
		        	cout<<"\t\t\t";
	    			cin.ignore();
	    			getline(cin,nombre);
	    			cout<<"\t\t\tIngrese su numero: "<<endl;
	    			cout<<"\t\t\t";
	    			cin>>numero;
		        	Login log = Login(user, password, nombre, numero);
		        	log.crearUserGuard();
		        	cout<<"\t\t\tUsuario creado correctamente!!"<<endl;
		        	getch();
		        	system("cls");
		        	return main();
				}else if(opMenu==5){
				cout<<"\t\t\tIngrese el numero de anuncio que desea eliminar: "<<endl;
				cout<<"\t\t\t";
				cin>>numero;
				Anuncio anu = Anuncio(numero);
		    	anu.eliminarAnuncio();
				}else{
					cout<<"Ingrese una opcion de la lista!"<<endl;
				}
				cout<<"\t\t\tDesea regresar al menu principal? ingrese (S) para regresar: "<<endl;
				cout<<"\t\t\t";
				cin>>resp;
				system("cls");
			}while(resp!='S');
			return main();
    	break;
    	
    	default:
    	cout<<"\t\t\tLa opcion ingresada no es valida!!"<<endl;
    	break;
    }
	return 0;
}
