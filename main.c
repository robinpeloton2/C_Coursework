//
//  main.c
//  C_Coursework
//
//  Created by White, Robin on 05/04/2019.
//  Copyright © 2019 White, Robin. All rights reserved.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "film.h"
#include "moviedatabase.h"

// Buffer size for words, again larger than largest word currently in file,
// for future files.
const int STRING_BUFFER = 64;

// Buffer size for each line in file. Although the longest line is 41
// it is bigger incase line is longer.
const int LONGEST_LINE_BUFFER = 120;

char *write_field(char *line, long start_point, long string_length)
{
    char *property = (char *)malloc(sizeof(char) * string_length + 1);
    property[string_length] = 0;
    memcpy(property, line + start_point, string_length);
    return property;
}

List *read_movies(const char *fileName, List *list)
{
    // Open file in read mode
    FILE *file = fopen(fileName, "r");

    // Initialise local line variable TODO WHY 140
    char line[200];

    // Null check if file has correctly opened
    if (file == NULL)
    {
        fprintf(stderr, "Error: Unable to open '%s' in mode 'r' "
                        "in read_movies().\n",
                fileName);
        exit(EXIT_FAILURE);
    }

    // Loop each line in file
    while (fgets(line, sizeof(line), file))
    {
        //         Initialise film variables to global heap
        char *title;
        char *year;
        char *ageRating;
        char *genre;
        char *duration;

        regex_t regexpr;
        int maxGroups = 7;
        regmatch_t matchingGroups[maxGroups];
        const char *pattern = "\"(.+)\",([0-9]{4}),\"(.+)\",\"([A-Za-z/-]+)\",([0-9]+),([0-9]+)";

        if (regcomp(&regexpr, pattern, REG_EXTENDED) != 0)
        {
            printf("regcomp error\n");
        }
        else if (regexec(&regexpr, line, maxGroups, matchingGroups, 0) != 0)
        {
            printf("regexec failed\n");
        }
        else
        {
            for (int g = 1; g < maxGroups - 1; g++)
            {
                long stringLength = matchingGroups[g].rm_eo - matchingGroups[g].rm_so;
                switch (g)
                {
                case 1:
                    title = write_field(line, matchingGroups[g].rm_so, stringLength);
                    break;
                case 2:
                    year = write_field(line, matchingGroups[g].rm_so, stringLength);
                    break;
                case 3:
                    ageRating = write_field(line, matchingGroups[g].rm_so, stringLength);
                    break;
                case 4:
                    genre = write_field(line, matchingGroups[g].rm_so, stringLength);
                    break;
                case 5:
                    duration = write_field(line, matchingGroups[g].rm_so, stringLength);
                    break;
                }
            }
            //make a new film
            filmData *film = film_new(title, atoi(year), ageRating, genre, atoi(duration));

            //Insert film into list
            list_insert(list, film);
            // free(film);
        }
        regfree(&regexpr);
        // list_print(list);
    }
    // Close File
    fclose(file);

    return list;
    exit(EXIT_SUCCESS);
}

int main(int argc, const char *argv[])
{
    printf(" --- Movie Database Program --- \n\n");

    //Initialize new list
    List *list = list_new();
    printf(
        "Please enter an number corresponding to your chosen task: \n\nTask 1\nTask 2\nTask 3\nTask 4\n\nTo print all films press 5\n\n");

    int choice;
    int loop = 0;
    while (!loop)
    {

        read_movies("films.txt", list);

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            movie_task1(list);
            break;
        case 2:
            list_filmNoir(list);
            break;
        case 3:
            list_shortTitle(list);
            break;
        case 4:
            list_deleteR(list);
            break;
        case 5:
            list_print(list);
            break;
        defualt:
            printf("Please enter a valid choice");
        }
        list_clear(list);

        printf("\nEnter a new number to display a new task\n");
    }
}
