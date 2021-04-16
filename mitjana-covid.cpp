/*

Nom: Theo Moreno Lomero
DNI: 45722473Z

Estratègia:

    -->Per realitzar el codi reutilitzem codi del programa filtra-covid.
    -->Per poder treballar amb nombres enters el que fem és transformar els caràcters a enters,utilitzant la taula ASCII.
    -->El que fem és multipliquem el valor del primer número per 10 elevat a la posició màxima menys un, després hem de sumar 
        aquest valor més el següent número per 10 elevat a la posició màxima menys dos i així fins a arribar a 10^0,
        aleshores guardem el valor que ocupa cada numero en la seva posició i la posició màxima.
*/  

#include <stdio.h>
#include <math.h>
#define Zero '0'

int main() {

   char character;
   int counter; 
   int counter_line; // Comptador de línies
   int counter_space; // Comptador de camps
   int counter_character_space; //Comptador de carècters per camps
   int max_position; // Posició de caràcter
   int n1, n2, n3; // Valors dels caràcters  
   int acumulator;
   float value; // Suma
   float mitjana;
   
   scanf("%c", &character);  

   //Inicialització
    counter = 0;
    counter_line = 0;
    counter_space = 1;
    counter_character_space = 0;
    n1 = 0;
    n2 = 0;
    n3 = 0;
    value = 0;
    mitjana = 0; 


   while(character != '#'){
   
      counter_character_space++;
      counter++;


      if(character == ','){
        counter_space++;
        counter_character_space = 0;

      }
      
      else if(character == '\n'){ 
        max_position--;
        acumulator += n1*pow(10,max_position);

        max_position--;
        acumulator += n2*pow(10,max_position);

        max_position--;
        acumulator += n3*pow(10,max_position);

        value += acumulator;
        counter_line++;
        
        acumulator = 0;
        counter_space = 1;
        n1 = 0;
        n2 = 0;
        n3 = 0;
   
  }

      if(counter_space == 2){

         max_position = counter_character_space;
         if(counter_character_space == 1){
            n1 = character - Zero;
         }

         else if(counter_character_space == 2){
            n2 = character - Zero;
         }

         else if(counter_character_space == 3){
            n3 = character - Zero;
         }
      }
   
      scanf("%c", &character);
         
      if(counter_line == 4){
         mitjana = value/4;
         printf("Valor mitjana: %.2f \n", mitjana);
         counter_line = 0;
         value = 0;
      } 
   }  
}
