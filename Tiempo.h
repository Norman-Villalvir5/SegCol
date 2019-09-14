#include <ctime>

using namespace std;

string dia(){
	string dia;
	string diaSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
	time_t now = time(0);
	
	tm *time = localtime(&now);
	dia = diaSemana[time->tm_wday];
	
	return dia;
}

string mes(){
	string mes;
	string numeroMes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Noviembre", "Diciembre"};
	time_t now = time(0);
	
	tm *time = localtime(&now);
	mes = numeroMes[time->tm_mon];
	
	return mes;
}

int hora(){
	int hora;
	time_t now = time(0);
	
	tm *time = localtime(&now);
	hora = time->tm_hour;
	
	return hora;
}

int mins(){
	int mins;
	
	time_t now = time(0);
	
	tm *time = localtime(&now);
	mins = time->tm_min;
	
	return mins;
}
