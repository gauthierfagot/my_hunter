/*
** EPITECH PROJECT, 2023
** create_sprite_dead
** File description:
** create_sprite_dead
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

sprite_t create_cat_dead(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE4, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE4;
    sprite.rect.top = TOP_SPRITE4;
    sprite.rect.width = WIDTH_SPRITE4;
    sprite.rect.height = HEIGHT_SPRITE4;
    sprite.start_position.x = 0;
    sprite.start_position.y = 0;
    sprite.speed.x = SPEED_SPRITE4;
    sprite.speed.y = 0;
    sprite.scale.x = 3 * (WIDTH / 1920.0);
    sprite.scale.y = 3 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    return sprite;
}

sprite_t create_bird_dead(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE5, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE5;
    sprite.rect.top = TOP_SPRITE5;
    sprite.rect.width = WIDTH_SPRITE5;
    sprite.rect.height = HEIGHT_SPRITE5;
    sprite.start_position.x = 0;
    sprite.start_position.y = 0;
    sprite.speed.x = SPEED_SPRITE5;
    sprite.speed.y = 0;
    sprite.scale.x = 3 * (WIDTH / 1920.0);
    sprite.scale.y = 3 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    return sprite;
}

sprite_t create_game_over(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE7, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE7;
    sprite.rect.top = TOP_SPRITE7;
    sprite.rect.width = WIDTH_SPRITE7;
    sprite.rect.height = HEIGHT_SPRITE7;
    sprite.start_position.x = WIDTH / 2 - (WIDTH_SPRITE7 * 1.5) *
        (WIDTH / 1920.0);
    sprite.start_position.y = HEIGHT / 7;
    sprite.speed.x = SPEED_SPRITE7;
    sprite.speed.y = 0;
    sprite.scale.x = 3 * (WIDTH / 1920.0);
    sprite.scale.y = 3 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    sfSprite_setScale(sprite.sprite, sprite.scale);
    return sprite;
}

sprite_t create_cursor(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE8, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE8;
    sprite.rect.top = TOP_SPRITE8;
    sprite.rect.width = WIDTH_SPRITE8;
    sprite.rect.height = HEIGHT_SPRITE8;
    sprite.start_position.x = 0;
    sprite.start_position.y = 0;
    sprite.speed.x = SPEED_SPRITE8;
    sprite.speed.y = 0;
    sprite.scale.x = 0.1 * (WIDTH / 1920.0);
    sprite.scale.y = 0.1 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setScale(sprite.sprite, sprite.scale);
    return sprite;
}

sprite_t create_start(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE9, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE9;
    sprite.rect.top = TOP_SPRITE9;
    sprite.rect.width = WIDTH_SPRITE9;
    sprite.rect.height = HEIGHT_SPRITE9;
    sprite.start_position.x = WIDTH / 2 - (WIDTH_SPRITE7 * 1.8) *
        (WIDTH / 1920.0);
    sprite.start_position.y = HEIGHT / 5;
    sprite.speed.x = SPEED_SPRITE9;
    sprite.speed.y = 0;
    sprite.scale.x = 2.5 * (WIDTH / 1920.0);
    sprite.scale.y = 2.5 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    sfSprite_setScale(sprite.sprite, sprite.scale);
    return sprite;
}
