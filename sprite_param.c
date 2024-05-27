/*
** EPITECH PROJECT, 2023
** sprite_param
** File description:
** sprite_param
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

void sprite_limit_position(sprite_t *sprite)
{
    sfVector2f position = {0, 0};

    position = sfSprite_getPosition(sprite->sprite);
    if (position.x < -WIDTH / 7 || position.x > WIDTH + WIDTH / 7) {
        position.x = sprite->start_position.x;
        sfSprite_setPosition(sprite->sprite, position);
    }
    if (position.y < 0 || position.y > HEIGHT) {
        position.y = sprite->start_position.y;
        sfSprite_setPosition(sprite->sprite, position);
    }
}

void sprite_limit_position_cat(sprite_t *sprite)
{
    sfVector2f position = {0, 0};

    position = sfSprite_getPosition(sprite->sprite);
    if (position.x < -WIDTH / 7 || position.x > WIDTH + WIDTH / 7) {
        position.x = sprite->start_position.x;
        sfSprite_setPosition(sprite->sprite, position);
        sprite->dead = 1;
    }
    if (position.y < 0 || position.y > HEIGHT) {
        position.y = sprite->start_position.y;
        sfSprite_setPosition(sprite->sprite, position);
        sprite->dead = 1;
    }
}

void sprites_animations(sprites_t *sprites, sfClock *clock_anim, menu_t *menu)
{
    sprite_animation_bird1(&sprites->bird1.rect);
    sprite_animation_bird2(&sprites->bird2.rect);
    sprite_animation_cat1(&sprites->cat1.rect);
    if (sprites->bird1.dead == 1 || sprites->bird2.dead == 1)
        sprite_animation_bird_dead(sprites, &sprites->bird_dead.rect);
    if (sprites->cat1.dead == 2)
        sprite_animation_cat1_dead(&sprites->cat1_dead.rect, menu);
    if (menu->score == WIN)
        sprite_animation_confetti(sprites, &sprites->confetti.rect);
    sfClock_restart(clock_anim);
}

void sprite_param(sprites_t *sprites, sfClock *clock_anim, sfClock *clock_mov,
    menu_t *menu)
{
    if ((sfClock_getElapsedTime(clock_mov)).microseconds > CLOCK_MOVEMENT &&
        menu->life > 0 && sprites->start.dead == 1) {
        sfSprite_move(sprites->bird1.sprite, sprites->bird1.speed);
        sfSprite_move(sprites->bird2.sprite, sprites->bird2.speed);
        sfSprite_move(sprites->cat1.sprite, sprites->cat1.speed);
        sprite_limit_position(&sprites->bird1);
        sprite_limit_position(&sprites->bird2);
        sprite_limit_position_cat(&sprites->cat1);
        sfClock_restart(clock_mov);
    }
    if ((sfClock_getElapsedTime(clock_anim)).microseconds > CLOCK_ANIMATION &&
        menu->life > 0 && sprites->start.dead == 1) {
        sprites_animations(sprites, clock_anim, menu);
    }
}
