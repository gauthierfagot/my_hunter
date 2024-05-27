/*
** EPITECH PROJECT, 2023
** events
** File description:
** events
*/
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/InputStream.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "my_hunter.h"

static void check_menu(sprites_t *sprites, menu_t *menu, int score)
{
    if (score == menu->score) {
        menu->life --;
        sfSound_play(menu->sounds->damage_sound);
    }
    if (menu->life <= 0) {
        sfMusic_stop(menu->sounds->music);
        sfSound_play(menu->sounds->end_sound);
    }
    if (menu->score == WIN) {
        sfMusic_stop(menu->sounds->music);
        sfSound_play(menu->sounds->win_sound);
    }
    if (menu->score == 10 && sprites->cat1.dead == 1) {
        sprites->cat1.dead = 0;
        sfSprite_setPosition(sprites->cat1.sprite,
            sprites->cat1.start_position);
    }
}

static void click_bird(sfVector2i *mouse, sprite_t *sprite, sprites_t *sprites,
    menu_t *menu)
{
    sfVector2f position = sfSprite_getPosition(sprite->sprite);
    sfVector2f reset_position = {sprite->start_position.x,
        rand() % HEIGHT / 2};

    if (mouse->x > position.x && mouse->x < position.x + sprite->rect.width) {
        if (mouse->y > position.y && mouse->y < position.y +
            sprite->rect.height) {
            sfSprite_setPosition(sprite->sprite, reset_position);
            sprite->speed.x *= 1.1;
            menu->score ++;
            sfSound_play(menu->sounds->dead_sound);
            sprite->dead = 1;
            sprites->bird_dead.start_position = position;
            return;
        }
    }
}

static void click_cat(sfVector2i *mouse, sprite_t *sprite, sprites_t *sprites)
{
    sfVector2f position = sfSprite_getPosition(sprite->sprite);

    if (mouse->x > position.x && mouse->x < position.x + sprite->rect.width) {
        if (mouse->y > position.y && mouse->y < position.y +
            sprite->rect.height) {
            sprite->dead = 2;
            sprites->cat1_dead.start_position.x = position.x;
            sprites->cat1_dead.start_position.y = position.y - HEIGHT_SPRITE3;
        }
    }
}

void restart_game(sprites_t *sprites, menu_t *menu)
{
    sfSprite_setPosition(sprites->bird1.sprite, sprites->bird1.start_position);
    sfSprite_setPosition(sprites->bird2.sprite, sprites->bird2.start_position);
    sprites->bird1.speed.x = SPEED_SPRITE;
    sprites->bird2.speed.x = SPEED_SPRITE2;
    sprites->cat1.dead = 1;
    sprites->cat1_dead.rect.left = LEFT_SPRITE4;
    menu->score = 0;
    menu->life = LIFE;
    sprites->start.dead = 0;
    sfSound_stop(menu->sounds->end_sound);
    sfSound_stop(menu->sounds->win_sound);
    sfMusic_play(menu->sounds->waiting_music);
}

void check_mouse_click(sfRenderWindow *window, sprites_t *sprites,
    menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int score = menu->score;

    click_bird(&mouse, &sprites->bird1, sprites, menu);
    click_bird(&mouse, &sprites->bird2, sprites, menu);
    click_cat(&mouse, &sprites->cat1, sprites);
    check_menu(sprites, menu, score);
}

void start_game(sprites_t *sprites, menu_t *menu)
{
    sprites->start.dead = 1;
    sfMusic_stop(menu->sounds->waiting_music);
    sfMusic_setLoop(menu->sounds->music, sfTrue);
    sfMusic_play(menu->sounds->music);
}

void analyze_events(sfRenderWindow *window, sfEvent *event, sprites_t *sprites,
    menu_t *menu)
{
    int life = menu->life;

    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtKeyPressed && sprites->start.dead == 0) {
            start_game(sprites, menu);
        }
        if (event->type == sfEvtMouseButtonPressed && menu->life > 0 &&
            menu->score != WIN && sprites->start.dead == 1) {
            check_mouse_click(window, sprites, menu);
        }
        if (event->type == sfEvtKeyPressed && (life <= 0 ||
            menu->score == WIN)) {
            restart_game(sprites, menu);
        }
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
