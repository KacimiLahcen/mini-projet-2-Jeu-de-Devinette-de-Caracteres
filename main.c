#include <stdio.h>

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

        int trouve = 0;
        for (i = 0; i < 5; i++) 
        {
            if (word[i] == guess && mot_cache[i] == '_') 
            {
                mot_cache[i] = guess;
                trouve = 1;
                lettres_found++;
            }
        }

        if (!trouve) 
        {
            chances++;
            printf("Lettre incorrect. Il vous reste %d essais .\n", max_chances - chances);
        }
    }

    if (lettres_found == 5) 
    {
        printf("Félicitations, le mot est: %s\n", word);
    } 
    else 
    {
        printf("Game Over");
    }

    return 0;
}


