/*
** EPITECH PROJECT, 2023
** destroy_variable
** File description:
** destroy_variable
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

void destroy_sprite(sprites_t *sprites)
{
    sfSprite_destroy(sprites->background.sprite);
    sfSprite_destroy(sprites->bird1.sprite);
    sfSprite_destroy(sprites->bird2.sprite);
    sfSprite_destroy(sprites->cat1.sprite);
    sfSprite_destroy(sprites->bird_dead.sprite);
    sfSprite_destroy(sprites->cat1_dead.sprite);
    sfSprite_destroy(sprites->confetti.sprite);
    sfSprite_destroy(sprites->cursor.sprite);
    sfSprite_destroy(sprites->start.sprite);
}

void destroy_texture(sprites_t *sprites)
{
    sfTexture_destroy(sprites->background.texture);
    sfTexture_destroy(sprites->bird1.texture);
    sfTexture_destroy(sprites->bird2.texture);
    sfTexture_destroy(sprites->cat1.texture);
    sfTexture_destroy(sprites->bird_dead.texture);
    sfTexture_destroy(sprites->cat1_dead.texture);
    sfTexture_destroy(sprites->confetti.texture);
    sfTexture_destroy(sprites->cursor.texture);
    sfTexture_destroy(sprites->start.texture);
}

void destroy_clock(sfClock *clock_anim, sfClock *clock_mov)
{
    sfClock_destroy(clock_anim);
    sfClock_destroy(clock_mov);
}

void destroy_sound(menu_t *menu)
{
    sfMusic_destroy(menu->sounds->music);
    sfMusic_destroy(menu->sounds->waiting_music);
    sfSound_destroy(menu->sounds->damage_sound);
    sfSound_destroy(menu->sounds->dead_sound);
    sfSound_destroy(menu->sounds->end_sound);
    sfSound_destroy(menu->sounds->win_sound);
}

void destroy_text(menu_t *menu)
{
    sfFont_destroy(menu->texts->score_text.font);
    sfFont_destroy(menu->texts->score_board.font);
    sfFont_destroy(menu->texts->life_text.font);
    sfFont_destroy(menu->texts->life_board.font);
    sfText_destroy(menu->texts->score_text.text);
    sfText_destroy(menu->texts->score_board.text);
    sfText_destroy(menu->texts->life_text.text);
    sfText_destroy(menu->texts->life_board.text);
}
