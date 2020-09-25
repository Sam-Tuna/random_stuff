/* ************************************************************************** */
/*
Nome: Ana Orsi
Numero USP: sei lá

Nome: Samir Atum
Numero USP: 9792612

Exercício-programa 4
*/
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
typedef struct caaminho{
	char imprimemaior[1200][2];
	struct caaminho *p;
}caminho;
caminho* nova (){
	int i;
	caminho *pa;
	pa=malloc(sizeof(caminho));
	pa->p=NULL;
	for(i=0;i<1200;i++) (pa->imprimemaior[i][0])=(pa->imprimemaior[i][1])=0;
	return pa;
}
int matriz[24][24]={
	/*A1*/{4, -1, -2, -2,  0, -1, -1, 0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -3, -2,  0, -2, -1,  0, -4},
	/*R2*/{-1,  5,  0, -2, -3,  1,  0, -2,  0, -3, -2,  2, -1, -3, -2, -1, -1, -3, -2, -3, -1,  0, -1, -4},
	/*N3*/{-2,  0,  6,  1, -3,  0,  0,  0,  1, -3, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3,  3,  0, -1, -4},
	/*D4*/{-2, -2,  1,  6, -3,  0,  2, -1, -1, -3, -4, -1, -3, -3, -1,  0, -1, -4, -3, -3,  4,  1, -1, -4},
	/*C5*/{0, -3, -3, -3,  9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, -3, -3, -2, -4},
	/*Q6*/{-1,  1,  0,  0, -3,  5,  2, -2,  0, -3, -2,  1,  0, -3, -1,  0, -1, -2, -1, -2,  0,  3, -1, -4},
	/*E7*/{-1,  0,  0,  2, -4,  2,  5, -2,  0, -3, -3,  1, -2, -3, -1,  0, -1, -3, -2, -2,  1,  4, -1, -4},
	/*G8*/{0, -2,  0, -1, -3, -2, -2,  6, -2, -4, -4, -2, -3, -3, -2,  0, -2, -2, -3, -3, -1, -2, -1, -4},
	/*H9*/{-2,  0,  1, -1, -3,  0,  0, -2,  8, -3, -3, -1, -2, -1, -2, -1, -2, -2,  2, -3,  0,  0, -1, -4},
	/*I10*/{-1, -3, -3, -3, -1, -3, -3, -4, -3,  4,  2, -3,  1,  0, -3, -2, -1, -3, -1,  3, -3, -3, -1, -4},
	/*L11*/{-1, -2, -3, -4, -1, -2, -3, -4, -3,  2,  4, -2,  2,  0, -3, -2, -1, -2, -1,  1, -4, -3, -1, -4},
	/*K12*/{-1,  2,  0, -1, -3,  1,  1, -2, -1, -3, -2,  5, -1, -3, -1,  0, -1, -3, -2, -2,  0,  1, -1, -4},
	/*M13*/{-1, -1, -2, -3, -1,  0, -2, -3, -2,  1,  2, -1,  5,  0, -2, -1, -1, -1, -1,  1, -3, -1, -1, -4},
	/*F14*/{-2, -3, -3, -3, -2, -3, -3, -3, -1,  0,  0, -3,  0,  6, -4, -2, -2,  1,  3, -1, -3, -3, -1, -4},
	/*P15*/{-1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4,  7, -1, -1, -4, -3, -2, -2, -1, -2, -4},
	/*S16*/{1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -2,  0, -1, -2, -1,  4,  1, -3, -2, -2,  0,  0,  0, -4},
	/*T17*/{0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1,  1,  5, -2, -2,  0, -1, -1,  0, -4},
	/*W18*/{-3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1,  1, -4, -3, -2, 11,  2, -3, -4, -3, -2, -4},
	/*Y19*/{-2, -2, -2, -3, -2, -1, -2, -3,  2, -1, -1, -2, -1,  3, -3, -2, -2,  2,  7, -1, -3, -2, -1, -4},
	/*V20*/{0, -3, -3, -3, -1, -2, -2, -3, -3,  3,  1, -2,  1, -1, -2, -2,  0, -3, -1,  4, -3, -2, -1, -4},
	/*B21*/{-2, -1,  3,  4, -3,  0,  1, -1,  0, -3, -4,  0, -3, -3, -2,  0, -1, -4, -3, -3,  4,  1, -1, -4},
	/*Z22*/{-1,  0,  0,  1, -3,  3,  4, -2,  0, -3, -3,  1, -1, -3, -1,  0, -1, -3, -2, -2,  1,  4, -1, -4},
	/*X23*/{0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2,  0,  0, -2, -1, -1, -1, -1, -1, -4},
	/*.*24.*/{-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,  1}
};
void coloca_gap (int tam1, int tam2, int gap, int a[][1000][2]){
	int i;
	for (i=0;i<=tam1+1;i++){
		a[i][0][0]=gap*i;
		a[i][0][1]=2;
	}
	for (i=0;i<=tam2+1;i++){
		a[0][i][0]=gap*i;
		a[0][i][1]=5;
	}
}
int triptofano(char seq){
	int n=-1;
	if (seq=='A') n=0;
	if (seq=='R') n=1;
	if (seq=='N') n=2;
	if (seq=='D') n=3;
	if (seq=='C') n=4;
	if (seq=='Q') n=5;
	if (seq=='E') n=6;
	if (seq=='G') n=7;
	if (seq=='H') n=8;
	if (seq=='I') n=9;
	if (seq=='L') n=10;
	if (seq=='K') n=11;
	if (seq=='M') n=12;
	if (seq=='F') n=13;
	if (seq=='P') n=14;
	if (seq=='S') n=15;
	if (seq=='T') n=16;
	if (seq=='W') n=17;
	if (seq=='Y') n=18;
	if (seq=='V') n=19;
	if (seq=='B') n=20;
	if (seq=='Z') n=21;
	if (seq=='X') n=22;
	if (seq=='*') n=23;
	return n;
}
int alanina(int matriz[][24], char seq2, char seq1){
	/*linha seq2, coluna seq1*/
	int posx, posy, d;
	posx=triptofano(seq2);
	posy=triptofano(seq1);
	d=matriz[posx][posy];
	return d;
}
int compara (int a[][1000][2], int gap, int i, int j, int d){
	int c, e, maior;
	c=a[i-1][j][0]+gap;
	e=a[i][j-1][0]+gap;
	d=a[i-1][j-1][0]+d;
	if(c>e){
		maior=c;
		a[i][j][1]=a[i][j][1]*2;
	}
	else if(e>c){
		maior=e;
		a[i][j][1]=a[i][j][1]*5;
	}
	else{
		a[i][j][1]=a[i][j][1]*10;
		maior=e;
	}
	if(d>maior){
		maior=d;
		a[i][j][1]=3;
	}
	else if(d==maior) a[i][j][1]=a[i][j][1]*3;
	return maior;
}
void asparagina (caminho *h, char imprime[][2], int *apontaimprime){
	int i, j=0;
	caminho *no;
	no=nova();
	for(i=0;i<=*apontaimprime;i++){
		for(j=0;j<2;j++){
			no->imprimemaior[i][j]=imprime[i][j];
		}
	}
	if(h->p==NULL) h->p=no;
	else{
		no->p=h->p;
		h->p=no;
	}
}
void histidina (int a[][1000][2], int x, int y, char seq1[], char seq2[], int aponta1, int aponta2, caminho *h, char imprime[][2], int *apontaimprime){
	if(x>1||y>1){
		if(a[x][y][1]%2==0){/*atualizar a struct (gap de cima)*/
			x=x-1;
			imprime[*apontaimprime][0]='-';
			imprime[*apontaimprime][1]=seq2[aponta2];
			*apontaimprime=*apontaimprime+1;
			aponta2--;
			histidina (a, x, y, seq1, seq2, aponta1, aponta2, h, imprime, apontaimprime);
			imprime[*apontaimprime][0]=0;
			imprime[*apontaimprime][1]=0;
			*apontaimprime=*apontaimprime-1;
			x=x+1;
			aponta2++;
		}
		if(a[x][y][1]%3==0){/*  atualizar a struct (match ou mismacth)*/
			y=y-1;
			x=x-1;
			imprime[*apontaimprime][0]=seq1[aponta1];
			imprime[*apontaimprime][1]=seq2[aponta2];
			*apontaimprime=*apontaimprime+1;
			aponta1--;
			aponta2--;
			histidina (a, x, y, seq1, seq2, aponta1, aponta2, h, imprime, apontaimprime);
			imprime[*apontaimprime][0]=0;
			imprime[*apontaimprime][1]=0;
			*apontaimprime=*apontaimprime-1;
			x=x+1;
			y=y+1;
			aponta1++;
			aponta2++;
		}
		if(a[x][y][1]%5==0){/*  atualizar a struct (gap esquerda)*/
			y=y-1;
			imprime[*apontaimprime][1]='-';
			imprime[*apontaimprime][0]=seq1[aponta1];
			*apontaimprime=*apontaimprime+1;
			aponta1--;
			histidina (a, x, y, seq1, seq2, aponta1, aponta2, h, imprime, apontaimprime);
			imprime[*apontaimprime][0]=0;
			imprime[*apontaimprime][1]=0;
			*apontaimprime=*apontaimprime-1;
			y=y+1;
			aponta1++;
		}
	}
	else{
		if(y<1){
			imprime[*apontaimprime][0]='-';
			imprime[*apontaimprime][1]=seq2[aponta2];
		}
		else if(x<1){
			imprime[*apontaimprime][1]='-';
			imprime[*apontaimprime][0]=seq1[aponta1];
		}
		else{
			imprime[*apontaimprime][0]=seq1[aponta1];
			imprime[*apontaimprime][1]=seq2[aponta2];
		}
		asparagina(h, imprime, apontaimprime);
		imprime[*apontaimprime][0]=0;
		imprime[*apontaimprime][1]=0;
	}
}
int main(){
	FILE * in;
	FILE * out;
	int i, j, lixo, gap, n=0, a[1000][1000][2], tam1=0, tam2=0, aponta1=1, aponta2=1, x, y, contaimprime=0, d=0, *apontaimprime, leitura=1;
	char arqin[50], seq1[1000], seq2[1000], tmp=0, imprime[1200][2];
	caminho *h, *charmander=NULL;
	h=malloc(sizeof(caminho));
	h->p=NULL;
	apontaimprime=&contaimprime;
	for(i=0; i<50; i++) arqin[i]='\0';
	for(i=0; i<1000; i++){
		for(j=0; j<1000; j++) a[i][j][1]=1;
	}
	for(i=0; i<1200; i++){
		for(j=0; j<2; j++) imprime[i][j]=0;
	}
	printf("Entre com o nome do arquivo fasta\n");
	lixo=scanf("%s", arqin);
	lixo=lixo+17;
	in=fopen(arqin, "r");
	if(in==NULL) printf("Nope\n");
	else{
		leitura=fscanf(in, "%c", &tmp);
		printf ("Entre com a penalidade do gap\n");
		scanf ("%d", &gap);
		if (tmp!='>'){
			printf ("coloque algo em fasta\n");
			return 89;
		}
		while (leitura!=EOF&&tmp!='\n') {
			leitura=fscanf(in, "%c", &tmp);
		}
		i=1;
		while (leitura!=EOF&&tmp!='>'){
			leitura=fscanf(in, "%c", &tmp);
			if (tmp!='\n'&&tmp!='>'){
				seq1[i]=tmp;
				i++;
			}
		}
		tam1=i-1;
		i=1;
		while (leitura!=EOF&&tmp!='\n') {
			leitura=fscanf(in, "%c", &tmp);
		}
		while (leitura!=EOF){
			leitura=fscanf(in, "%c", &tmp);
			if (tmp!='\n'){
				seq2[i]=tmp;
				i++;
			}
		}
		tam2=i-1;
		coloca_gap(tam1, tam2, gap, a);
		for(i=1;i<=tam2;i++){
			for(j=1;j<=tam1;j++){
				d=alanina(matriz, seq2[i], seq1[j]);
				a[i][j][0]=compara(a, gap, i, j, d);
			}
		}
		aponta1=y=tam1;
		aponta2=x=tam2;
		histidina(a, x, y, seq1, seq2, aponta1, aponta2, h, imprime, apontaimprime);
		fclose(in);
        out=fopen("alinhado.txt", "w");
		if (h->p!=NULL) charmander=h->p;
		j=1;
		while (charmander!=NULL){/***********************************************Essa eh a parte de imprimir no arquivo**************************************************/
			i=0;
			x=0;
			fprintf(out, "Alinhamento %d:\n", j);
			while (charmander->imprimemaior[i][0]!=0){
				lixo=0;
				if (i>0&&charmander->imprimemaior[i-1][0]!=0){
					lixo++;
					fprintf(out, "%c", charmander->imprimemaior[i-1][0]);
				}
				while ((i+1)%81!=0&&charmander->imprimemaior[i][0]!=0){
					fprintf(out, "%c", charmander->imprimemaior[i][0]);
					lixo++;
					i++;
				}
				i++;
				fprintf(out, "\n");
				for (n=0;n<lixo;n++) fprintf(out, "|");
				fprintf(out, "\n");
				if (x>0&&charmander->imprimemaior[x-1][0]!=0){
					fprintf(out, "%c", charmander->imprimemaior[x-1][0]);
				}
				while ((x+1)%81!=0&&charmander->imprimemaior[x][1]!=0){
					fprintf(out, "%c", charmander->imprimemaior[x][1]);
					x++;
				}
				x++;
				fprintf(out, "\n\n");
			}
			j++;
			charmander=charmander->p;
		}
		while(h->p!=NULL){
			for(i=0;h->p->imprimemaior[i][0]!=0;i++){
				printf("%c-%c\n", (h->p->imprimemaior[i][0]), (h->p->imprimemaior[i][1]));
			}
			printf("\n");
			h->p=h->p->p;
		}
		fclose(out);
	}
	return 42;
}
