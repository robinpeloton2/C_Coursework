//
//  moviedatabase.c
//  C_Coursework
//
//  Created by White, Robin on 05/04/2019.
//  Copyright © 2019 White, Robin. All rights reserved.
//

#include "moviedatabase.h"
#include "film.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 Method to create a new MovieDatabase of film's
 Generates an error message if memory allocation fails.
 */
List *list_new()
{
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory in list_new()\n");

        exit(EXIT_FAILURE);
    }

    list->first = NULL;
    list->last = NULL;

    return list;
}

void list_insert(List *list, filmData *film)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory in list_insert()\n");

        exit(EXIT_FAILURE);
    }

    node->film = film;
    node->next = list->first;

    if (list->first == NULL)
    {
        list->first = list->last = node;
    }
    else
    {
        list->first = node;
    }
}

int list_length(List *list)
{
    int length = 0;

    for (Node *node = list->first; node != NULL; node = node->next)
    {
        length++;
    }

    return length;
}

filmData *list_head(List *list)
{
    if (list->first == NULL)
    {
        fprintf(stderr, "Error: attempt to return the head of an empty list.");

        exit(EXIT_FAILURE);
    }

    filmData *film = list->first->film;

    Node *node = list->first;

    if (list->first == list->last)
    {
        list->first = list->last = NULL;
    }
    else
    {
        list->first = list->first->next;
    }

    free(node);

    return film;
}

filmData *list_tail(List *list)
{
    if (list->first == NULL)
    {
        fprintf(stderr, "Error: attempt to return the tail of an empty list.");

        exit(EXIT_FAILURE);
    }

    filmData *film = list->last->film;

    Node *tail = list->last;

    if (list->first == list->last)
    {
        list->first = list->last = NULL;
    }
    else
    {
        Node *node;

        for (node = list->first; node->next != tail; node = node->next)
            ;

        list->last = node;
        list->last->next = NULL;
    }

    free(tail);

    return film;
}

void list_print(List *list)
{
    // Loop and print all nodes of the movie database
    if (list->first != NULL)
        for (Node *node = list->first; node != NULL;
             node = node->next)
        {
            // Get movie item to print
            filmData *film = node->film;

            // Print item information to console
            film_print(film);
        }
    // Else display empty message to console
    else
        printf("\nMovie Database currently empty.\n");

    exit(EXIT_SUCCESS);
}

void list_clear(List *list)
{
    while (list->first != NULL)
    {
        Node *node = list->first;

        list->first = node->next;

        free(node);
    }

    list->last = NULL;
}

//----------------------------------TASK 1---------------------------------//

/**
Sort list by year in decreasing order,
 if the list is not empty loop through and
 use the bubblesort algorithm to sort the list
 
 @param list to be sorted
 */
List *movie_task1(List *list)
{
    if (list->first != list->last) // list contains two or more films
    {
        int sorted;
        do
        {
            sorted = 1;
            for (Node *node = list->first; node->next != NULL; node = node->next)
            {
                if (film_getYear(node->film) < film_getYear(node->next->film))
                {
                    filmData *temp = node->film;
                    node->film = node->next->film;
                    node->next->film = temp;
                    sorted = 0;
                }
            }
        } while (!sorted);
    }
    printf(" ------- TASK 1 ------- \n");
    list_print(list);
    return list;
    exit(EXIT_SUCCESS);
}

//----------------------------------TASK 2---------------------------------//

/////**
//// Display the third longest film-noir in movies (Task 2)
////
List *list_filmNoir(List *list)
{

    //Create a new list of film-noir movies
    List *noir = list_new();

    //Only sort if movie contains more that 2 nodes
    if (list->first != list->last)
    {
        for (Node *node = list->first; node->next != NULL;
             node = node->next)
        {
            //initilize node pointer
            filmData *film = node->film;

            //If genre contains substring of "Film-Noir" add the film to the list "noir"
            if (strstr(film_getGenre(node->film), "Film-Noir") != NULL)
            {
                list_insert(noir, film);
            }
        }

        //Sort noir list by duration
        int sorted;
        do
        {
            sorted = 1;
            for (Node *node = noir->first; node->next != NULL; node = node->next)
            {
                if (film_getDuration(node->film) < film_getDuration(node->next->film))
                {
                    filmData *temp = node->film;
                    node->film = node->next->film;
                    node->next->film = temp;
                    sorted = 0;
                }
            }
        } while (!sorted);
    }

    //Get the current node of the list, initialize count and index values
    Node *node = noir->first;
    int count = 0;
    int index = 2;

    //Loop through the extracted noir films and find the 3rd index
    while (node != NULL)
    {

        if (count == index)
        {
            printf(" ------- TASK 2 ------- \n");
            printf("Display the third longest Film-Noir: \n");
            film_print(node->film);
        }
        count++;
        node = node->next;
    }

    // list_print(noir);

    return noir;
}

//----------------------------------TASK 3---------------------------------//

///**
// Sort movie by length of title then print the shortest title
//
// @param movie to be sorted
// @param title to be compared
// @return the shortest title in movie
// */
void list_shortTitle(const List *list)
{
    //State of sorted
    int sorted;

    //Loop while not sorted
    do
    {
        sorted = 1;
        for (Node *node = list->first; node->next != NULL;
             node = node->next)
        {
            //Get movies to be sorted
            filmData *film = node->film;
            filmData *nextFilm = node->next->film;

            //If one string is longer than the other, swap them
            // printf("%lu and %lu\n", strlen(film_getTitle(film)), strlen(film_getTitle(nextFilm)));
            if (strlen(film_getTitle(film)) > strlen(film_getTitle(nextFilm)))
            {
                filmData *temp = node->film;
                node->film = node->next->film;
                node->next->film = temp;
                sorted = 0;
            }
        }
    } while (!sorted);

    //Print the first element in the list only;
    printf(" ------- TASK 3 ------- \n");
    printf("\nFilm with the shortest title: \n");
    // film_print(list->first->film);
    // list_print(list);
    film_print(list->first->film);
}

//----------------------------------TASK 4---------------------------------//

void list_deleteR(const List *list)
{

    //Only sort if movie contains more that 2 nodes
    if (list->first != list->last)
    {
        int count = 0;

        for (Node *node = list->first; node->next != NULL;
             node = node->next)
        {
            //Get movies to be sorted
            filmData *film = node->film;

            //If string is not equal to "R" add to the count, else remove the film from the list
            if (strcmp(film_getRating(film), "R") != 0)
            {
                count++;
            }
            else
            {
                //Remove film from list
                film_free(film);
            }
        }
        printf(" ------- TASK 4 ------- \n");
        printf("All R rated movies have been removed, amount of movies remaining: "
               "%d\n\n",
               count);
    }
}
