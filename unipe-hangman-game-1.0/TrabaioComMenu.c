#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

void menu(void);
void creditos(void);
void menujogar(void);
void agradecimento(void);
void jogaraleatorio(void);
void rank(void);
void cadastrar(void);
void dificuldades(void);
void dificil(void);
void medio(void);
void facil(void);
void jogarcadastro(void);


int main(int argc, char** argv)
{
	fflush(stdin);
    menu();
    fflush(stdin);
}

void menu(){
	
	system("@cls||clear");
	int sel;
	setlocale(LC_ALL, "Portuguese");
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	printf("|------BEM VINDO AO JOGO DA FORCA-------|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|----------------MENU-------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|----DIGITE O NUMERO PARA SELECIONAR----|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|                                       |\n");
	printf("| 1: JOGAR                              |\n");
	printf("| 2: VER RANKING                        |\n");
	printf("| 3: CADASTRAR PALAVRAS                 |\n");
	printf("| 4: CREDITOS                           |\n");
	printf("| 5: SAIR                               |\n");
	printf("|_______________________________________|\n");
	fflush(stdin);
	scanf("%d", &sel);
	
	switch(sel){
		case 1: menujogar();
		case 2: rank();
		case 3: cadastrar();
		case 4: creditos();
		case 5: agradecimento;	
}
}

void menujogar(){
	
	int sel;
	system("@cls||clear"); 
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	printf("|-------COMO GOSTARIA DE JOGAR?---------|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|----------------MENU-------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|----DIGITE O NUMERO PARA SELECIONAR----|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|                                       |\n");
	printf("| 1: PALAVRAS ALEATÓRIAS                |\n");
	printf("| 2: POR DIFICULDADE                    |\n");
	printf("| 3: USAR PALAVRAS CADASTRADAS          |\n");
	printf("| 4: VOLTAR PARA O MENU                 |\n");
	printf("|_______________________________________|\n");
	fflush(stdin);
	scanf("%d", &sel);
	
	switch(sel){
		case 1: jogaraleatorio();
		case 2: dificuldades();
		case 3: jogarcadastro();
		case 4: menu();
	}
	
}

void dificuldades(){
	
	int sel;
	system("@cls||clear"); 
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	printf("|--QUAL DIFICULDADE GOSTARIA DE JOGAR?--|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|----DIGITE O NUMERO PARA SELECIONAR----|\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|                                       |\n");
	printf("| 1: DIFICIL                            |\n");
	printf("| 2: MEDIO                              |\n");
	printf("| 3: FACIL                              |\n");
	printf("| 4: VOLTAR PARA O MENU                 |\n");
	printf("|_______________________________________|\n");
	fflush(stdin);
	scanf("%d", &sel);
	
	switch(sel){
		case 1: dificil();
		case 2: medio();
		case 3: facil();
		case 4: menu();	
	}
	
}

void dificil(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	system("@cls||clear");
	static char words[540000][25];
    FILE *file;
    
    int i, j;
    size_t cnt, n;
    char word[25];

    srand(time(NULL));
    file = fopen("dificil.txt", "r");
    cnt = 0;
    while(1==fscanf(file, "%24s", word)){
        if(cnt == 540000)
            break;
        strcpy(words[cnt++], word);
    }
    fclose(file);
    n = cnt;
    if(n > RAND_MAX){
        int part;
        size_t random = 0;
        i = n / RAND_MAX;
        part = rand() % (i+1);
        if(part == i){
            j = n % RAND_MAX;
            if(j != 0)
                random = random + RAND_MAX*part + rand() % j;
            else
                random = random + RAND_MAX*(part-1) + rand();
        } else {
            random = random + RAND_MAX*part + rand();
        }
        
    } else {
        int random = rand() % n;
        
    }
    int random = rand() % n;
    FILE *rank;
    int sel;
	char usrname[3];
	
	
	// index de palavra aleatória 
	int randomIndex = rand() %6;

	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	

	int wordlength = strlen(words[random]);
	int advinha[8] = {0,0,0,0,0,0,0,0};

	int quit = 0;


	int loopIndex = 0;  
	char usradv[16]; 
	char palavraadv;



		//Loop de jogo
		while (numCorrect < wordlength)
		{
			fflush(stdin);
			
			printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
			printf("|------------JOGO DA FORCA--------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|______________");
			
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					
					printf("%c",words[random][loopIndex]);
				}
				else
				{
					printf("-");
				}



			}




			
			printf("____________________|");
			printf("\n|                                       |\n");
			printf("|       DIGITE 'quit' PARA SAIR         |\n");
			printf("|_______________________________________|\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			fflush(stdin);
			system("@cls||clear"); 
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}

			palavraadv = usradv[0];
			printf("%c", palavraadv);

			oldCorrect = numCorrect; 

			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == words[random][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}


			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("\nParabens voce acertou!\n");
			}
		}//loop while


	if(quit == 1)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------O USARIO DESISTIU-----------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
	else if(vidasnum == 0)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ PERDEU--------------|\n");
		printf("|-------------A PALAVRA ERA-------------|\n");
		printf("|               %s             |\n", words[random]);
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		scanf("%d",&sel);
		fflush(stdin);
		switch(sel){
			case 1: menu();
		}
		
		
		
		
	}
	else
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|        DIGITE SEU NOME(3 LETRAS)      |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(usrname);
		rank = fopen("ranking.txt","a+");
		fputs(usrname,rank);
		fputs("\n",rank);
		fclose(rank);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           RANKING CADASTRADO          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
}

