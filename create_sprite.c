/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite
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

sprite_t create_background(void)
{
    sprite_t background;

    background.texture = sfTexture_createFromFile(BACKGROUND, NULL);
    background.sprite = sfSprite_create();
    background.scale.x = WIDTH / 1920.0;
    background.scale.y = HEIGHT / 1080.0;
    sfSprite_setTexture(background.sprite, background.texture, sfTrue);
    return background;
}

sprite_t create_bird1(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE;
    sprite.rect.top = TOP_SPRITE;
    sprite.rect.width = WIDTH_SPRITE;
    sprite.rect.height = HEIGHT_SPRITE;
    sprite.start_position.x = -WIDTH / 7;
    sprite.start_position.y = rand() % 400;
    sprite.speed.x = SPEED_SPRITE;
    sprite.speed.y = 0;
    sprite.scale.x = 1.1 * (WIDTH / 1920.0);
    sprite.scale.y = 1.1 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    return sprite;
}

sprite_t create_bird2(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE2, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE2;
    sprite.rect.top = TOP_SPRITE2;
    sprite.rect.width = WIDTH_SPRITE2;
    sprite.rect.height = HEIGHT_SPRITE2;
    sprite.start_position.x = WIDTH + WIDTH / 7;
    sprite.start_position.y = rand() % 400;
    sprite.speed.x = SPEED_SPRITE2;
    sprite.speed.y = 0;
    sprite.scale.x = 1.1 * (WIDTH / 1920.0);
    sprite.scale.y = 1.1 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    return sprite;
}

sprite_t create_cat(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE3, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE3;
    sprite.rect.top = TOP_SPRITE3;
    sprite.rect.width = WIDTH_SPRITE3;
    sprite.rect.height = HEIGHT_SPRITE3;
    sprite.start_position.x = -WIDTH / 7;
    sprite.start_position.y = HEIGHT / 1.355;
    sprite.speed.x = SPEED_SPRITE3;
    sprite.speed.y = 0;
    sprite.scale.x = 1.1 * (WIDTH / 1920.0);
    sprite.scale.y = 1.1 * (HEIGHT / 1080.0);
    sprite.dead = 1;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    return sprite;
}

sprite_t create_confetti(void)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(TEXTURE6, NULL);
    sprite.sprite = sfSprite_create();
    sprite.rect.left = LEFT_SPRITE6;
    sprite.rect.top = TOP_SPRITE6;
    sprite.rect.width = WIDTH_SPRITE6;
    sprite.rect.height = HEIGHT_SPRITE6;
    sprite.start_position.x = WIDTH / 2 - (WIDTH_SPRITE6 / 2);
    sprite.start_position.y = HEIGHT / 2;
    sprite.speed.x = SPEED_SPRITE6;
    sprite.speed.y = 0;
    sprite.scale.x = 1.1 * (WIDTH / 1920.0);
    sprite.scale.y = 1.1 * (HEIGHT / 1080.0);
    sprite.dead = 0;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, sprite.start_position);
    return sprite;
}
