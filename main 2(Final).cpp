#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

char mat[25][25],t;                                   
int i,l,c,p=0,ccx,ccy,y,cont=0,movimento = 0,z=0,s=0,o=0,e=0,pp=0,ss=0,x=2,bot=0,h=0,ee=0,tt=0,sss=0,x1=2,oo=0,qq=0,qq2=0,kk=0;

void movimentacao();
void personagem();
void mapa()	;
void imprime();
void menu();

void fase0();

struct Coordenada
{
    int x;
    int y;
};

struct Hero
{
    int vida;   // <-- Quantidade de dano que pode receber antes de morrer
    char nome[20];
    int fase;
    bool bot;
    
    //PARA RODAR O RPG
    int dano;   // <--- d12 (1 e 12);
    int defesa; // <--- d6  (1 e  6);
    int pv;   // <-- Quantidade de dado que pode receber antes de morrer no rpg
    
	Coordenada posicao; // <-- Posição do heroi no tabuleiro
};

struct Vilan
{
    int dano;
    int defesa;
    int pv;
    
	Coordenada posicao;
};

void cord(Hero& obj){
	
cout << "Digite as coordenadas (x, y) do herói: \n";
    cin >> obj.posicao.x >> obj.posicao.y;	
	
}



void Criar(Hero& obj)
{
    cout << "\nBem vindo a criação do personagem\n";
    cout << "Digite o nome do herói: ";
   cin >> obj.nome; 
    
    //cout << "Digite as coordenadas (x, y) do herói: \n";
    //cin >> obj.posicao.x >> obj.posicao.y;
    obj.posicao.x=1;
	obj.posicao.y=1;
    
    obj.vida = 3; // define o n de vidas
    obj.fase = 1;
    system("clear || cls");
}

void Combate(Hero x, Vilan& y)
{
	x.dano = 5;
	x.defesa = 5;

	y.dano = 3;
	y.defesa = 5;
	
    int dado = rand()%6 + 1;   // Gerando um valor aleatório entre 1 e 6 ('jogada )de um dado de 12 lados
    int danoTotal = dado + x.dano;  // Valor do dado mais o dano do hero

	cout << "\nCOMBATE- Seu turno: \n";
	cout << "\nVocê ataca!\n";
    cout << "_____\n";
    
	cout << "\tDano: " << danoTotal << "\n";
    cout << "\tVecna levantou o seu escudo...\n";
    
	cout << "\tO dano total foi de " << danoTotal - y.defesa << "\n";   // Dano reduzido por causa da defesa do vilÃ£o
    y.pv -= danoTotal - y.defesa; // Subtraindo a vida pelo dano causado
    cout << "\Vecna tem " << y.pv << " pontos de vida\n";
    
	cout << "_____\n";
    
}

void Combate(Vilan y, Hero& x)
{
	x.dano = 5;
	x.defesa = 5;
	
	y.dano = 3;
	y.defesa = 5;
	
    int dado = rand()%6 + 1;
    int danoTotal = dado + y.dano;  // Valor do dado mais o dano do vilÃ£o
    
	cout << "\nCOMBATE- Turno oponente:\n";
	cout << "\nVecna ataca!\n";
    cout << "_____\n";
    
	cout << "\tDano: " << danoTotal << "\n";
    cout << "\t" << x.nome << " levantou o escudo...\n";
    
	cout << "\tO dano total foi de " << danoTotal - x.defesa << "\n";
    x.pv -= danoTotal - x.defesa; 
    cout << "\tSeu heroi tem " << x.pv << " pontos de vida\n";
    
	cout << "_____\n";
    
}

