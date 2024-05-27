/*
** EPITECH PROJECT, 2023
** set_sprite
** File description:
** set_sprite
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
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "my_hunter.h"

static void set_text(text_t *text, sfRenderWindow *window)
{
    sfText_setFont(text->text, text->font);
    sfText_setScale(text->text, text->scale);
    sfText_setString(text->text, text->str);
    sfText_setColor(text->text, text->color);
    sfRenderWindow_drawText(window, text->text, NULL);
}

void set_text_game(menu_t *menu, texts_t *texts, sfRenderWindow *window)
{
    texts->score_board.str = int_to_str(menu->score);
    texts->life_board.str = int_to_str(menu->life);
    set_text(&texts->score_text, window);
    set_text(&texts->score_board, window);
    set_text(&texts->life_text, window);
    set_text(&texts->life_board, window);
}

void set_sprite(sfRenderWindow *window, sprite_t *sprite)
{
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void set_sprites_game(sfRenderWindow *window, sprites_t *sprites)
{
    if (sprites->cat1.dead != 2) {
        set_sprite(window, &sprites->bird1);
        set_sprite(window, &sprites->bird2);
        if (sprites->bird1.dead == 1 || sprites->bird2.dead == 1) {
            sfSprite_setPosition(sprites->bird_dead.sprite,
                sprites->bird_dead.start_position);
            set_sprite(window, &sprites->bird_dead);
        }
        if (sprites->cat1.dead == 0)
            set_sprite(window, &sprites->cat1);
    }
    if (sprites->cat1.dead == 2) {
        sfSprite_setPosition(sprites->cat1_dead.sprite,
            sprites->cat1_dead.start_position);
        set_sprite(window, &sprites->cat1_dead);
    }
}

void set_cursor(sfRenderWindow *window, sprites_t *sprites)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f tmp;

    tmp.x = mouse.x;
    tmp.y = mouse.y;
    sfSprite_setPosition(sprites->cursor.sprite, tmp);
    sfRenderWindow_drawSprite(window, sprites->cursor.sprite, NULL);
}

void set_sprites(sfRenderWindow *window, sprites_t *sprites, menu_t *menu)
{
    sfSprite_setScale(sprites->background.sprite, sprites->background.scale);
    sfRenderWindow_drawSprite(window, sprites->background.sprite, NULL);
    set_text_game(menu, menu->texts, window);
    if (sprites->start.dead == 0) {
        sfRenderWindow_drawSprite(window, sprites->start.sprite, NULL);
    } else {
        if (menu->life > 0 && menu->score != WIN) {
            set_sprites_game(window, sprites);
        }
        if (menu->score == WIN) {
            set_sprite(window, &sprites->confetti);
        }
        if (menu->life <= 0) {
            sfRenderWindow_drawSprite(window, sprites->game_over.sprite, NULL);
        }
    }
    set_cursor(window, sprites);
}
