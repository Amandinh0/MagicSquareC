

#include <stdio.h>

void clear_keyboard_buffer(void);
void buildSquare(int* square, int dimension);
void printArray(int* square, int dimension);
void fill_array_with_zeros(int* square, int dimension);

int main(int argc, const char * argv[]) {
    
    int dimension;
    
    printf("How big do you want your magic square?\n");
    printf("Enter an odd number:");
    int catch_dimension = scanf("%d",&dimension);
    clear_keyboard_buffer();
    while(catch_dimension != 1|| ((dimension%2) ==0)){
        printf("Invalid input!\n");
        printf("Please enter again:");
        catch_dimension = scanf("%d",&dimension);
        clear_keyboard_buffer();
    }
    
    int square[dimension][dimension];
    
    fill_array_with_zeros(square[0],dimension);
    
    buildSquare(square[0],dimension);
    
    printArray(square[0], dimension);
    return 0;
}

void buildSquare(int* square, int dimension){
    
    
    int row = 0;
    int cols = dimension/2;
    int number = 1;
    
    *(square +(row*dimension + cols)) = 1;
    while (number < dimension * dimension){
        
        number++;
        row--;
        cols++;
        
        if((row < 0) && (cols>dimension-1)){
            row+=2;
            cols--;
        }
        if(row < 0){
            row = dimension-1;
        }
        
        if(cols>dimension-1){
            cols =0;
        }
        
        if(*(square +(row*dimension + cols)) != 0){
            row+=2;
            cols--;
        }
        *(square +(row*dimension + cols)) = number;
    }

}

void fill_array_with_zeros(int* square, int dimension){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            *(square + (i * dimension + j)) = 0;
        }
    }
    
}


void clear_keyboard_buffer(void)
    {
            char c;
            scanf("%c",&c);
            while(c != '\n')
            {
                scanf("%c",&c);
            }
    }

void printArray(int* square, int dimension){
    
    for(int i = 0;i< dimension;i++){
        printf("____");
    }
    printf("\n");
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            printf("|%2d",*(square + (i * dimension + j)));
            printf("%-1c",' ');
        }
        printf("|");
        printf("\n");
        for(int z = 0;z < dimension;z++){
            printf("----");
        }
        printf("\n");
    }
    
}
