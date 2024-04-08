#pragma once
#define SIZE 40
#define UNKNOWN -1
#define MIN_PLAYER2 -10
#define MAX_PLAYER1 10
#define PLAYER1 1
#define PLAYER2 2
#define BEST 1000
#define WORST -1000
#define TIE 0
#define FOUND 1
#define NOT_FOUND 0

struct game {
	int** board;
	int player_win = UNKNOWN;
	int height, width, amount_win;
	int who_win;
};

//wyrysowywanie pozycji
void draw(game* new_game);
//stworzenie tablicy o rozmiarze planszy
void create(game* new_game, int N, int M, int K);
//sprawdzenie wygranej
int check_win(game* new_game);
//wygenerowanie wszystkich mozliwych ruchow gracza
void gen_all_pos_mov(game* new_game, int player);
//wygenerowanie wszystkich mozliwych ruchow gracza, lub jednego jesli jest on wygrywajacy/konczacy gre
void gen_all_pos_mov_cut_if_game_over(game* new_game, int player);
//rozwiazanie gry
void solve_game_state(game* new_game, int player);
//minimax
int minimax(game* new_game, bool is_max);
//czy zostaly jakies ruchy
bool is_moves_left(game* new_game);
//zwraca mniejsza liczbe
int mini(int a, int b);
//zwraca wieksza liczbe
int maxi(int a, int b);
//zwalnianie pamieci
void czysc(game* new_game);