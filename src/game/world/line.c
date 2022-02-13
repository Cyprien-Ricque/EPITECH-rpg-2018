/*
** EPITECH PROJECT, 2018
** displaying
** File description:
** displaying
*/

#include "my_rpg.h"
#include "world.h"

void draw_line_b(sfRenderWindow *window, sfVector2f point1, sfVector2f point2,
    sfVertexArray *array)
{
    sfVertex vertex1 = {.position = point1, .color = sfBlue};
    sfVertex vertex2 = {.position = point2, .color = sfRed};

    sfVertexArray_clear(array);
    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_setPrimitiveType(array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, array, NULL);
}

void draw_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2,
    sfVertexArray *array)
{
    sfVertex vertex1 = {.position = point1, .color = sfBlack};
    sfVertex vertex2 = {.position = point2, .color = sfBlack};

    sfVertexArray_clear(array);
    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_setPrimitiveType(array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, array, NULL);
}
