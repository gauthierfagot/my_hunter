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

#ifndef MY_HUNTER_
    #define MY_HUNTER_

    #define LIFE 10
    #define WIN 20

    #define WIDTH 1920
    #define HEIGHT 1080
    #define FRAME 30
    #define CLOCK_ANIMATION 99000
    #define CLOCK_MOVEMENT 30000

    #define FONT "font/pixel.ttf"

    #define BACKGROUND "image/background1.jpg"

    #define BACKGROUND_MUSIC "sound/music.wav"
    #define WAITING_MUSIC "sound/waiting.wav"
    #define DEAD_SOUND "sound/dead.wav"
    #define DAMAGE_SOUND "sound/damage.wav"
    #define END_SOUND "sound/end.wav"
    #define WIN_SOUND "sound/win.wav"

    #define TEXTURE "image/image.png"
    #define LEFT_SPRITE 0
    #define TOP_SPRITE 0
    #define WIDTH_SPRITE 110
    #define HEIGHT_SPRITE 110
    #define LAST_LEFT_SPRITE 220
    #define SPEED_SPRITE 9

    #define TEXTURE2 "image/duck_reverse.png"
    #define LEFT_SPRITE2 0
    #define TOP_SPRITE2 0
    #define WIDTH_SPRITE2 110
    #define HEIGHT_SPRITE2 110
    #define LAST_LEFT_SPRITE2 220
    #define SPEED_SPRITE2 -9

    #define TEXTURE3 "image/cat.png"
    #define LEFT_SPRITE3 415
    #define TOP_SPRITE3 160
    #define WIDTH_SPRITE3 140
    #define HEIGHT_SPRITE3 100
    #define LAST_LEFT_SPRITE3 555
    #define SPEED_SPRITE3 6

    #define TEXTURE4 "image/explosion_cat.png"
    #define LEFT_SPRITE4 0
    #define TOP_SPRITE4 0
    #define WIDTH_SPRITE4 96
    #define HEIGHT_SPRITE4 96
    #define LAST_LEFT_SPRITE4 1056
    #define SPEED_SPRITE4 9

    #define TEXTURE5 "image/explosion_bird.png"
    #define LEFT_SPRITE5 0
    #define TOP_SPRITE5 0
    #define WIDTH_SPRITE5 32
    #define HEIGHT_SPRITE5 32
    #define LAST_LEFT_SPRITE5 192
    #define SPEED_SPRITE5 9

    #define TEXTURE6 "image/Confetti.png"
    #define LEFT_SPRITE6 0
    #define TOP_SPRITE6 0
    #define WIDTH_SPRITE6 512
    #define HEIGHT_SPRITE6 512
    #define LAST_LEFT_SPRITE6 3584
    #define SPEED_SPRITE6 9

    #define TEXTURE7 "image/game_over.png"
    #define LEFT_SPRITE7 0
    #define TOP_SPRITE7 0
    #define WIDTH_SPRITE7 236
    #define HEIGHT_SPRITE7 236
    #define LAST_LEFT_SPRITE7 236
    #define SPEED_SPRITE7 9

    #define TEXTURE8 "image/cursor.png"
    #define LEFT_SPRITE8 0
    #define TOP_SPRITE8 0
    #define WIDTH_SPRITE8 618
    #define HEIGHT_SPRITE8 618
    #define LAST_LEFT_SPRITE8 0
    #define SPEED_SPRITE8 9

    #define TEXTURE9 "image/start.png"
    #define LEFT_SPRITE9 0
    #define TOP_SPRITE9 0
    #define WIDTH_SPRITE9 317
    #define HEIGHT_SPRITE9 163
    #define LAST_LEFT_SPRITE9 317
    #define SPEED_SPRITE9 9

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f start_position;
    sfVector2f speed;
    sfVector2f scale;
    int dead;
} sprite_t;

typedef struct sprites {
    sprite_t background;
    sprite_t bird1;
    sprite_t bird2;
    sprite_t cat1;
    sprite_t cat1_dead;
    sprite_t bird_dead;
    sprite_t confetti;
    sprite_t game_over;
    sprite_t cursor;
    sprite_t start;
} sprites_t;

typedef struct sounds {
    sfMusic *music;
    sfMusic *waiting_music;
    sfMusic *waiting;
    sfSound *dead_sound;
    sfSound *damage_sound;
    sfSound *end_sound;
    sfSound *win_sound;
} sounds_t;

typedef struct text {
    sfText *text;
    sfFont *font;
    char *str;
    sfVector2f position;
    sfVector2f scale;
    sfColor color;
} text_t;

typedef struct texts {
    text_t score_text;
    text_t score_board;
    text_t life_text;
    text_t life_board;
} texts_t;

typedef struct menu {
    int life;
    int score;
    texts_t *texts;
    sounds_t *sounds;
} menu_t;

sprite_t create_background(void);
sprite_t create_bird1(void);
sprite_t create_bird2(void);
sprite_t create_cat(void);
sprite_t create_cat_dead(void);
sprite_t create_bird_dead(void);
sprite_t create_confetti(void);
sprite_t create_game_over(void);
sprite_t create_cursor(void);
sprite_t create_start(void);

texts_t add_text(void);
sounds_t add_sounds(void);
sprites_t add_sprite(void);

void set_sprites(sfRenderWindow *window, sprites_t *sprites, menu_t *menu);

void sprite_animation_bird1(sfIntRect *rect);
void sprite_animation_bird2(sfIntRect *rect);
void sprite_animation_cat1(sfIntRect *rect);
void sprite_animation_cat1_dead(sfIntRect *rect, menu_t *menu);
void sprite_animation_bird_dead(sprites_t *sprites, sfIntRect *rect);
void sprite_animation_confetti(sprites_t *sprites, sfIntRect *rect);

text_t create_score_text(void);
text_t create_score_board(void);
text_t create_life_text(void);
text_t create_life_board(void);

void analyze_events(sfRenderWindow *window, sfEvent *event, sprites_t *sprites,
    menu_t *menu);
void sprite_param(sprites_t *sprites, sfClock *clock_anim, sfClock *clock_mov,
    menu_t *menu);

void destroy_sprite(sprites_t *sprites);
void destroy_texture(sprites_t *sprites);
void destroy_clock(sfClock *clock_anim, sfClock *clock_mov);
void destroy_sound(menu_t *menu);
void destroy_text(menu_t *menu);

int my_putstr(char const *str);
char *int_to_str(int nb);

#endif /* !MY_HUNTER_ */
