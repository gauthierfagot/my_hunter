/*
** EPITECH PROJECT, 2023
** create_text
** File description:
** create_text
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

text_t create_score_text(void)
{
    text_t text;

    text.text = sfText_create();
    text.font = sfFont_createFromFile(FONT);
    text.str = "SCORE";
    text.position.x = WIDTH / 100;
    text.position.y = HEIGHT / 100;
    text.scale.x = 1 * (WIDTH / 1920.0);
    text.scale.y = 1 * (HEIGHT / 1080.0);
    text.color = sfWhite;
    sfText_setPosition(text.text, text.position);
    return text;
}

text_t create_score_board(void)
{
    text_t text;

    text.text = sfText_create();
    text.font = sfFont_createFromFile(FONT);
    text.str = NULL;
    text.position.x = WIDTH / 100 + (100 * (WIDTH / 1920.0));
    text.position.y = HEIGHT / 100;
    text.scale.x = 1 * (WIDTH / 1920.0);
    text.scale.y = 1 * (HEIGHT / 1080.0);
    text.color = sfYellow;
    sfText_setPosition(text.text, text.position);
    return text;
}

text_t create_life_text(void)
{
    text_t text;

    text.text = sfText_create();
    text.font = sfFont_createFromFile(FONT);
    text.str = "LIFE";
    text.position.x = WIDTH / 100 + (WIDTH - (150 * (WIDTH / 1920.0)));
    text.position.y = HEIGHT / (HEIGHT - 100);
    text.scale.x = 1 * (WIDTH / 1920.0);
    text.scale.y = 1 * (HEIGHT / 1080.0);
    text.color = sfWhite;
    sfText_setPosition(text.text, text.position);
    return text;
}

text_t create_life_board(void)
{
    text_t text;

    text.text = sfText_create();
    text.font = sfFont_createFromFile(FONT);
    text.str = NULL;
    text.position.x = WIDTH / 100 + (WIDTH - (70 * (WIDTH / 1920.0)));
    text.position.y = HEIGHT / (HEIGHT - 100);
    text.scale.x = 1 * (WIDTH / 1920.0);
    text.scale.y = 1 * (HEIGHT / 1080.0);
    text.color = sfRed;
    sfText_setPosition(text.text, text.position);
    return text;
}
