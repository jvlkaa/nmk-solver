#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "operations.h"
using namespace std;

void draw(game* new_game)
{
	for (int i = 0; i < new_game->height; i++) {
		for (int j = 0; j < new_game->width; j++) {
			printf("%d", new_game->board[i][j]);
			if (j != new_game->width - 1)
				printf(" ");
		}
		printf("\n");
	}
}

void create(game* new_game, int N, int M, int K)
{
	new_game->height = N;
	new_game->width = M;
	new_game->amount_win = K;
	new_game->player_win = NOT_FOUND;
	new_game->board = new int* [N];
	for (int i = 0; i < N; i++)
		new_game->board[i] = new int[M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			new_game->board[i][j] = 0;
	}
}

int check_win(game* new_game)
{
	int count = 1;
	int player;
	int win = NOT_FOUND;
	for (int i = 0; i < new_game->height; i++) {
		for (int j = 0; j < new_game->width; j++) {
			if (new_game->board[i][j] != 0) {
				player = new_game->board[i][j];
				int k = 1;
				//gora
				while (i + k != new_game->height && new_game->board[i + k][j] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//dol
				while (i - k >= 0 && new_game->board[i - k][j] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//lewo
				while (j + k != new_game->width && new_game->board[i][j + k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//prawo
				while (j - k >= 0 && new_game->board[i][j - k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//prawy dolny skos
				while (i + k != new_game->height && j + k != new_game->width && new_game->board[i + k][j + k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//lewy dolny skos
				while (i + k != new_game->height && j - k >= 0 && new_game->board[i + k][j - k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//lewy gorny skos
				while (i - k >= 0 && j - k >= 0 && new_game->board[i - k][j - k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
				k = 1;
				//prawy gorny skos
				while (i - k >= 0 && j + k != new_game->width && new_game->board[i][j - k] == player && win == NOT_FOUND) {
					count++;
					k++;
				}
				if (count >= new_game->amount_win && win == 0) { win = FOUND; new_game->player_win = player; }
				else { count = 1; }
			}
		}
	}
	return win;
}

void gen_all_pos_mov(game* new_game, int player)
{
	int pos = 0, pom1;
	for (int i = 0; i < new_game->height; i++) {
		for (int j = 0; j < new_game->width; j++) {
			if (new_game->board[i][j] == 0)
				pos++;
		}
	}
	pom1 = check_win(new_game);
	if (pom1 == 0) {
		printf("%d\n", pos);
		for (int i = 0; i < new_game->height; i++) {
			for (int j = 0; j < new_game->width; j++) {
				if (new_game->board[i][j] == 0) {
					new_game->board[i][j] = player;
					draw(new_game);
					new_game->board[i][j] = 0;
				}
			}
		}
	}
	else
		printf("0\n");
}

void gen_all_pos_mov_cut_if_game_over(game* new_game, int player)
{
	int pos = 0, pom1;
	for (int i = 0; i < new_game->height; i++) {
		for (int j = 0; j < new_game->width; j++) {
			if (new_game->board[i][j] == 0)
				pos++;
		}
	}
	pom1 = check_win(new_game);
	int win[] = { UNKNOWN, UNKNOWN };
	if (pom1 == 0) {
		for (int i = 0; i < new_game->height; i++) {
			for (int j = 0; j < new_game->width && win[0] == UNKNOWN; j++) {
				if (new_game->board[i][j] == 0) {
					new_game->board[i][j] = player;
					int if_win = check_win(new_game);
					if (if_win != NOT_FOUND) {
						win[0] = i;
						win[1] = j;
					}
					new_game->board[i][j] = 0;
				}
			}
		}
		if (win[0] != UNKNOWN && win[1] != UNKNOWN)
		{
			printf("1\n");
			new_game->board[win[0]][win[1]] = player;
			draw(new_game);
		}
		else
		{
			cout << pos << endl;
			for (int i = 0; i < new_game->height; i++) {
				for (int j = 0; j < new_game->width; j++) {
					if (new_game->board[i][j] == 0) {
						new_game->board[i][j] = player;
						draw(new_game);
						new_game->board[i][j] = 0;
					}
				}
			}
		}
	}
	else
		printf("0\n");
}

void solve_game_state(game* new_game, int player)
{
	int curr_best_option = NOT_FOUND;
	if (player == PLAYER1) { curr_best_option = WORST; }
	if (player == PLAYER2) { curr_best_option = BEST; }
	int find = NOT_FOUND;
	for (int i = 0; i < new_game->height && find == 0; i++) {
		for (int j = 0; j < new_game->width && find == 0; j++) {
			if (new_game->board[i][j] == 0)
			{
				new_game->board[i][j] = player;
				int change_best_option = NOT_FOUND;
				if (player == PLAYER1)
					change_best_option = minimax(new_game, false);
				if (player == PLAYER2)
					change_best_option = minimax(new_game, true);
				new_game->board[i][j] = 0;
				if (player == PLAYER1)
				{
					if (change_best_option > curr_best_option)
						curr_best_option = change_best_option;
					if (curr_best_option == MAX_PLAYER1)
						find = FOUND;
				}
				else if (player == PLAYER2) {
					if (change_best_option < curr_best_option)
						curr_best_option = change_best_option;
					if (curr_best_option == MIN_PLAYER2)
						find = FOUND;
				}
			}
		}
	}
	if (curr_best_option == MIN_PLAYER2)
		printf("SECOND_PLAYER_WINS\n");
	else if (curr_best_option == MAX_PLAYER1)
		printf("FIRST_PLAYER_WINS\n");
	else
		printf("BOTH_PLAYERS_TIE\n");
}

int minimax(game* new_game, bool is_max)
{
	int win = check_win(new_game);
	int current_player;
	if (win != NOT_FOUND) {
		if (new_game->player_win == PLAYER1)
			return MAX_PLAYER1;
		else if (new_game->player_win == PLAYER2)
			return MIN_PLAYER2;
	}
	else if (!is_moves_left(new_game))
		return TIE;
	else {
		if (is_max)
		{
			current_player = PLAYER1;
			int best_option = WORST;
			for (int i = 0; i < new_game->height; i++) {
				for (int j = 0; j < new_game->width; j++) {
					if (new_game->board[i][j] == 0) {
						new_game->board[i][j] = current_player;
						best_option = maxi(best_option, minimax(new_game, !is_max));
						new_game->board[i][j] = 0;
					}
				}
			}
			return best_option;
		}
		else
		{
			current_player = PLAYER2;
			int best_option = BEST;
			for (int i = 0; i < new_game->height; i++) {
				for (int j = 0; j < new_game->width; j++) {
					if (new_game->board[i][j] == 0) {
						new_game->board[i][j] = current_player;
						best_option = mini(best_option, minimax(new_game, !is_max));
						new_game->board[i][j] = 0;
					}
				}
			}
			return best_option;
		}
	}
	return 0;
}

bool is_moves_left(game* new_game)
{
	for (int i = 0; i < new_game->height; i++) {
		for (int j = 0; j < new_game->width; j++) {
			if (new_game->board[i][j] == 0)
				return true;
		}
	}
	return false;
}

int mini(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int maxi(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void czysc(game* new_game)
{
	for (int i = 0; i < new_game->height; i++)
		delete[] new_game->board[i];
	delete[] new_game->board;
}