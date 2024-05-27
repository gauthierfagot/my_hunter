/*
** EPITECH PROJECT, 2023
** sprite_animation
** File description:
** sprite_animation
*/
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_hunter.h"

void sprite_animation_bird1(sfIntRect *rect)
{
    if (rect->left != LAST_LEFT_SPRITE)
        rect->left += WIDTH_SPRITE;
    else
        rect->left = LEFT_SPRITE;
}

void sprite_animation_bird2(sfIntRect *rect)
{
    if (rect->left != LAST_LEFT_SPRITE2)
        rect->left += WIDTH_SPRITE2;
    else
        rect->left = LEFT_SPRITE2;
}

void sprite_animation_cat1(sfIntRect *rect)
{
    if (rect->left != LAST_LEFT_SPRITE3)
        rect->left += WIDTH_SPRITE3;
    else
        rect->left = LEFT_SPRITE3;
}

void sprite_animation_confetti(sprites_t *sprites, sfIntRect *rect)
{
    sfVector2f reset_position = {rand() % WIDTH - (WIDTH_SPRITE6 / 2),
        sprites->confetti.start_position.y};

    if (rect->top != LAST_LEFT_SPRITE6) {
        rect->top += HEIGHT_SPRITE6;
        if (rect->left != LAST_LEFT_SPRITE6)
        rect->left += WIDTH_SPRITE6;
        else
            rect->left = LEFT_SPRITE6;
    } else {
        if (rect->left != LAST_LEFT_SPRITE6)
        rect->left += WIDTH_SPRITE6;
        else {
            rect->left = LEFT_SPRITE6;
            rect->top = TOP_SPRITE6;
            sfSprite_setPosition(sprites->confetti.sprite, reset_position);
        }
    }
}
