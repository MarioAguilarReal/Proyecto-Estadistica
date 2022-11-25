#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <time.h>
using namespace std;

void leerDatos();
void leerDatosArchivo();
void crearA();
void leerA();
void ordenarVector();
void tallos_hojas();
void graficoPuntos();
void histogramas();
void media();
void moda();
void mediana();
void varianza_uno();
void varianza_dos();
void minimosCuadrados();

int i=0, j=0, k=0;//Iteradores del programa
int data=0;
int gd=DETECT, gm;

typedef struct{
    int vectorPrincipal[100];
    int n;
}vars;
vars v;

int main(){
    int op=0, op2=0, pp=0;
    srand(time(NULL));
    do{
        printf("ESCOGE UNA FUNCION:\n\n");
        printf("\t[1]MEDIA\t\t[2]MODA\t\t\t[3]MEDIANA\n\n\t[4]DIAGRAMA DE TALLOS\t[5]DIAGRAMA DE PUNTOS\t[6]HISTOGRAMA\n\n\t[7]VARIANZA POBLACIONAL\t[8]VARIANZA MUESTRAL\t[9]MINIMOS CUADRADOS\n\n\t[0]Salir\n\n");
        printf("\n[Opcion]-> ");
        cin>>op;
        printf("\n");

        if(op==0){
            printf("Has salido");
            exit(3);
        }else if(op != 9){
            printf("INGRESAR DATOS POR:\n");
            printf("\t[1]TECLADO\n\t[2]ARCHIVO\n");
            if(pp!=0){
			printf("\t[3]REUSAR DATOS ANTERIORES\n");
        	}
            cout<<"->";
			cin>>op2;
            switch(op2){
                case 1:
                    cout<<"INGRESA LA CANTIDAD (n) DE DATOS:\n"<<endl;
                    cin>>v.n;
                    leerDatos();
                    break;
                case 2:
                    leerDatosArchivo();
                    break;
                case 3:
                    break;
            }
            ordenarVector();
        }
        switch(op){
            case 1:
                media();
                system("pause");
                system("cls");
                break;
            case 2:
                moda();
                system("pause");
                system("cls");
                break;
            case 3:
                mediana();
                system("pause");
                system("cls");
                break;
            case 4:
                tallos_hojas();
                system("pause");
                system("cls");
                break;
            case 5:
                graficoPuntos();
                system("pause");
                system("cls");
                break;
            case 6:
                histogramas();
                system("pause");
                system("cls");
                break;
            case 7:
                varianza_uno();
                system("pause");
                system("cls");
                break;
            case 8:
                varianza_dos();
                system("pause");
                system("cls");
                break;
            case 9:
                minimosCuadrados();
                system("pause");
                system("cls");
                break;
        }
        pp+=1;
    }while(op=!0);
    return 0;
}

void leerDatos(){
    for(i=0;i<v.n;i++){
        cout<<"Ingresa el dato ["<<i+1<<"]: "<<endl;
        cin>>v.vectorPrincipal[i];
    }
}

void leerDatosArchivo(){
    cout<<"ELIGE UNA OPCION:\n";
    cout<<"\t[1]ABRIR UN ARCHIVO EXISTENTE"<<endl;
    cout<<"\t[2]CREAR UN ARCHIVO"<<endl<<"->";
    int opa=0;
    cin>>opa;
    switch (opa)
    {
    case 2:
        crearA();
        cout<<"\nDatos Ingresados correctamente"<<endl;
        system("pause");
        system("cls");
        break;
    
    case 1:
        leerA();
        break;
    }
}

void crearA(){
    FILE *fptr;
    int dato;
    char nombreArchivo[100], c;

    cout<<"INGRESA LA CANTIDAD DE DATOS DEL -NUEVO- ARCHIVO:"<<endl<<"->";
    cin>>v.n;

    printf("\nINGRESA EL NOMBRE DEL ARCHIVO (al final poner [.txt]):\n");
    scanf("%s", nombreArchivo);

    fptr = fopen(nombreArchivo , "w");
    if(fptr == NULL){
        printf("No se puede abrir el archivo\n");
        exit(0);
    }

    printf("INGRESA LOS DATOS DEL ARCHIVO: \n");
    for(i=0;i<v.n;i++){
        printf("Dato [%d]: ", i+1);
        scanf("%d", &dato);
        fprintf(fptr, "%d ", dato);
    }
    fclose(fptr);

    fptr = fopen(nombreArchivo, "r+");
    if(fptr==NULL){
        printf("Error No se puede abrir el archivo\n");
        exit(0);
    }
    i=0;
    while(!feof(fptr)){
        fscanf(fptr, "%d", &v.vectorPrincipal[i]);
        i++;
	}
    fclose(fptr);
}