void RPG()
{
	srand(time(NULL));
	
	Hero heroi;
	Vilan vilao;
	
	vilao.pv = 20;
	heroi.pv = 50;
	
	char escolha;
	char lixo;
	
	
        cout << "\nUm ser repugnante está guardando o portal!\n";	
	 	cout << "\nDerrote o vilão para completar a fase!\n";
	 	
	 	while(true)//<-- rodada de rpg
		 {
		 	cout << "a: atacar\td: defender\n";
	 	    escolha = getche();
	 	
	 	if(heroi.pv <= 0 || vilao.pv <= 0)
		{
		   break;	
		}
		
		 
		 else
		 { 
		   if(escolha == 'a')
		   {
			   Combate(heroi, vilao);
			   cout << "Vez de Vecna!\n";	
			  // Combate(vilao, heroi);
			   
			   system("pause");
			   system("clear || cls");
	   	   }
	   	   
	   	   else if(escolha == 'd')
	   	   {
			  Combate(vilao, heroi);
			 // cout << "Sua vez!\n";
			 // Combate(heroi, vilao);
			  
			   system("pause");	
			   system("clear || cls");
           }
			  
	    	  else
			  {
			  	cout << "COMANDO INVALIDO\n";
			  	cout << "Perdeu sua vez";
			  }
		 }
		 
		 
		 Combate(vilao, heroi);
		 
		 }
	 	
	 	if(heroi.pv > vilao.pv)
		 {
		 	cout << "\tVITÓRIA!\n Com um último golpe, você derruba o oponente!\n";
		 	cout << "E passa com alegria pelo portal!\n";
		 //	cout << "Para vencer a última fase, passe pelo portal!";
		 //	cout << "\n";
		    qq2=1;
			sss=1;
		 	kk=1;
		 	heroi.fase = 3;
		 	system("pause");
			 system("cls");	
		 }
		 
		 else
		 {
		 	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
		 	cout << "\tDERROTA!\n Com um último golpe, o oponte vence a luta";
		 	cout << "\n";
		 	
		 	system("pause");
			 system("cls");	
		 }
}

void Status(Hero obj)
{
    
    cout << "Seu heroi ficou com os seguintes status:\n";
    cout << "##########################################\n";
    cout << "\tNome: " << obj.nome << "\n";
    cout << "\tVida: " << obj.vida << "\n";
    cout << "##########################################\n";
    
	system("pause");
	system("clear || cls");
    
}

void Sla()
{
	string a = "\t+++   +++  ++++  +++  ++  ++  ++\n";
	string b = "\t++++ ++++  ++    ++++ ++  ++  ++\n";
	string c = "\t++ +++ ++  ++++  ++ ++++  ++  ++\n";
	string d = "\t++     ++  ++    ++  +++  ++  ++\n";
	string f = "\t++     ++  ++++  ++   ++  ++++++\n";
	
	string h = "\t______\n";
	
	cout << h;
	cout << a << b << c << d << f;
	cout << h;
}

void Tutorial()
{	
	cout<<"\n----------------------------------------------++++-----------------------------------------------------------";
	cout<<"\n\n\t O jogo é do estilo aventura/puzzle onde o objetivo é o \n";
	cout<<"\t passar de três fases. Em cada fase o jogador deve se\n";
	cout<<"\t movimentar para pegar uma chave para abrir a porta fechada.\n\n";
	cout<<"\t O jogador possui os seguintes comandos:";
	cout<<"\n O: Simbolo que representa o botao(abre passagens secretas)";
	cout<<"\n W: O jogador movimenta uma unidade para cima.";
	cout<<"\n A: O jogador movimenta uma unidade para a esquerda.";
	cout<<"\n S: O jogador movimenta uma unidade para baixo.";
	cout<<"\n D: O jogador movimenta uma unidade para direita.";
	cout<<"\n I: O jogador interage com o objeto que ele estiver em cima.";
	cout<<"\n\n &: Simbolo que representa o jogador.";
	cout<<"\n *: Simbolo que representa uma parede, o jogador nao pode passar pela parede.";
	cout<<"\n @: Simbolo que representa a chave para abrir a porta para finalizar a fase,\n";
	cout<<" a porta abre no momento em que o jogador interage com a chave.";
	cout<<"\n D: Simbolo que representa uma porta fechada.";
	cout<<"\n =: Simbolo que representa uma porta que foi aberta quando o jogador interagiu com a chave.";
	cout<<"\n #: Simbolo que representa um espinho(tira uma vida).";
	cout<<"\n >: simbolo que representa um teletransporte.O teletransporte sempre deve\n";
	cout<<" vir em par, quando o jogador toca em um ele e transportado para outro e vice-versa.\n";
	cout<<" $: O guardião do portal, jogue uma rodada e derrote o oponente para passar pelo portal\n";
	cout<<" e vencer o jogo.";
	cout<<"\n\n\t O JOGADOR POSSUI UM TOTAL DE 3 VIDAS, SE PERDER TODAS AS VIDAS O JOGO VOLTA PARA O MENU INICIAL.";
	cout<<"\n\n----------------------------------------------++++-----------------------------------------------------------";

	
}