void medio(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	system("@cls||clear");
	static char words[540000][25];
    FILE *file;
    
    int i, j;
    size_t cnt, n;
    char word[25];

    srand(time(NULL));
    file = fopen("medio.txt", "r");
    cnt = 0;
    while(1==fscanf(file, "%24s", word)){
        if(cnt == 540000)
            break;
        strcpy(words[cnt++], word);
    }
    fclose(file);
    n = cnt;
    if(n > RAND_MAX){
        int part;
        size_t random = 0;
        i = n / RAND_MAX;
        part = rand() % (i+1);
        if(part == i){
            j = n % RAND_MAX;
            if(j != 0)
                random = random + RAND_MAX*part + rand() % j;
            else
                random = random + RAND_MAX*(part-1) + rand();
        } else {
            random = random + RAND_MAX*part + rand();
        }
        
    } else {
        int random = rand() % n;
        
    }
    int random = rand() % n;
    FILE *rank;
    int sel;
	char usrname[3];
	
	
	// index de palavra aleatória 
	int randomIndex = rand() %6;

	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	

	int wordlength = strlen(words[random]);
	int advinha[8] = {0,0,0,0,0,0,0,0};

	int quit = 0;


	int loopIndex = 0;  
	char usradv[16]; 
	char palavraadv;



		//Loop de jogo
		while (numCorrect < wordlength)
		{
			fflush(stdin);
			//printf("guesswords: %s randomIndex: %d tamanhopalavra: %d\n", words[random], randomIndex, wordlength);
			printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
			printf("|------------JOGO DA FORCA--------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|______________");
			
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					
					printf("%c",words[random][loopIndex]);
				}
				else
				{
					printf("-");
				}



			}




			
			printf("____________________|");
			printf("\n|                                       |\n");
			printf("|       DIGITE 'quit' PARA SAIR         |\n");
			printf("|_______________________________________|\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			fflush(stdin);
			system("@cls||clear"); 
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}

			palavraadv = usradv[0];
			printf("%c", palavraadv);

			oldCorrect = numCorrect; 

			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == words[random][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}


			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("\nParabens voce acertou!\n");
			}
		}//loop while


	if(quit == 1)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------O USARIO DESISTIU-----------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
	else if(vidasnum == 0)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ PERDEU--------------|\n");
		printf("|-------------A PALAVRA ERA-------------|\n");
		printf("|               %s             |\n", words[random]);
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
		
		
		
		
	}
	else
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|        DIGITE SEU NOME(3 LETRAS)      |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(usrname);
		rank = fopen("ranking.txt","a+");
		fputs(usrname,rank);
		fputs("\n",rank);
		fclose(rank);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           RANKING CADASTRADO          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
}