void leerA(){
    FILE *fptr;
    char nombreArchivo[100], c;

    printf("INGRESA EL NOMBRE DEL ARCHIVO: \n");
    scanf("%s", nombreArchivo);

    fptr = fopen(nombreArchivo, "r+");
    if(fptr==NULL){
        printf("Error No se puede abrir el archivo\n");
        exit(0);
    }
    i=0;
    while(!feof(fptr)){
        fscanf(fptr, "%d", &v.vectorPrincipal[i]);
        i++;
    }
    v.n=i-1;

    fclose(fptr);

}

void ordenarVector(){
    int v_temp;

    for(i=0;i<v.n;i++){
        for(j=0;j<v.n;j++){
            if(v.vectorPrincipal[i] < v.vectorPrincipal[j]){
                v_temp=v.vectorPrincipal[i];
                v.vectorPrincipal[i]=v.vectorPrincipal[j];
                v.vectorPrincipal[j]=v_temp;
            }
        }
    }
}

void tallos_hojas(){
    int aux = 0, tallos[100], hojas[100];

    for(i=0; i<v.n; i++){
        if(i>=1){
            if(tallos[aux-1]!=(v.vectorPrincipal[i]/10)){
                tallos[aux] = v.vectorPrincipal[i]/10;
                aux++;
            }
        }else if(i==0){
            tallos[aux] = v.vectorPrincipal[i]/10;
            aux++;
        }
    }

    cout<<"DIAGRAMA DE TALLOS Y HOJAS\n\n";
    
    for(i=0; i<20; i++)cout<<"--";
    
    cout<<endl;

    for(i=0; i<aux;i++){
        cout<<tallos[i]<<" ||";
        for(j=0;j<v.n;j++){
            if(tallos[i]==(v.vectorPrincipal[j]/10)){
                cout<<(v.vectorPrincipal[j]%10)<<" ";
            }
        }
        cout<<endl;
    }
    for(i=0;i<20;i++)cout<<"--";
    cout<<endl;
}

void graficoPuntos(){
    int vBase[100], vSinRep[100], i_vSinRep=0, i_amplitud, contador=0, index=0, bs=0, x=50, y=400, limite_inf=v.vectorPrincipal[0], limite_sup=v.vectorPrincipal[v.n-1], amplitud = limite_sup-limite_inf;
    char num[6];

    for(i=0;i<v.n;i++){
        if(index!=v.vectorPrincipal[i]){//Si el dato anterior es diferente del actual se ejecutara
            contador++;//Contador de datos repetidos
            for(j=0;j<v.n;j++){
                if(v.vectorPrincipal[i]==v.vectorPrincipal[j] && i!=j){
                    contador++;//cuenta los datos repetidos
                }
            }
            vBase[bs]=contador;//Guarda el conteo de datos en un vector
            contador=0;//se reinicia el contador para el siguiente dato que se repetira
            bs++;//Aumenta el indice del donde se guardan los datos
        }
        index=v.vectorPrincipal[i];//Index será igual al dato actual
    }

    //inicio lo graficos ajustando la pantalla a la cantidad de datos
    initwindow(x+(20*amplitud)+50, y+100);
    for(i=0;i<v.n;i++){//guarda los datos sin repetidos en un vector
        if(index!=v.vectorPrincipal[i]){
            vSinRep[i_vSinRep]=v.vectorPrincipal[i];
            i_vSinRep++;
        }
        index=v.vectorPrincipal[i];
    }
    //cout<<v.vectorPrincipal<<endl;
    for(i=0; i<i_vSinRep;i++){
        if(i==0){
            x=10;
		}else{
			x=x+(20*(vSinRep[i]-vSinRep[i-1]));
        }
        sprintf(num, "|%d|", vSinRep[i]);
        outtextxy(x+40, y+10, num);
        if(i<(i_vSinRep)){
            int l=vBase[i];
            for(j=0;j<l;j++){
                circle(x+50, y-=10, 2);
            }
            y=400;
        }
    }
    x=50;
    moveto(2, 410);
    outtext("Dato:");
    
    moveto(20, 200);
    lineto(20, 400);
    lineto(x+(20*amplitud)+30, 400);
    system("pause");
    closegraph();
}