void Menu()
{
	system("cls");
	Sla();

	cout << "\t  BEM VINDO AO MENU PRINCIPAL!\n";
	cout << "\t1- Jogar\n\t2- Tutorial\n\t3- Sair\n";
	cout << "\tEscolha para continuar: ";
}

void Matriz50(int x, int y)
{
	char matriz[50][50];
	int l,c,r=1;  //l = linha, c = coluna.
	int i,j,m=3;
	bool v;
	
	for(l=0;l!=1;l++)
	{
	 for(c=0;c!=50;c++)              // parte de cima
	 {
      matriz[l][c]='*';     
	 }		
	}
	
	for(c=0;c!=1;c++)
	{                              //lateral esquerda
	 for(l=0;l!=50;l++)
	 {
      matriz[l][c]='*';
	 }
	}
	
	for(l=1;l!=49;l++)
	{
	 for(c=1;c!=49;c++)             //meio
	 {
      matriz[l][c]=' ';
	 }		
	}
		
		for(l=1;l!=40;l++)
	{
		matriz[l][4]='#';                   //desenho1
	
	 }
	 
	 	for(l=1;l!=39;l++)
	{
		matriz[l][5]='#';                   //desenho2
	
	 }
	   	
     	for(l=8;l!=49;l++)
	{
		matriz[l][8]='#';                   //desenho3
	
	 }
		
		for(c=8;c!=37;c++)
	{
		matriz[8][c]='#';                   //desenho3 coluna
	
	 }
	
	 	for(l=8;l!=39;l++)
	{
		matriz[l][37]='#';                   //desenho3
	
	 }
	
		for(c=15;c!=38;c++)
	{
		matriz[38][c]='#';                   //desenho3 coluna
	
	 }
	
	 	for(l=13;l!=39;l++)
	{
		matriz[l][14]='#';                   //desenho3
	
	 }
	 
	 for(c=14;c!=29;c++)
	{
		matriz[13][c]='#';                   //desenho3 coluna
	
	 }
		
		for(l=1;l!=43;l++)
	{
		matriz[l][41]='#';                   //desenho
	
	 }
	 
	 	for(l=20;l!=49;l++)
	{
		matriz[l][44]='#';                   //desenho
	
	 }
	   	
     	for(l=20;l!=49;l++)
	{
		matriz[l][45]='#';                   //desenho
	
	 }
	   	for(l=20;l!=49;l++)
	{
		matriz[l][46]='#';                   //desenho
	
	 }
	
		for(c=11;c!=42;c++)
	{
		matriz[43][c]='#';                   //desenho3 coluna
	
	 }
     	
	for(l=11;l!=43;l++)
	{
		matriz[l][11]='#';                   //desenho3
	
	 }

    	for(c=11;c!=33;c++)
	{
		matriz[11][c]='#';                   //desenho3 coluna
	
	 }
	 
	 	for(l=11;l!=27;l++)
	{
		matriz[l][33]='#';                   //desenho
	
	 }
	 
	 matriz[48][7]='O'; 
   if(matriz[x][y] == 'O')
        {
        	pp=1;
   }   
	 
	 if(pp!=1){
	 
	 	for(c=47;c!=49;c++)
	{
		matriz[20][c]='#';                   //passagem
	
	 }
	 for(c=47;c!=49;c++)
	{
		matriz[21][c]='#';                   //passagem
	
	 }
    }else{
    		for(c=47;c!=49;c++)
	{
		matriz[20][c]=' ';                   //passagem
	
	 }
	 for(c=47;c!=49;c++)
	{
		matriz[21][c]=' ';                   //passagem
	
	 }
    	
    	
	}
	 
	 	


  for(c=49;c!=50;c++)
	{                
	 for(l=0;l!=50;l++)
	 {
      matriz[l][c]='*';
	 }    
	                           
	}
	
	for(l=49;l!=50;l++)
	{
	 for(c=0;c!=50;c++)
	 {
      matriz[l][c]='*' ;           
	 }	
	 	
	}
	
	if(o!=1){
		matriz[48][49] = 'D';
	}else{
		matriz[48][49] = '=';
		
	}

   if(	matriz[x][y] == '#')
      {
        s=1;
   }
  
   
	matriz[25][25]='@';      
	
        if(	matriz[x][y] == '@')
        {
        	char esc;
        	cout<<"\nVoce achou o botao pressione i para usar\n";
        	cin>>esc;

        	 if(esc=='i')
        	 {
              e=1;
        	  cout<<"\nPASSAGEM ABERTA\n";	
        	  matriz[48][49]='='; 
        	  system("pause");
        	  system("cls");
			  o=1;
			 }
        
		}     else if(x==48 && y==49 && e==1 )	{
        	qq=1;
        	s=1;
        	x=0;
	    }
	 	

{
	 	matriz [x][y] = '&';
	 	
	 	for (i = 0; i < 50; i++)
     {
          for (j = 0; j < 50; j++)
          {
               cout << matriz[i][j]<<' ';
          }
          
          cout << "\n";
     }
     
     //cout<<"x="<<x;
     //cout<<"\n\n";
     //cout<<"y="<<y;
    // cout<<"\n\n";
  }
  
 }

