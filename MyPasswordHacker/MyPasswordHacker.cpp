// MyPasswordHacker.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "ctime"
#include "string"

using namespace std;

bool find_password();
string find_password_rec(string, int);
int numberOfSymbols;
string generatedPasword;

int _tmain(int argc, _TCHAR* argv[])
{
	double startTime = clock();
	setlocale(LC_ALL, "Russian");
	ifstream fileWithPassword("D:\\Password.txt");
	getline(fileWithPassword, generatedPasword);
	if(find_password())
		cout << "Success! - " << generatedPasword << endl << endl;
	double endTime = clock();
	cout << (endTime - startTime)/1000 << endl << endl;
	system("pause");
	return 0;
}

bool find_password(){
	int mas[7] = {1, 2, 3, 4, 6, 8, 10};
	for(int n = 0; n < 7; n++){
		string inputPassword = "";
		for(int i = 0; i < mas[n]; i++){
			inputPassword = inputPassword + "а";
		}
		numberOfSymbols = mas[n];
		if(find_password_rec(inputPassword, 1) == generatedPasword){
			return true;
		}
	}
	return false;
}

string find_password_rec(string curentPassword, int currentNumberOfSymbols){
	for(int currentSymbol = -32; currentSymbol <= -1; currentSymbol++){
		curentPassword[currentNumberOfSymbols - 1] = (char)currentSymbol;
		if(currentNumberOfSymbols < numberOfSymbols)
			curentPassword = find_password_rec(curentPassword, currentNumberOfSymbols+1);
		if(curentPassword == generatedPasword)
			return curentPassword;
	}
	return curentPassword;
}
