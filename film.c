//
//  film.c
//  C_Coursework
//
//  Created by White, Robin on 05/04/2019.
//  Copyright © 2019 White, Robin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "film.h"

typedef struct filmStruct
{
    char *title, *ageRating, *genre;
    int duration, year;
} filmData;

/**
 Get method for film release year

 @param film containing year
 @return integer value of the films release year
 */
int film_getYear(const filmData *film)
{
    return film->year;
}

/**
Get method for film duration

 @param film containing duration
 @return return film duration
 */
int film_getDuration(const filmData *film)
{
    return film->duration;
}

/**
 Get method for film title

 @param film containing title
 @return film title
 */
char *film_getTitle(const filmData *film)
{
    return film->title;
}

/**
 Get method for film age rating

 @param film containing age ratine
 @return film age rating
 */
char *film_getRating(const filmData *film)
{
    return film->ageRating;
}

/**
 Get method for film genre

 @param film containing genre
 @return genre of film
 */
char *film_getGenre(const filmData *film)
{
    return film->genre;
}

/**
 Create a new film:
 allocate memory for a new film, generates error message if
 allocation fails

 @param title of film
 @param year release date
 @param ageRating age rating of film
 @param genre description of film
 @param duration of film
 @return newly created film
 */
filmData *film_new(char *title, int year, char *ageRating, char *genre, int duration)
{
    //Allocate memory for new film
    filmData *film = malloc(sizeof(filmData));

    //Null check for memory allocation
    if (!film)
    {
        fprintf(stderr, "Error: There is not enough memory in"
                        "filmData_new().\n");
        exit(EXIT_FAILURE);
    }

    //TODO wruite here why I are not using malloc and copying
    film->title = title;
    film->year = year;
    film->ageRating = ageRating;
    film->genre = genre;
    film->duration = duration;

    return film;

    exit(EXIT_SUCCESS);
}

void film_print(const filmData *film)
{
    printf("\nTitle:                %s\n"
           "Release Year:         %d\n"
           "Age Rating:           %s\n"
           "Genre:                %s\n"
           "Duration:             %d\n",
           film_getTitle(film),
           film_getYear(film),
           film_getRating(film),
           film_getGenre(film),
           film_getDuration(film));
}

/**
 Method to free a movie from memory

 @param film that will be freed from memory
 */
void film_free(filmData *film)
{
    free(film);
}
