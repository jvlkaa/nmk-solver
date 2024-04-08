#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "operations.h"
using namespace std;

int main()
{
	char command[SIZE];
	game* new_game = new game;
	while (cin >> command) {
		int N, M, K;
		int player;
		if (strcmp("GEN_ALL_POS_MOV", command) == 0)
		{
			scanf("%d%d%d%d", &N, &M, &K, &player);
			create(new_game, N, M, K);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++)
					scanf("%d", &new_game->board[i][j]);
			}
			gen_all_pos_mov(new_game, player);
		}
		else if (strcmp("GEN_ALL_POS_MOV_CUT_IF_GAME_OVER", command) == 0)
		{
			scanf("%d%d%d%d", &N, &M, &K, &player);
			create(new_game, N, M, K);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++)
					scanf("%d", &new_game->board[i][j]);
			}
			gen_all_pos_mov_cut_if_game_over(new_game, player);
		}
		else if (strcmp("SOLVE_GAME_STATE", command) == 0)
		{
			scanf("%d%d%d%d", &N, &M, &K, &player);
			create(new_game, N, M, K);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++)
					scanf("%d", &new_game->board[i][j]);
			}
			int pom = check_win(new_game);
			if (pom != 0) {
				if (new_game->player_win == PLAYER1)
					printf("FIRST_PLAYER_WINS\n");
				if (new_game->player_win == PLAYER2)
					printf("SECOND_PLAYER_WINS\n");
			}
			else {
				solve_game_state(new_game, player);
			}
		}
		czysc(new_game);
	}
	delete new_game;
	return 0;
}