void facil(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	system("@cls||clear");
	static char words[540000][25];
    FILE *file;
    
    int i, j;
    size_t cnt, n;
    char word[25];

    srand(time(NULL));
    file = fopen("facil.txt", "r");
    cnt = 0;
    while(1==fscanf(file, "%24s", word)){
        if(cnt == 540000)
            break;
        strcpy(words[cnt++], word);
    }
    fclose(file);
    n = cnt;
    if(n > RAND_MAX){
        int part;
        size_t random = 0;
        i = n / RAND_MAX;
        part = rand() % (i+1);
        if(part == i){
            j = n % RAND_MAX;
            if(j != 0)
                random = random + RAND_MAX*part + rand() % j;
            else
                random = random + RAND_MAX*(part-1) + rand();
        } else {
            random = random + RAND_MAX*part + rand();
        }
        
    } else {
        int random = rand() % n;
        
    }
    int random = rand() % n;
    FILE *rank;
    int sel;
	char usrname[3];
	
	
	// index de palavra aleatória 
	int randomIndex = rand() %6;

	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	

	int wordlength = strlen(words[random]);
	int advinha[8] = {0,0,0,0,0,0,0,0};

	int quit = 0;


	int loopIndex = 0;  
	char usradv[16]; 
	char palavraadv;



		//Loop de jogo
		while (numCorrect < wordlength)
		{
			fflush(stdin);
			//printf("guesswords: %s randomIndex: %d tamanhopalavra: %d\n", words[random], randomIndex, wordlength);
			printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
			printf("|------------JOGO DA FORCA--------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|______________");
			
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					
					printf("%c",words[random][loopIndex]);
				}
				else
				{
					printf("-");
				}



			}




			
			printf("____________________|");
			printf("\n|                                       |\n");
			printf("|       DIGITE 'quit' PARA SAIR         |\n");
			printf("|_______________________________________|\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			fflush(stdin);
			system("@cls||clear"); 
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}

			palavraadv = usradv[0];
			printf("%c", palavraadv);

			oldCorrect = numCorrect; 

			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == words[random][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}


			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("\nParabens voce acertou!\n");
			}
		}//loop while


	if(quit == 1)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------O USARIO DESISTIU-----------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
	else if(vidasnum == 0)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ PERDEU--------------|\n");
		printf("|-------------A PALAVRA ERA-------------|\n");
		printf("|               %s             |\n", words[random]);
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
		
		
		
		
	}
	else
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|        DIGITE SEU NOME(3 LETRAS)      |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(usrname);
		rank = fopen("ranking.txt","a+");
		fputs(usrname,rank);
		fputs("\n",rank);
		fclose(rank);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           RANKING CADASTRADO          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
}

void jogarcadastro(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	system("@cls||clear");
	static char words[540000][25];
    FILE *file;
    
    int i, j;
    size_t cnt, n;
    char word[25];

    srand(time(NULL));
    file = fopen("cadastrar.txt", "r");
    cnt = 0;
    while(1==fscanf(file, "%24s", word)){
        if(cnt == 540000)
            break;
        strcpy(words[cnt++], word);
    }
    fclose(file);
    n = cnt;
    if(n > RAND_MAX){
        int part;
        size_t random = 0;
        i = n / RAND_MAX;
        part = rand() % (i+1);
        if(part == i){
            j = n % RAND_MAX;
            if(j != 0)
                random = random + RAND_MAX*part + rand() % j;
            else
                random = random + RAND_MAX*(part-1) + rand();
        } else {
            random = random + RAND_MAX*part + rand();
        }
        
    } else {
        int random = rand() % n;
        
    }
    int random = rand() % n;
    FILE *rank;
    int sel;
	char usrname[3];
	
	
	// index de palavra aleatória 
	int randomIndex = rand() %6;

	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	

	int wordlength = strlen(words[random]);
	int advinha[8] = {0,0,0,0,0,0,0,0};

	int quit = 0;


	int loopIndex = 0;  
	char usradv[16]; 
	char palavraadv;



		//Loop de jogo
		while (numCorrect < wordlength)
		{
			fflush(stdin);
			//printf("guesswords: %s randomIndex: %d tamanhopalavra: %d\n", words[random], randomIndex, wordlength);
			printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
			printf("|------------JOGO DA FORCA--------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|______________");
			
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					
					printf("%c",words[random][loopIndex]);
				}
				else
				{
					printf("-");
				}



			}




			
			printf("____________________|");
			printf("\n|                                       |\n");
			printf("|       DIGITE 'quit' PARA SAIR         |\n");
			printf("|_______________________________________|\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			fflush(stdin);
			system("@cls||clear"); 
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}

			palavraadv = usradv[0];
			printf("%c", palavraadv);

			oldCorrect = numCorrect; 

			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == words[random][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}


			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("\nParabens voce acertou!\n");
			}
		}//loop while


	if(quit == 1)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------O USARIO DESISTIU-----------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
	else if(vidasnum == 0)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ PERDEU--------------|\n");
		printf("|-------------A PALAVRA ERA-------------|\n");
		printf("|               %s             |\n", words[random]);
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
		
		
		
		
	}
	else
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|        DIGITE SEU NOME(3 LETRAS)      |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(usrname);
		rank = fopen("ranking.txt","a+");
		fputs(usrname,rank);
		fputs("\n",rank);
		fclose(rank);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           RANKING CADASTRADO          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
}