void histogramas(){
    int x=50, y=600, ampli=0, k=0, z=0, contador=0, vFrecuencias[100], resta=0, limInferior=0, l=0;
    float vMarcaClase[100];
    char num[6];

    k=sqrt(v.n);
    resta=v.vectorPrincipal[v.n-1]-v.vectorPrincipal[0];
    ampli=int(resta/k)+1;
    limInferior=v.vectorPrincipal[0];

    do{
        for(i=0; i<v.n; i++){
            if(v.vectorPrincipal[i]>=limInferior && v.vectorPrincipal[i]<(limInferior+ampli)){
                contador++;
            }
        }
        vMarcaClase[z]=float((limInferior+(ampli))/2);
        vFrecuencias[z]=contador;
        limInferior+=ampli;
        z++;
        contador=0;
    }while(z<k);

    int color=4, relleno=1;

    initwindow(x+(k*60)+50, y+100);
    for (i=0; i<k; i++){
        setfillstyle(relleno, color+i);
        l=vFrecuencias[i];
        bar(x, y-(l*15), x+40, y);
        sprintf(num, "%d", l);
        outtextxy(x+15, y-(l*15)+10, num);
        x+=60;
    }
    x=50, y=600;
    for(i=0; i<k;i++){
        l=vMarcaClase[i];
        sprintf(num, "%d", l);outtextxy(x, y+40, num);
        x+=60;
    }

    for(i=0;i<=30;i++){
        l=i;
        sprintf(num, "%d", l);
        outtextxy(2, 592-(15*i), num);
        if(i%2==0){
            line(10, 599-(15*i), x, 599-(15*i));
        }
    }
    moveto(2, 640);
    outtext("Clase: ");
    moveto(20, 200);
    lineto(20, 600);
    lineto(x, 600);
    system("pause");
    closegraph();
}

void moda(){
    int cont1=0, cont2=0;
    float moda=0;

    for(i=0; i<v.n; i++){
        for(j=0; j<v.n; j++){
            if(v.vectorPrincipal[i]==v.vectorPrincipal[j] && i!=j)cont1++;
        }
        if(cont1>cont2){
            cont2=cont1;
            moda=v.vectorPrincipal[i];
        }
        cont1=0;
    }
    printf("\nLa moda es el numero: %f\n", moda);
}

void mediana(){
    int m=0;
    float mediana=0;

    if(v.n%2!=0){
        m=(v.n/2);
        printf("\nLa mediana es: %d \n", v.vectorPrincipal[m]);
    }else if ((v.n%2)==0){
        m=(v.n/2);
        mediana = (v.vectorPrincipal[m]+v.vectorPrincipal[m-1])/2;
        printf("\nLa mediana es: %f: \n", mediana);
    }

}

void media(){
    float sum=0, media=0;

    for(i=0;i<v.n;i++){
        sum+=float(v.vectorPrincipal[i]);
    }
    media=sum/v.n;
    printf("\nLa media es %f: \n", media);
}

void varianza_uno(){
    float sum=0, media=0, varianza=0;
    int contador=1;
    
    for(i=0;i<v.n;i++){
        contador++;
        sum+=float(v.vectorPrincipal[i]);
    }
    contador++;
    media=sum/v.n;
    sum=0;

    for(i=0;i<v.n;i++){
        contador++;
        sum+=pow(v.vectorPrincipal[i]-media, 2);
    }

    contador++;
    varianza=sum/(v.n-1);
    cout<<"LA VARIANZA ES: "<<varianza<<endl<<"Los pasos requeridos para realizar esta operacion fueron: "<<contador<<endl;
}

