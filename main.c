#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Usage: %s <Nazwa pliku>", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *f = fopen((char*)argv[1], "r");
    if (f == NULL) {
        printf("Blad otwierania pliku");
        return EXIT_FAILURE;
    }

    int i = 1; 
    int j = 0;
    char buff[CHAR_MAX];
    char wynik[CHAR_MAX];
    while (fgets(buff, 127, f) != NULL) {
        if (i == 40) {
            wynik[j] = buff[9];
            j++;
            i = 0;
        }
        i++;
    }
    strcpy(&wynik[j], "\0");

    printf("%s", wynik);

    fclose(f);
    return EXIT_SUCCESS;
}
