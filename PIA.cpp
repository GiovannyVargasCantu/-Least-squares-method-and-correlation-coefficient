#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int main (){
   float m,b,r=0; //pendiente,interseccion,correlacion
   int n,i;  //n sirve para determinar la variable que ira dentro de nuestros arreglos de x y y,
   // i es un contador simplemente
   float sumax=0,sumay=0,sumaxy=0,sumaxsquare=0; //sumas utilizadas inicializadas en 0 
   float restax_x=0,restay_y=0,restax_x_square=0,restay_y_square=0,restax_y=0;//sumas utilizadas inicializadas en 0 
	printf ("Cuantos variables son? (Solamente contando las x o y son de la misma cantidad)\n");
	scanf ("%d",&n);
	float x[n],y[n];
   for(i=1;i<=n; i++)
   {
       printf ("Ingresar las x%d: \n",i);
       scanf ("%f",&x[i]);
       printf ("Ingresar las y%d: \n",i); //Recoge las x y y, llendo 1 por 1 en el arreglo de c/u
       scanf ("%f",&y[i]);
       sumax += x[i];  //Mantiene registro de la suma simple (sumax, sumay)
   	   sumay += y[i];
       system("cls"); //Cuestion estetica, limpia la pantalla despues de cada introduccion
   }
   for (i=1;i<=n;i++)
   {
   	 sumaxy += x[i]*y[i];
   	 sumaxsquare += x[i]*x[i];
   	 restax_x += (x[i] - (sumax/n));  
   	 restay_y += (y[i] - (sumay/n));
   	//Ahora que tenemos los valores en cada arreglo (subindice)
   	//Recorremos cada valor haciendo todas las respectivas operaciones, es importante hacer separado estas
   	//con respecto a las otras, por que las otras utilizan estas variables de este ciclo for, entonces ocasionaria
   	//problemas a la hora de correrlo.
   }
   for (i=1;i<=n;i++)
   {
   restax_x_square += pow (x[i] - (sumax/n),2);
   	restay_y_square += pow (y[i] - (sumay/n),2);
   	restax_y += (x[i] - (sumax/n))*(y[i] - (sumay/n));
   }
    
   printf ("sumax: %f \nsumay: %f\nsumaxy: %f\nsumaxsquare: %f\n",sumax,sumay,sumaxy,sumaxsquare);  
   //La linea 41 si bien no es necesaria, la mantuve para informacion adicional respecto a los valores ingresados y aparte me permitia
   //hacer una prueba de escritorio manual de mi parte y comprobar la eficiencia de este programa
   m = ((n * sumaxy) - (sumax *sumay))/((n * sumaxsquare) - (pow(sumax , 2)));  //Respectivas operaciones
   b = ((sumay * sumaxsquare)- (sumax*sumaxy))/((n*sumaxsquare)-(pow(sumax , 2))); //Respectivas operaciones
   
    printf("\n\tpendiente(m) = %f\n\tInterseccion(b) = %.2f\n",m,b);
    printf("\n\n\tValor de la variable dependiente es y = %.2f*x+ (%.2f)\n\n",m,b);
    
    printf ("Perfecto una vez obtenido los valores y el metodo de minimos cuadrados, procederemos a el coeficiente de correlacion: \n");
    printf ("Sumatoria X menos el promedio = %f\n Sumatoria de Y menos el promedio = %.2f\nSumatoria de X menos el promedio al cuadrado = %.2f\nSumatoria de Y menos el promedio al cuadrado = %.2f\nSumatoria de X menos el promedio por Sumatoria de Y menos el promedio = %.2f\n",restax_x,restay_y,restax_x_square,restay_y_square,restax_y);
   r = (restax_y) /((sqrt(restax_x_square))*(sqrt(restay_y_square)));  //Respectiva operacion.
    printf ("\n\n\tCorrecto, su coeficiente de corrrelacion es: %.3f\n",r);
    
    printf ("\n\nGracias por utilizar este software, tenga un buen dia :D\n\n");
    
    system ("pause");
    
    getch();
    
    return 0;
}


