#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>




using namespace std;

using bord_t=string;

enum class GameStatus {X_Wins,O_Wins,Draw,Ongoing};

unordered_map<bord_t,double> value_table;

GameStatus getWinner(const bord_t& bord)
{
    for (int i=0;i<3;++i)
    {
        if(((bord[i*3]==bord[i*3+1])&&(bord[i*3+1]==bord[i*3+2]))&&bord[i*3]!=' ')  
        {
            if (bord[i*3] == 'X'){return GameStatus::X_Wins;}
            else{return GameStatus::O_Wins;}
        }
        if (((bord[i]==bord[i+3])&&(bord[i+3]==bord[i+6]))&&bord[i]!=' ')
        {
            if (bord[i] == 'X'){return GameStatus::X_Wins;}
            else{return GameStatus::O_Wins;}
        }
    }
    if((((bord[0]==bord[4])&&(bord[4]==bord[8]))&&bord[0]!=' ')||(((bord[2]==bord[4])&&(bord[4]==bord[6])))&&bord[2]!=' ')  
    {
            if (bord[4] == 'X'){return GameStatus::X_Wins;}
            else{return GameStatus::O_Wins;}
    }
    if (bord.find(' ') != string::npos)
    {
        return GameStatus::Ongoing;
    }
    else
    {
        return GameStatus::Draw;
    }

}

double get_value(unordered_map<bord_t,double>& value_table,const bord_t& bord)
{
    
    if (value_table.find(bord)==value_table.end())
    {
        GameStatus status = getWinner(bord);
        if (status == GameStatus::X_Wins)
        {
            value_table[bord] = 1.0;
        }
        else if (status == GameStatus::O_Wins || status == GameStatus::Draw)
        {
            value_table[bord] = 0.0;
        }
        else
        {
            value_table[bord] = 0.5;
        }
    }

    return value_table[bord];
}



bord_t initial_board()
{
    return "         ";
}

char get_cell(const bord_t& board, int i){
    return board[i];
}



string aplly_board_move(const bord_t& board,int i, char player){
    string new_board=board;
    new_board[i]=player;
    return new_board;

}

int main()
{
    double test =get_value(value_table,"XXX      ");
    
    cout<<"The output is "<<test<<endl;
}