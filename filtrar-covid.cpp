/*
Nom: Theo Moreno Lomero
DNI: 45722473Z


Estratègia: 

  --> Utilitzem un bucle principal que llegeixi caràcter per caràcter fins que arribi al '#'.
  --> Crear un comptador de comes per saber en quins camps estem i un comptador de caracter.
  --> Crem tres variables addicionals que emmagatzemin les tres primeres lletres del nostre municipi en aquest Lleida, i que es reiniciïn en cada canvi de camp(va en funcio del contador de comes).
  --> Per ultim utilitzem un condicional que indiqui quan hem trobat el nom del municipi, i així llegir o no la resta de la línia.
*/


#include <stdio.h>
#define isMUNICIPI 5 // Posició on estroba el nom del Municipi
#define LIMIT 7 // Posició on es troba el tipus de descripció

int main() { 

   int counter; // Comptador de caràcters			
   int counter_comma; // Comptador de comes
   int counter_character_space; // Comptador de caràcters per camps
   bool LLEIDA; // Condicional per identifica Leida
   char character, char1, char2, char3; // Un variable que llegeix el caràcter i tres variables per emmagatzema les tres primeres lletres del municipi

   scanf("%c", &character);
 
  //Inicialització
    counter = 0;
    counter_comma = 1;
    counter_character_space = 0;
    LLEIDA = false;


   while(character != '#'){ // Mentres que no trobi '#'			
      
      //Incrementem les variables
      counter_character_space++;
      counter++;
            
      //Si es llegeix una coma el comptador de caràcters el reiniciem. Reiniciem els caràcters amb un espai
      // per a evitar que es quedin emmagatzemats caràcters de camps anteriors.

      if(character == ','){			
        char1 = ' '; 
        char2 = ' ';
        char3 = ' ';
        counter_comma++;
        counter_character_space = 0; 
        
      }

      
      //Si trobem un return  reiniciem els contadors.En el cas d'haver trobat el municipi i haver arribat al final de línia, 
      //indiquem que no hem trobat en el municipi i així continuem llegint.

      else if(character == '\n'){		
        char1 = ' '; 
        char2 = ' ';
        char3 = ' ';
        LLEIDA = false;
        counter_comma = 1;
        counter_character_space = 0;
       
      }
      
      // Assignem els tres primers caràcters

      if(counter_character_space == 1){		
        char1 = character; 
      }
      
      else if(counter_character_space == 2){
        char2 = character;  
      }
      
      else if(counter_character_space == 3){
        char3 = character; 
      }
      
      scanf("%c", &character);  //Tornem a llegir el següent caracter

       
      //Si el contador de coma coincideix amb la constant i les tres primeres lletres coincideixen amb “Lle” indiquem que hem
      //trobat el municipi Lleida
       
      if(counter_comma == isMUNICIPI && (char1 == 'L' && char2 == 'l' && char3 == 'e')){
        LLEIDA = true;
      }

      
       //Si hem trobat el municipi i el contador de comes és superior al limit i encara no em arribat al return, imprimim lo seguent.

      if(LLEIDA == true && counter_comma > LIMIT){
         printf("%c", character);
      }
   }
    printf ("#\n");
}