void varianza_dos(){
    double sum1=0, sum2=0, sqrt=0;
    float div=0, varianza=0;
    int contador=1;

    for(i=0;i<v.n;i++){
        contador++;
        sum1+=pow(float(v.vectorPrincipal[i]), 2);
    }
    cout<<sum1<<endl;

    for(i=0; i<v.n;i++){
        contador++;
        sum2+=float(v.vectorPrincipal[i]);
    }
    contador++;
    sqrt=pow(sum2, 2);
    contador++;
    div=sqrt/v.n;
    contador++;
    varianza=((sum1-div)/(v.n-1));
    cout<<"LA VARIANZA ES: "<<varianza<<endl<<"Los pasos requeridos para realizar esta operacion fueron: "<<contador<<endl;
}
void reorganizarDatos(int n, float X[100], float Y[100]){
	for(i=0;i<n;i++){
		//X[i]=X[i]/10;
		//Y[i]=Y[i]/10;
	}
}
void minimosCuadrados(){
    float datosX[100], sumx=0, datosY[100], sumy=0, XY[100], sumxy=0, X2[100], sumx2=0;
    float m, b, X, Y;
    int n;
    cout<<"INGRESA LA CANTIDAD (n) DE DATOS:\n";
    cin>>n;
    cout<<"INGRESA LOS DATOS:"<<endl;
    for(i=0;i<n;i++){
    cout<<"X["<<i+1<<"]->";
    cin>>datosX[i];
    cout<<"Y["<<i+1<<"]->";
    cin>>datosY[i];
    }
    /*for(i=0;i<n;i++){
		if(datosX[i]>=100){
			reorganizarDatos(n, datosX, datosY);
			break;
		}
    }*/
    for(i=0;i<n;i++){
        XY[i]=datosX[i]*datosY[i];
        X2[i]=pow(datosX[i],2);
    }
    float nuevoV[100];
    for(i=0;i<n;i++){
        sumx+=datosX[i];
        sumy+=datosY[i];
        sumxy+=XY[i];
        sumx2+=X2[i];
        nuevoV[i]=datosX[i];

    }
    int v_temp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(nuevoV[i] < nuevoV[j]){
                v_temp=nuevoV[i];
                nuevoV[i]=nuevoV[j];
                nuevoV[j]=v_temp;
            }
        }
    }

    int auxmax, auxmin;
	for(i=0;i<n;i++){
        //cout<<datosX[i]<<endl;
		for(j=0;j<n;j++){
			if(datosX[i]==nuevoV[n-1]){
				auxmax=i;
			}
			if(datosX[i]==nuevoV[0]){
				auxmin=i;	
			}
		}
	}

    m=((sumxy-((sumx*sumy)/n))/(sumx2-(pow(sumx,2)/n)));
    b=((sumy/n)-(m*(sumx/n)));


    float pmax,pmin, auxiliar;
    cout<<nuevoV[n-1]<<endl<<nuevoV[0]<<endl;
    pmax=(m*nuevoV[n-1])+b;
    pmin=(m*nuevoV[0])+b;

	
    cout<<pmax<<endl<<pmin<<endl<<endl;
    
    initwindow(800, 800);
    

    for(i=0;i<n;i++){
        circle(80+(datosX[i]*20),(620-(datosY[i]*20)), 4);
    }

    for(i=0;i<=31+1;i++){
        circle(80+(20*i), 620, 2);
	}
	for(i=0;i<=31+1;i++){
		circle(80,620-(20*i) ,2);
	}
    
    moveto(80, 620);
    linerel(0, -600);
    moveto(80, 620);
    linerel(640, 0);
    if(m>0){
    	moveto(80+(nuevoV[0]*20), 620-(pmin*20));
	    linerel( 0+(nuevoV[n-1]*20), 0-(pmax*20));
	}else if(m<0){
        cout<<"hola soy menor";
		line(80+(nuevoV[0]*20), 620-(pmin*20), 80+(nuevoV[n-1]*20), 620-(pmax*20));
	}
	outtextxy(80, 620+80, "LA ECUACION DE LA RECTA ES: ");
	char ecu[100];
    sprintf(ecu, "Y = %f X + %f ", m, b);
    outtextxy(350, 700, ecu);

    system("pause");
    closegraph();
}