void Matriz0(int &x, int &y)
{
	char escb;
	char matriz[75][75];
	int l,c;  //l = linha, c = coluna.
	int i,j,m=3;	
	

	
	for(l=1;l!=74;l++)
	{
	 for(c=1;c!=74;c++)             //meio
	 {
      matriz[l][c]=' ';
	 }		
	}
	

	 for(l=0;l!=13;l++)            //desenho 1  |  
	 {
      matriz[l][25]='#';     
	 }		
	
	 for(c=0;c!=26;c++)            //desenho 2  _
	 {
      matriz[13][c]='*';     
	 }		
    
    	 for(c=26;c!=53;c++)            //desenho 3 #  _
	 {
      matriz[13][c]='#';     
	 }		
	 
    for(c=65;c!=74;c++)            //desenho 3 #  _
	 {
      matriz[13][c]='#';     
	 }		
    
    
    for(l=14;l!=30;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][52]='#';     
	 }	
	 	 
	 for(l=25;l!=31;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][30]='#';     
	 }	
	 
	 	 for(c=30;c!=52;c++)            //desenho 3 # meio _
	 {
      matriz[30][c]='#';     
	 }		
	 
	  for(c=18;c!=30;c++)            //desenho 3 # meio _
	 {
      matriz[25][c]='#';     
	 }		

	 	 for(c=30;c!=52;c++)            //desenho 3 #  _
	 {
      matriz[41][c]='#';     
	 }		
	 
	 
	 for(l=41;l!=47;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][30]='#';     
	 }	
	 
	  for(c=18;c!=31;c++)            //desenho 3 # meio _
	 {
      matriz[47][c]='#';     
	 }		
	 
	 	for(l=26;l!=47;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][18]='#';     
	 }	
	 
	 
	  for(c=30;c!=52;c++)            //desenho 3 #  _
	 {
      matriz[41][c]='#';     
	 }		
	 
	 
	 for(l=41;l!=61;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][52]='#';     
	 }	
    
     for(l=14;l!=61;l++)            //desenho 1 #  meio |  
	 {
      matriz[l][65]='#';     
	 }	
    
    
	 for(c=0;c!=74;c++)            //desenho 2  _
	 {
      matriz[61][c]='#';     
	 }			
	 
	 
	 
	 for(l=61;l!=67;l++)            //desenho 1 # cima |  --------------------obstaculos--
	 {
      matriz[l][11]='#';     
	 }	
	 
	 for(l=69;l!=74;l++)            //desenho 1 #  |  
	 {
      matriz[l][11]='#';     
	 }	
	 
	 
	 
	 for(l=66;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][14]='#';     
	 }	
	 
	 	for(l=61;l!=66;l++)            //desenho 1 # cima |  
	 {
      matriz[l][17]='#';     
	 }	
	 
	  for(l=63;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][20]='#';     
	 }	
	 
	 	for(l=61;l!=70;l++)            //desenho 1 # cima |  
	 {
      matriz[l][23]='#';     
	 }	
	 
	 	for(l=69;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][26]='#';     
	 }	
	 
	 	for(l=61;l!=66;l++)            //desenho 1 # cima |  
	 {
      matriz[l][29]='#';     
	 }	
	 
	  	for(l=64;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][32]='#';     
	 }	
	 
	 	for(l=61;l!=71;l++)            //desenho 1 # cima |  
	 {
      matriz[l][35]='#';     
	 }	
	 
	  	for(l=67;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][38]='#';     
	 }	

        for(l=61;l!=69;l++)            //desenho 1 # cima |  
	 {
      matriz[l][41]='#';     
	 }	

     	for(l=65;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][44]='#';     
	 }	
     
     
      for(l=61;l!=69;l++)            //desenho 1 # cima |  
	 {
      matriz[l][47]='#';     
	 }	
     
     	for(l=70;l!=74;l++)            //desenho 1 #  baixo|  
	 {
      matriz[l][49]='#';     
	 }	
     
     
      for(l=61;l!=72;l++)            //desenho 1 # cima |  ----------------------------------------------
	 {
      matriz[l][52]='#';     
	 }	
     
	for(c=74;c!=75;c++)
	{                
	                                      //lateral direita
	 for(l=0;l!=75;l++)
	 {
      matriz[l][c]='*';
	 }    
	                           
	}
	
	for(l=74;l!=75;l++)
	{
	 for(c=0;c!=75;c++)
	 {
      matriz[l][c]='*';               //parte de baixo
	 }	
	 	
	}
	
	
	for(l=0;l!=1;l++)
	{
	 for(c=0;c!=75;c++)              // parte de cima
	 {
      matriz[l][c]='*';     
	 }		
	}
	
	for(c=0;c!=1;c++)
	{                              //lateral esquerda
	 for(l=0;l!=75;l++)
	 {
      matriz[l][c]='*';
	 }
	}
  
	
    matriz[4][25]='#';
	matriz[5][25]='#';                 //teletransporte 1
	matriz[6][25]='>';
	matriz[7][25]='#';
	matriz[8][25]='#';
	matriz[62][73]='#';
	matriz[63][73]='#';
	matriz[64][73]='#';
	matriz[65][73]='#';
	matriz[66][73]='#';                 //teletransporte 2
	matriz[67][73]='>';
	matriz[68][73]='#';
	matriz[69][73]='#';
	matriz[70][73]='#';
	matriz[71][73]='#';
	matriz[72][73]='#';
	matriz[73][73]='#';
	
	
	matriz[1][67]='#';
	matriz[2][68]='#';
	matriz[3][69]='#';
	matriz[4][70]='#';
	matriz[5][71]='#';
	matriz[5][71]='#';
	matriz[5][72]='#';
	matriz[5][73]='#';
	matriz[5][74]='#';
	
	matriz[6][74]='#';
	matriz[7][74]='D';
	                      //Porta
	matriz[8][73]='#';
	matriz[8][72]='#';
	matriz[8][71]='#';
	matriz[9][70]='#';
	matriz[10][69]='#';
	matriz[11][68]='#';
	matriz[12][67]='#';
	
	matriz[68][4]='O';                  //botao
	matriz[36][24]='@';
	//matriz[7][73]= '$';  
	
	if(	matriz[x][y] == 'O')
        {
        	h=1;
        }
        
     if(matriz[x][y] == '>' && x<20 )
        {
        	x=67;
        	y=72;
        }   
	
	 if(matriz[x][y] == '>' && x>20 )
        {
        	x=6;
        	y=24;
        }   
	
	if(h!=1){
	
	matriz[61][53]='#';
	matriz[61][54]='#';
	matriz[61][55]='#';          // oque ele deve abrir depois de apertar o botao
	matriz[61][56]='#';
	matriz[61][57]='#';
	matriz[61][58]='#';
	matriz[61][59]='#';
	matriz[61][60]='#';
	matriz[61][61]='#';
	matriz[61][62]='#';
	matriz[61][63]='#';
	matriz[61][64]='#';
	matriz[61][64]='#';
   }else{
   	matriz[61][53]=' ';
	matriz[61][54]=' ';
	matriz[61][55]=' ';          // oque ele deve abrir depois de apertar o botao
	matriz[61][56]=' ';
	matriz[61][57]=' ';
	matriz[61][58]=' ';
	matriz[61][59]=' ';
	matriz[61][60]=' ';
	matriz[61][61]=' ';
	matriz[61][62]=' ';
	matriz[61][63]=' ';
	matriz[61][64]=' ';
	matriz[61][64]=' ';
   
   }
   	if(oo!=1){
		matriz[7][74] = 'D';
	}else{
		matriz[7][73] = '$';
		matriz[7][74] = '=';
		
	}
   

	 	if(	matriz[x][y] == '@')
        {
        	char esc;
        	cout<<"\nVoce achou a chave pressione i para usar\n";
        	cin>>esc;

        	 if(esc=='i')
        	 {
              ee=1;
        	  cout<<"\nPASSAGEM ABERTA\n";	
        	  matriz[7][74]='='; 
        	  system("pause");
        	  system("cls");
			  oo=1;
			 }
        
		}     else if(x==7 && y==74 && ee==1 )	{
        	qq2=1;
        	//sss=1;
	    }
     
        if(matriz[x][y] == '$')
		{
			RPG();
			
		}
	  
	  if(	matriz[x][y] == '#')
       {
        sss=1;
			 }
	  

	 	matriz[x][y] = '&';
	 	
	 	for (i = 0; i < 75; i++)
     {
          for (j = 0; j < 75; j++)
          {
               cout << matriz[i][j]<<' ';
          }
          
          cout << "\n";
     }

  }


