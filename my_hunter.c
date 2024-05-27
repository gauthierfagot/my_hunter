/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_hunter
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

menu_t create_menu(sounds_t *sounds, texts_t *texts)
{
    menu_t menu;

    menu.life = LIFE;
    menu.score = 0;
    menu.sounds = sounds;
    menu.texts = texts;
    return menu;
}

void central_loop(sfRenderWindow *window, sprites_t *sprites)
{
    sfEvent event;
    sfClock *clock_anim = sfClock_create();
    sfClock *clock_mov = sfClock_create();
    sounds_t sounds = add_sounds();
    texts_t texts = add_text();
    menu_t menu = create_menu(&sounds, &texts);

    sfMusic_setLoop(menu.sounds->waiting_music, sfTrue);
    sfMusic_play(menu.sounds->waiting_music);
    while (sfRenderWindow_isOpen(window)) {
        set_sprites(window, sprites, &menu);
        sfRenderWindow_display(window);
        sprite_param(sprites, clock_anim, clock_mov, &menu);
        analyze_events(window, &event, sprites, &menu);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy_clock(clock_anim, clock_mov);
    destroy_sound(&menu);
    destroy_text(&menu);
}

int info_flag(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_hunter\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\t- The goal of this game is to reach a certain score by");
    my_putstr(" killing ducks\n");
    my_putstr("\t- However, if you miss your target, you lose a life\n");
    my_putstr("\t- The score to reach and the life are macros that you can");
    my_putstr(" modify if you wish\n");
    my_putstr("\t\t(by default, Score to reach: 20 and Life: 10)\n");
    my_putstr("\t- The speed of the ducks increases as you kill them\n");
    my_putstr("\t- When your score is equal to 10, a cat named Hoppy\n");
    my_putstr("\t\twill appear in the game: It's up to you what to do :)\n");
    my_putstr("\t- To start or restart a game, simply click on any button on");
    my_putstr(" your keyboard,\n");
    my_putstr("\t\twhen you started or finished the game\n");
    my_putstr("\nGood game to you !\n");
    return 0;
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;
    sprites_t sprites = add_sprite();

    if (argc == 2 && argv[1][0] == '-') {
        if (argv[1][1] == 'h')
            return info_flag();
    }
    if (argc >= 2)
        return 84;
    window = sfRenderWindow_create(mode, "Hunter", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, FRAME);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    central_loop(window, &sprites);
    destroy_texture(&sprites);
    destroy_sprite(&sprites);
    sfRenderWindow_destroy(window);
    return 0;
}
