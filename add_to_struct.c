/*
** EPITECH PROJECT, 2023
** add_to_struct
** File description:
** add_to_struct
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

texts_t add_text(void)
{
    texts_t texts;

    texts.score_text = create_score_text();
    texts.score_board = create_score_board();
    texts.life_text = create_life_text();
    texts.life_board = create_life_board();
    return texts;
}

sounds_t add_sounds(void)
{
    sounds_t sounds;
    sfMusic *music = sfMusic_createFromFile(BACKGROUND_MUSIC);
    sfMusic *waiting_music = sfMusic_createFromFile(WAITING_MUSIC);
    sfSound *dead_sound = sfSound_create();
    sfSound *damage_sound = sfSound_create();
    sfSound *end_sound = sfSound_create();
    sfSound *win_sound = sfSound_create();

    sfSound_setBuffer(dead_sound, sfSoundBuffer_createFromFile(DEAD_SOUND));
    sfSound_setBuffer(damage_sound,
        sfSoundBuffer_createFromFile(DAMAGE_SOUND));
    sfSound_setBuffer(end_sound, sfSoundBuffer_createFromFile(END_SOUND));
    sfSound_setBuffer(win_sound, sfSoundBuffer_createFromFile(WIN_SOUND));
    sounds.music = music;
    sounds.waiting_music = waiting_music;
    sounds.dead_sound = dead_sound;
    sounds.damage_sound = damage_sound;
    sounds.end_sound = end_sound;
    sounds.win_sound = win_sound;
    return sounds;
}

sprites_t add_sprite(void)
{
    sprites_t sprites;

    sprites.background = create_background();
    sprites.bird1 = create_bird1();
    sprites.bird2 = create_bird2();
    sprites.cat1 = create_cat();
    sprites.cat1_dead = create_cat_dead();
    sprites.bird_dead = create_bird_dead();
    sprites.confetti = create_confetti();
    sprites.game_over = create_game_over();
    sprites.cursor = create_cursor();
    sprites.start = create_start();
    return sprites;
}