void Fase1(Hero& obj)
{

	system("cls");
	char opc;
	char matriz[50][50];
	Matriz50(obj.posicao.x,obj.posicao.y);
	while(s!=1)
	{
		opc = getche();
		
        if(opc == 'w')
		{
			system("clear || cls");
			
			
			if(obj.posicao.x!=1)
			{
			obj.posicao.x = obj.posicao.x-1;
		   }
			Matriz50(obj.posicao.x,obj.posicao.y);
			
		}
		
		else if(opc == 'a')
		{
			system("clear || cls");
				if(obj.posicao.y!=1)
			{
			obj.posicao.y = obj.posicao.y-1;
	       	}
			Matriz50(obj.posicao.x,obj.posicao.y);
			
		}
		
		else if(opc == 's')
		{
			system("clear || cls");
			
			if(obj.posicao.x!=48)
			{
			obj.posicao.x= obj.posicao.x+1;
			}
			
			Matriz50(obj.posicao.x,obj.posicao.y);
		}
		
		else if(opc == 'd')
		{
			system("clear || cls");
			if(obj.posicao.x<48){
				if(obj.posicao.y!=48)
			{
			obj.posicao.y = obj.posicao.y+1;
			  }
			}else{
					if(obj.posicao.y!=48+o)
			{
			obj.posicao.y = obj.posicao.y+1;
			}	
			}
			Matriz50(obj.posicao.x, obj.posicao.y);
		
		}	
	}
}



