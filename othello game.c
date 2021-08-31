#include <stdio.h>
#include <stdlib.h>
////////////////// function:           print_board //////////////////
int can_flip_opponent(int board[8][8], int row, int column, int current_player);
void print_board(int board[8][8])
{
    int x,y;   
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (x=0; x<8; x++)
    {
         printf("%d ",x);    
        for (y=0; y<8; y++)
        {
            if(board[x][y]==0)       
            {
                printf("|   ");   
            }
            if(board[x][y]==1)   
            {
                printf("| O ");   
            }
            if(board[x][y]==2)   
            {
                printf("| # ");   
            }
        }
        printf ("|\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}
////////////////// function:    print_game_details //////////////////
void print_game_details(int board[8][8], int current_player)
{
    int count=0;   
    int i,j, countO=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)       
        {
            if(board[i][j]==1)       
            {
                count++;   
            }
            else if(board[i][j]==2)   
            {
                countO++;   
            }
        }
    }
    char y;
    if(current_player == 1)
    {
        y='O';
    }
    else if(current_player == 2)
    {
        y='#';
    }
    printf("\nPlayer  O: %d",count);
    printf("          Player  #: %d\n", countO);
    printf("\nCurrent Turn: %c\n",y);
}
////////////////// function:             need_pass //////////////////
int need_pass(int board[8][8], int current_player)
{
    int i, j;   
    for (i=0; i<8; i++)
    {
        for (j=0;j<8;j++)       
        {
            if (can_flip_opponent(board, i, j, current_player) == 1)       
            {
                return 0;   
            }
        }
    }
    return 1;
}
////////////////// function:          is_end_game //////////////////
int is_end_game(int board[8][8])
{
    int i, j,countO=0;   
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)       
        {
            if(board[i][j]==0)       
            {
                countO++;   
            }
        }
    }
    if(countO==0)   
    {
        return 1;   
    }
    else if (need_pass(board,1) == 1 &&need_pass(board,2) == 1)
    {
        return 1;
    }
    else
        return 0;
}
////////////////// function: is_wrong_input_range //////////////////
int is_wrong_input_range(int row, int column)
{
    if(row >=0 && row<=7 && column >=0 && column<=7)       
    {
        return 0;   
    }
    else   
        return 1;
}
////////////////// function:        is_empty_cell //////////////////
int is_empty_cell(int board[8][8], int row, int column)
{
    if(board[row][column]==0)       
        return 1;
    else
        return 0;
}
////////////////// function:    can_flip_opponent //////////////////
int can_flip_opponent(int board[8][8], int row, int column, int current_player)
{
    if (board[row][column] != 0)       
    {
        return 0;   
    }
    int i, j;
    int can_flip = 0;
    int find_opp = 0;
    int opponent_player;
    if(current_player==1)
    {
        opponent_player=2;   
    }
    else   
    {
        opponent_player=1;   
    }
    for (i = row - 1; i  >= 0; i--)  //Check up   
    {
        if (find_opp == 1 && board[i][column] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[i][column] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[i][column] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( i= row +1;i< 8;i++) //Check down   
    {
        if (find_opp == 1 && board[i][column] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[i][column] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[i][column] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( j= column -1 ;j >=0;j--) // check left
    {
        if (find_opp == 1 && board[row][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[row][j] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[row][j] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( j= column + 1 ;j< 8;j++) //Check right   
    {
        if (find_opp == 1 && board[row][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[row][j] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[row][j] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( i= row - 1, j= column - 1 ;i >=0 && j >=0;i--,j--) //check diagonal left   
    {
        if (find_opp == 1 && board[i][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[i][j] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[i][j] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( i= row - 1, j= column + 1 ;i >= 0 && j < 8;i--,j++) //Check diagonal right
    {
        if (find_opp == 1 && board[i][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[i][j] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[i][j] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( i= row + 1, j= column - 1 ;i <8 && j >=0;i++,j--) //Check diagonal left(downwards)   
    {
        if (find_opp == 1 && board[i][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        if (board[i][j] == opponent_player)   
        {
            find_opp = 1;   
        }
        if (board[i][j] != opponent_player)   
        {
            break;   
        }
    }
    find_opp = 0;
    for( i= row + 1, j= column + 1 ;i < 8 && j < 8;i++,j++) //Check diagonal right(downwards)
    {
        if (find_opp == 1 && board[i][j] == current_player)       
        {
            can_flip = 1;   
            break;
        }
        
        if (board[i][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    return can_flip;
    
    
    
}



////////////////// function:        flip_opponent //////////////////



void flip_opponent(int board[8][8], int row, int column, int current_player)

{
    
    
    
    
    
    int i, j;
    
    int can_flip = 0;
    
    int find_opp = 0;
    
    int opponent_player;
    
    if(current_player==1)
        
    {
        
        opponent_player=2;
        
    }
    
    else
        
    {
        
        opponent_player=1;
        
    }
    
    for (i = row - 1; i  >= 0; i--)  //Check up
        
    {
        
        if (find_opp == 1 && board[i][column] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][column] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][column] != opponent_player)
            
        {
            
            break;
            
        }
        
    }
    
    
    
    if (can_flip == 1)
        
    {     board[row][column]=current_player;
        
        for (i = row - 1; i >= 0; i--)
            
        {
            
            if (board[i][column] == opponent_player)
                
            {
                
                board[i][column] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    for( i= row +1;i< 8;i++) //Check down
        
    {
        
        if (find_opp == 1 && board[i][column] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][column] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][column] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (i = row + 1; i < 8; i++)
            
        {
            
            if (board[i][column] == opponent_player)
                
            {
                
                board[i][column] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    for( j= column -1 ;j >=0;j--) // check left
        
    {
        
        if (find_opp == 1 && board[row][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[row][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[row][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (j = column - 1; j >=0; j--)
            
        {
            
            if (board[row][j] == opponent_player)
                
            {
                
                board[row][j] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    
    
    can_flip = 0;
    
    
    
    for( j= column + 1 ;j< 8;j++) //Check right
        
    {
        
        if (find_opp == 1 && board[row][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[row][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[row][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (j = column + 1; j < 8; j++)
            
        {
            
            if (board[row][j] == opponent_player)
                
            {
                
                board[row][j] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    
    
    for( i= row - 1, j= column - 1 ;i >=0 && j >=0;i--,j--) //check diagonal left
        
    {
        
        if (find_opp == 1 && board[i][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (i= row - 1,j = column - 1; i >=0 && j>=0; i--,j--)
            
        {
            
            if (board[i][j] == opponent_player)
                
            {
                
                board[i][j] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    
    
    for( i= row - 1, j= column + 1 ;i>=0 &&j < 8;i--,j++) //Check diagonal right
        
    {
        
        if (find_opp == 1 && board[i][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (i= row - 1,j = column + 1; i >= 0&& j < 8; i--,j++)
            
        {
            
            if (board[i][j] == opponent_player)
                
            {
                
                board[i][j] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    for( i= row + 1, j= column - 1 ;i <8 && j >=0;i++,j--) //Check diagonal left(downwards)
        
    {
        
        if (find_opp == 1 && board[i][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {board[row][column]=current_player;
        
        for (i= row + 1,j = column - 1; i < 8 && j >=0; i++,j--)
            
        {
            
            if (board[i][j] == opponent_player)
                
            {
                
                board[i][j] = current_player;
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    can_flip = 0;
    
    
    
    for( i= row + 1, j= column + 1 ;i < 8 && j < 8;i++,j++) //Check diagonal right(downwards)
        
    {
        
        if (find_opp == 1 && board[i][j] == current_player)
            
        {
            
            can_flip = 1;
            
            break;
            
        }
        
        if (board[i][j] == opponent_player)
            
        {
            
            find_opp = 1;
            
        }
        
        if (board[i][j] != opponent_player)
            
        {
            
            break;
            
            
            
        }
        
        
        
    }
    
    
    
    if (can_flip == 1)
        
    {
        
        board[row][column]=current_player;
        
        
        
        for (i= row + 1,j = column + 1; i < 8 && j < 8; i++,j++)
            
        {
            
            if (board[i][j] == opponent_player)
                
            {
                
                board[i][j] = current_player;
                
                
                
            }
            
            else
                
            {
                
                break;
                
            }
            
        }
        
    }
    
    
    
    
    
    // should be only once?
    
    
    
    
    
    
    
}





////////////////// function:         print_winner //////////////////



void print_winner(int board[8][8])

{
    
    
    
    int i,j; int count1=0,count2=0;
    
    for(i=0;i<8;i++)
        
    {
        
        for(j=0;j<8;j++)
            
        {
            
            if(board[i][j]==1)
                
            {
                
                count1++;
                
            }
            
            else if(board[i][j]==2)
                
            {
                
                count2++;
                
            }
            
        }
        
    }
    
    
    
    
    
    printf("\nPlayer O:%d",count1);
    
    printf("             Player #:%d",count2);
    
    if(count1>count2)
        
    {
        
        printf("\nWinner: Player O!\n");
        
    }
    
    else if(count2>count1)
        
    {
        
        printf("\nWinner: Player #!\n");
        
        
        
    }
    
    else
        
        printf("DRAW!!!!!\n");
    
}



///////////////// Main /////////////////



int main(int argc, char **argv)

{
    
    int current_player = 1;  // current_player can be 1 or 2;
    
    int board[8][8]={0};           // store the current game board
    
    int row, column, mode, stop, all_test_pass;
    
    int i,j;
    
    
    
    printf("Select Mode: [1. Normal Mode | 2. Debug Mode] ?\n");
    
    scanf("%d", &mode);
    
    
    
    
    
    if(mode == 1)
        
    {
        
        
        //board[3][2]=2;
        board[3][4]=1;
        
        board[4][3]=1;
        
        board[3][3]=2;
        
        board[4][4]=2;
        
        
        
        
        
        
        
        
        
        /*
         
         Initialize the board as instructed in
         
         P.3 of the specification.
         
         */
        
    }
    
    else if(mode == 2)
        
    {
        
        FILE *fp;
        
        fp = fopen("board.txt", "r");
        
        if (fp == NULL)
            
        {
            
            perror("board.txt");
            
            exit(1);
            
        }
        
        for(i=0;i<8;i++)
            
        {
            
            
            
            for(j=0;j<8;j++)
                
                
                
                fscanf(fp,"%d",&board[i][j]);
            
            
            
        }
        
        
        
        fclose(fp);
        
        
        
        //exit(0);
        
        /*
         
         Initialize the board based on the
         
         input file format as described in
         
         P.7 of the specification.
         
         */   
    }
    stop = 0;
    
    
    
    while(stop == 0) { // the big game loop begins
        
        
        
        print_board(board);
        
        
        print_game_details(board, current_player);
        
        
        
        if( is_end_game(board) == 1 ) {
            
            stop = 1;
            
        }
        
        
        
        if(need_pass(board, current_player) == 1)
            
        {
            
            printf("You have to pass this turn\n");
            
            if(current_player==1)
                
            {
                
                current_player=2;
                
            }
            
            else
                
                current_player=1;
            
            continue;
            
        }
        
        else
            
        {
            
            
            
            printf("Enter");
            
            
            
            
            
            do {
                
                all_test_pass = 1;
                
                scanf("%d%d", &row, &column);
                if(  is_wrong_input_range(row, column) == 1 ) {
                    
                    printf("Wrong input range\n");
                    all_test_pass = 0;   
                }
                else if( is_empty_cell(board, row, column) == 0 ) {
                    printf("No empty cell\n");
                    all_test_pass = 0;   
                }
                else if( can_flip_opponent(board, row, column, current_player) == 0 ) {
                    printf("Can't place the disc here\n");
                    all_test_pass = 0;   
                }
                if(all_test_pass == 1) {
                    flip_opponent(board, row, column, current_player);   
                }
            } while( all_test_pass == 0 );
        } // end of else body //
        if(current_player==1)   
        {
            current_player=2;   
        }
        else
            current_player=1;
    }  // the big game loop ends
    print_board(board);
    print_winner(board);
    return 0;
}
