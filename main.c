#include <stdio.h>
#include <stdbool.h>

int main() 
{
    char guess, word[] = "hello";
    char mot_cache[] = {'_', '_', '_', '_', '_'};
    int chances = 0, max_chances = 3;
    int i;
    int lettres_found = 0;

    while (lettres_found < 5 && chances < max_chances) 
    {
        printf("Le mot est : ");
        for (i = 0; i < 5; i++) 
        {
            printf("%c ", mot_cache[i]);
        }

        printf("\n Entrer une lettre : ");
        scanf(" %c", &guess);

        bool found = false;
        for (i = 0; i < 5; i++) 
        {
            if (word[i] == guess && mot_cache[i] == '_')   // I cant replace: mot_cache[i] == '_'  with  lettres_found < 5,
            {                                              //  cuz if i do : logic ruin, mot_cache[i] == '_' means it found once, the other will still count the already founds as correct answer
                mot_cache[i] = guess;
                found = true;
                lettres_found++;
            }
        }

        if (found == false)    // same same   if (!found)
        {
            chances++;
            printf("Lettre incorrect. Il vous reste %d essais .\n", max_chances - chances);
        }
    }

    if (lettres_found == 5) 
    {
        printf("Fe'licitations, le mot est: %s\n", word);
    } 
    else 
    {
        printf("Game Over");
    }

    return 0;
}


