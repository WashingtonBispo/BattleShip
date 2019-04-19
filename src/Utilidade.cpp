#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void gotoxy(int x, int y){

	printf("%c[%d;%df",0x1B ,y,x);

	return;
}



void Preencher(){
	string bloco="\u2588";
	gotoxy(1,3);
	for(int x=0;x<13;x++){
		cout << "\u2551";
		for(int y=0;y<13;y++)
	    		cout << " S \u2551";
		cout << endl << endl;

		}

return ;
}


void Faz_Retangulo(int x, int y){
	gotoxy(1,2);
		cout << "\u2554";
		for(int i=0;i<x;i++)
			cout << "\u2550";
		cout << "\u2557" << endl;

		for(int i=0;i<y;i++){
			cout << "\u2551";
			gotoxy(x+2,3+i);
			cout << "\u2551" << endl;
		}

		cout << "\u255A";

		for(int i=0;i<x;i++)
                        cout << "\u2550";
		cout << "\u255D";
return ;
}


void Menu(){

	gotoxy(8,5);
	cout << "BATALHA" << endl << "        NAVAL"<<  "\n\n    MORRA  INSETO";
	gotoxy(5,11);
        cout << "--> Jogar\n";
        cout << "        Comandos\n";
        cout << "\n\n\n	KONAMI";
	gotoxy(1,1);
	Faz_Retangulo(19,15);
        gotoxy(30,30);

return;
}

int Escolhe_Menu(){
	char c;
	int n=5;
	while (c!='f'){
      		c=getchar();
		  gotoxy(5,n+6);
		  cout << "   ";
		  if(c=='w' || c=='W')
			n--;
                  if(c=='S' || c=='s')
                       n++;
		  if(n>25)
			n--;
		  if(n<5)
			  n++;
		  gotoxy(5,6+n);
		  cout << "-->";
		 
		 
	//INICIO PIADA	 
		  if(n==16)
                          cout << "EI SETINHA ISSO NAO VALE";
		  if(n==1)
                          cout << "VOLTA AQUI AGORA";
		if(n==18)
                          cout << "VOCE NAO VAI ENCONTAR NADA AI";
		if(n==19)
                          cout << "DESISTO DE VOCE";


		if(n==25)
			  cout << "EASTER EGG";
		  
	//FIM PIADA		
		gotoxy(30,30);

	}
return n;

}
