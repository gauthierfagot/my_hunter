/*
** EPITECH PROJECT, 2023
** sprite_animation_dead
** File description:
** sprite_animation_dead
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

void sprite_animation_bird_dead(sprites_t *sprites, sfIntRect *rect)
{
    if (rect->left != LAST_LEFT_SPRITE5)
        rect->left += WIDTH_SPRITE5;
    else {
        rect->left = 0;
        sprites->bird1.dead = 0;
        sprites->bird2.dead = 0;
    }
}

void sprite_animation_cat1_dead(sfIntRect *rect, menu_t *menu)
{
    if (rect->left != LAST_LEFT_SPRITE4) {
        rect->left += WIDTH_SPRITE4;
    } else if (menu->life > 0) {
        menu->life = 0;
        sfMusic_stop(menu->sounds->music);
        sfSound_play(menu->sounds->end_sound);
    }
}
