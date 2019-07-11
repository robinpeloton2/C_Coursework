//
//  film.h
//  C_Coursework
//
//  Created by White, Robin on 05/04/2019.
//  Copyright © 2019 White, Robin. All rights reserved.
//

#ifndef film_h
#define film_h

#include <stdio.h>



typedef struct filmStruct filmData;

filmData* film_new(char *title, int year, char *ageRating,
                       char *genre, int duration);

/*
 * Get method to get release year of a film
 *
 * @param pointer to movie containing year
 * @return year int
 */
int film_getYear(const filmData *film);

/*
 * Get method to get duration of a film
 *
 * @param pointer to movie containing duration
 * @return duration int
 */
int film_getDuration(const filmData *film);

/*
 * Get method to get title of a film
 *
 * @param pointer to movie containing title
 * @return title char
 */
char *film_getTitle(const filmData *film);

/*
 * Get method to get age rating of a film
 *
 * @param pointer to movie containing ageRating
 * @return ageRating char
 */
char *film_getRating(const filmData *film);

/**
 Get method for genre of film

 @param film to get genre from
 @return genre of film
 */
char *film_getGenre(const filmData *film);

/**
 Method to print a film to the console

 @param film to be printed
 */
void film_print(const filmData *film);

/**
 Method to free a film from memory

 @param film to be free'd from memory
 */
void film_free(filmData *film);

#endif /* film_h */