void Fase2(Hero& obj)
{
	system("cls");
	char opc;
	char matriz[75][75];
	Matriz0(obj.posicao.x,obj.posicao.y);
	

	while(sss!=1)
	{
		opc = getche();
		
        if(opc == 'w')
		{
			system("clear || cls");
			if(obj.posicao.x!=1)
			{
			obj.posicao.x = obj.posicao.x-1;
		   }
			Matriz0(obj.posicao.x,obj.posicao.y);
			
		}
		
		else if(opc == 'a')
		{
			system("clear || cls");
				if(obj.posicao.y!=1)
			{
			obj.posicao.y = obj.posicao.y-1;
	       	}
			Matriz0(obj.posicao.x,obj.posicao.y);
			
		}
		
		else if(opc == 's')
		{
			system("clear || cls");
			
			if(obj.posicao.y<25){
				if(obj.posicao.x!=73 && obj.posicao.x!=12)
			{
			obj.posicao.x= obj.posicao.x+1;
			}
			}else{
				if(obj.posicao.x!=73)
			{
			obj.posicao.x= obj.posicao.x+1;
			}
				
			}
			
			
			
			Matriz0(obj.posicao.x,obj.posicao.y);
		}
		
		else if(opc == 'd')
		{
			system("clear || cls");
			
			if(obj.posicao.y!=73+oo  )
			{
			obj.posicao.y = obj.posicao.y+1;
			}	
			Matriz0(obj.posicao.x, obj.posicao.y);
		}
		
	}
}

