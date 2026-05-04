#include <iostream>
#include <vector>
#include <string>

using namespace std;

using bord_t=string;

bord_t initial_board()
{
    return "         ";
}

char get_cell(const bord_t& board, int i){
    return board[i];
}

string aplly_board_move(string board,int i, char player){
    string new_board=board;
    new_board[i]=player;
    return new_board;

}