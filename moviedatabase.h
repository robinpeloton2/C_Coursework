//
//  moviedatabase.h
//  C_Coursework
//
//  Created by White, Robin on 05/04/2019.
//  Copyright © 2019 White, Robin. All rights reserved.
//

#ifndef moviedatabase_h
#define moviedatabase_h

#include <stdio.h>
#include <stdlib.h>

#include "film.h"
typedef struct _Node
{
    filmData *film;

    struct _Node *next;
} Node;

typedef struct _List
{
    Node *first;
    Node *last;
} List;

//Node Iterator
typedef Node *Iterator;

//Return first element in list
static inline Iterator list_begin(const List *list)
{
    return list->first;
}

//Return last element in list
static inline Iterator list_end(const List *list)
{
    return NULL;
}

//Get the next element in the list
static inline Iterator iterator_next(const Iterator i)
{
    return i->next;
}

////Get the current element in the list
//static inline int iterator_value(const Iterator i)
//{
//    return i-film;
//}

////Set the position of the iterator
//static inline Iterator iterator_set(Iterator i, filmData* film)
//{
//    i->film = film;
//}

/**
 Pointer to a newly created list,
 allocate memory for new list and return error
 if memory cannot be allocated.
 */
List *list_new();

//void getList(const List* list);

/**
 Pointer to list to witch a value is too be added

 @param list to be added to
 @param film to add to list
 */
void list_add(List *list, filmData *film);

/**
 Pointer to list to be inserted with a new value,
 inserts an integer at the head of the list, allocates
 memory for the new value and returns error if memory cannot be allocated

 @param list to be inserted
 @param film to insert
 */
void list_insert(List *list, filmData *film);

/**
 Pointer to a lined list structure,
 determines the number of integer values currently stored
 

 @param list to be pointed
 @return number of elements comprimising the list
 */
int list_length(List *list);

/**
 Removes the current first element of the list and
 returns it's value. If the list is empty, return
 error message

 @param list pointer
 @return value of first element in linked list
 */
filmData *list_head(List *list);

/**
 Removes the last element of the list and
 returns it's value. If the list is empty,
 return error message

 @param list pointer
 @return value of the last element in the list
 */
filmData *list_tail(List *list);

/**
 Clear all elements from list

 @param list pointer
 */
void list_clear(List *list);

/**
 Prints a linked list of integer values to the specified output
 stream

 @param list pointer
 */
void list_print(List *list);

/**
 Use bubblesort to loop through list and sort by year,
 displaying oldest first and newest last

 @param list to be sorted through
 */
List *movie_task1(List *list);
/**
 * Method that counts the numbe of entries in MovieDatabase
 *
 * @param list to be counted
 * @return Integer displaying amount of values in MovieDatabase
 */
// void list_count(List *list);

/**
 Method to return the film noir with the third longest duration

 */
List *list_filmNoir(List *list);

/**
 Find the film in MovieDatabase with the shortest title

 @param list to be sorted
 */
void list_shortTitle(const List *list);

/**
 Method to delete all R rated movies from the database

 @param list to be scanned for R rated movies
 */
void list_deleteR(const List *list);

/**
 Sort films in chronological order by year

 @param list to be sorted
 */
List *list_sort(List *list, filmData *film1, filmData *film2);

#endif /* moviedatabase_h */