void rei(Hero& obj){
system("cls");	

cout<<"Encostou em um espinho! resta so "<< x <<"/3 vidas!\n";

system("pause");
	
	
obj.posicao.x = 1;
obj.posicao.y = 1;	
s=0;
x--;
}

void pose(Hero& obj){
	
obj.posicao.x = 1;
obj.posicao.y = 1;	

}

void rei2(Hero& obj){
system("cls");	

cout<<"Encostou em um espinho! resta so "<< x1 <<"/3 vidas!\n";

system("pause");
	
	
obj.posicao.x = 1;
obj.posicao.y = 1;	
sss=0;
x1--;
}

void derrota()
{
	system("cls");
	string h = "\t______\n";
	cout<< h;
	
   cout<<"Perdeu? kkkkk\n";	
   system("pause");	
}

void vitoria()
{
	
	system("cls");
	string h = "\t______\n";
	cout<< h;
	
   cout<<"Você conseguiu passar de fase!\n";	
   system("pause");
   	
}

void Despedida()
{  system("cls");
   cout << "Até a próxima aventura jogador!\n";
   system("pause");		
}

void VitoriaFinal()
{   system("cls");
	cout <<"Parabéns! Você completou todas as fases e chegou ao final do jogo!\n";
	system("pause");	
}

void movimentacao(int q,int w,int e,int r)
{
	movimento = getche(); //cima
	if(movimento == 119){
		if(ccy != 1){
		
			if(ccy != q || ccx <6 || ccx>18 ){  
			--ccy;	
			mapa();}
		else if(ccy != q){  
			--ccy;	
			mapa();
		}
	}
}
	else if(movimento == 97){ //esquerda
		if(ccx != w && ccx != 1 ){
			--ccx;
			mapa();
		}
	}
	else if(movimento == 115){ //baixo
	if(ccy>18){
	  if(ccy != e){     
	  ++ccy;
	  mapa();
	}
	} 
	else if(ccy != e || ccx <6 || ccx>18 ){
			++ccy;
			mapa();
		}
	}
	else if(movimento == 100){ //direita
	if(ccy>22){
	  if(ccx != 23+y){     
	  ++ccx;
	  mapa();
	}
}
	else if(ccx != r && ccx != 23){
			++ccx;
			mapa();
		}
	}
	cout<<"\n"<<ccy<<"\n";
			cout<<ccx<<"\n";
	
   if(ccy == 4 && ccx == 8 ){	
           system("cls");
		   cout<<"Voce encontrou a chave! aperte i para usa-la!\n";	
		   cin >> t;
		   if(t=='i'){
		    cout<<"A porta esta aberta! passe por ela e va pra 2 fase!\n";
		    system("pause");
		    ++ccx;
		    p=1;
		    y=1;
	       }else{
	       	--ccx;
		   }
	}else if(ccy == 23 && ccx == 24 && p==1){	
        	system("pause");
            z=1;
	       }

}