void jogaraleatorio(){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	system("@cls||clear");
	 
	char guesswords[][16] = 
	{
		"green",
		"yellow",
		"purple",
		"windows",
		"linux",
		"apple"



	};
	
	FILE *rank;
	int sel;
	char usrname[3];
	
	
	// index de palavra aleatória 
	int randomIndex = rand() %6;

	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	

	int wordlength = strlen(guesswords[randomIndex]);
	int advinha[8] = {0,0,0,0,0,0,0,0};

	int quit = 0;


	int loopIndex = 0;  
	char usradv[16]; 
	char palavraadv;



		//Loop de jogo
		while (numCorrect < wordlength)
		{
			fflush(stdin);
			//printf("guesswords: %s randomIndex: %d tamanhopalavra: %d\n", guesswords[randomIndex], randomIndex, wordlength);
			printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
			printf("|------------JOGO DA FORCA--------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|---------------------------------------|\n");
			printf("|______________");
			
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					
					printf("%c",guesswords[randomIndex][loopIndex]);
				}
				else
				{
					printf("-");
				}



			}




			
			printf("____________________|");
			printf("\n|                                       |\n");
			printf("|       DIGITE 'quit' PARA SAIR         |\n");
			printf("|_______________________________________|\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			fflush(stdin);
			system("@cls||clear"); 
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}

			palavraadv = usradv[0];
			printf("%c", palavraadv);

			oldCorrect = numCorrect; 

			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == guesswords[randomIndex][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}


			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("\nParabens voce acertou!\n");
			}
		}//loop while


	if(quit == 1)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------O USARIO DESISTIU-----------|\n");
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		scanf("%d",&sel);
		fflush(stdin);
		switch(sel){
			case 1: menu();
		}
	}
	else if(vidasnum == 0)
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ PERDEU--------------|\n");
		printf("|-------------A PALAVRA ERA-------------|\n");
		printf("|                  %s             |\n", guesswords[randomIndex]);
		printf("|                                       |\n");
		printf("|           OBRIGADO POR JOGAR          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
		
		
		
		
	}
	else
	{
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|          OBRIGADOR POR JOGAR          |\n");
		printf("|        DIGITE SEU NOME(3 LETRAS)      |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(usrname);
		rank = fopen("ranking.txt","a+");
		fputs(usrname,rank);
		fputs("\n",rank);
		fclose(rank);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|--------------VOCÊ GANHOU--------------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           RANKING CADASTRADO          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}
	}
}

void rank(){
	int sel;
	FILE *rank;
	char *ranks[50];
	rank = fopen("ranking.txt","r");
	system("@cls||clear");
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯RANKS¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	while (fscanf(rank,"%s",ranks) == 1){
	
    	printf("|                  %s                  |\n", ranks);
	}
	fclose(rank);
	printf("|           OBRIGADO POR JOGAR          |\n");
	printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
	printf("|_______________________________________|\n");
	fflush(stdin);
	scanf("%d",&sel);
	switch(sel){
	case 1: menu();
		}
}

void cadastrar(){

	FILE *cadastro;
	int sel;
	char pala[50];
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|------------CADASTRAR PALVRAS----------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|             DIGITE A PALAVRA          |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		gets(pala);
		cadastro = fopen("cadastrar.txt","a+");
		fputs(pala,cadastro);
		fputs("\n",cadastro);
		fclose(cadastro);
		system("@cls||clear");
		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
		printf("|-----------CADASTRAR PALAVRAS----------|\n");
		printf("|---------------------------------------|\n");
		printf("|                                       |\n");
		printf("|           PALAVRA CADASTRADA          |\n");
		printf("|      DIGITE 1 PARA VOLTAR AO MENU     |\n");
		printf("|_______________________________________|\n");
		fflush(stdin);
		scanf("%d",&sel);
		switch(sel){
			case 1: menu();
		}

}

void agradecimento(){
	system("@cls||clear");
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	printf("|-----------------SAIR------------------|\n");
	printf("|---------------------------------------|\n");
	printf("|                                       |\n");
	printf("|           OBRIGADO POR JOGAR          |\n");
	printf("|_______________________________________|\n");
}

void creditos(){
	int sel;
	system("@cls||clear");
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	printf("|--------------CRÉDITOS-----------------|\n");
	printf("|---------------------------------------|\n");
	printf("|                                       |\n");
	printf("|         JOSÉ GABRIEL GOUVEIA          |\n");
	printf("|           LUCAS GONÇALVES             |\n");
	printf("|           VINICIUS SOBRAL             |\n");
	printf("|           MÁRIO FERREIRA              |\n");
	printf("|                                       |\n");
	printf("|        1: VOLTAR PARA O MENU          |\n");
	printf("|        2: ENCERRAR O JOGO             |\n");
	printf("|_______________________________________|\n");
	fflush(stdin);
	scanf("%d", &sel);
	
	switch(sel){
		case 1: menu();
		case 2: agradecimento();
	}
	
}