void personagem() // personagem
{
	mat[ccy][ccx] = '&';
	mat[4][8] = '@';
	if(p!=1){
		mat[23][24] = 'D';
	}else{
		mat[23][24] = '=';
		
	}
}


void mapa()
{	
	for(l=0;l!=1;l++)
	{
	 for(c=0;c!=25;c++)              // parte de cima
	 {
      mat[l][c]='*';     
	 }		
	}
	for(c=0;c!=1;c++)
	{                              //lateral esquerda
	 for(l=0;l!=25;l++)
	 {
      mat[l][c]='*';
	 }
	}
	for(l=1;l!=24;l++)
	{
	 for(c=1;c!=24;c++)             //meio
	 {
      mat[l][c]=' ';
	 }		
	}
		for(l=1;l!=18;l++)
	{
		mat[l][6]='*';                   //desenho
	 }
	 
	 for(l=6;l!=19;l++)
	{
		mat[18][l]='*';                   //desenho
	 }
	 for(l=6;l!=19;l++)
	{
		mat[5][l]='*';                   //desenho
	 }
	 for(l=5;l!=18;l++)
	{
		mat[l][18]='*';                   //desenho
	 }
  for(c=24;c!=25;c++)
	{                              //lateral direita
	 for(l=0;l!=25;l++)
	 {
      mat[l][c]='*';
	 }                              
	}
	for(l=24;l!=25;l++)
	{
	 for(c=0;c!=25;c++)
	 {
      mat[l][c]='*';               //parte de baixo
	 }		
	}
}

void imprime()
{
	for(i=0;i!=25;i++)
	{
		for(c=0;c!=25;c++)
		{                                //imprimir a matriz;
	     cout<<mat[i][c]<<" ";
		}
         cout<<"\n";
	}
}
	
void fase0()
{
	
	while(z != 1){
		system("CLS");
		ccy = 1 ;
	    ccx = 1;
		while(z != 1){
			system("CLS");
			mapa();
			personagem();
			imprime();
			if(ccy>18){
			movimentacao(19,1,23,23);	
			}else if(ccy<=18 && ccy>=5 ){
			movimentacao(1,19,23,5);
		    }
			else{
		    	movimentacao(1,7,4,5);
			}				
	} 


}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char escolha; 
	Hero heroi; 
	
	while(true)
	{
	
	Menu();
	cin >> escolha;
	//escolha='1';
	if(escolha == '1')
	{
		Criar(heroi);
		Status(heroi);
		system("cls");
	
	    fase0();
	    vitoria();
	  // cord(heroi);
		
	    while(x>=0 && s!=1){
	    	
		Fase1(heroi);
		
		if(x>-1 && qq!=1 ){
		rei(heroi);	
		}
		}
		
	  if(x==-1){
	  	derrota();
	 	system("pause");
	  	main();
	  }
		
	   vitoria();
	   pose(heroi);
	    //cord(heroi);
	   while(x1>=0 && sss!=1){
	    
		Fase2(heroi);
		if(x1>-1 && qq2!=1){
		rei2(heroi);	
		}
		}
		
	   if(x1==-1){
	  	derrota();
	   	system("pause");
	   	main();
	    }
	    if(kk!=0){
	    VitoriaFinal();	
		}
	    Despedida();
	}
	
	else if(escolha == '2')
	{
		system("cls");
		Tutorial();
		cout<<"\n";
        system("pause");
	}
	
	else if(escolha == '3')//quebra o laço -> opc sair
	{
		system("cls");
		Despedida();
		exit(0);
	}
	else
	{
		cout<<"invalido!!\n";
		system("pause");
		main();
	}
	system("cls");
	}
}
