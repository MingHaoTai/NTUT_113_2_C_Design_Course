#include<stdio.h>

void DFExpresion(char data[], int *index, int start_row, int start_col, int size, int result[][2], int *count){
    char current = data[(*index)++];
    if (current == '0') {
        return;
    }    
    else if (current == '1') {
        for (int i = start_row; i < start_row + size; i++){
            for (int j = start_col; j < start_col + size; j++){
                result[*count][0] = i;
                result[*count][1] = j;
                (*count)++;
            }
        }
    }
    else if (current == '2') {
        int half = size / 2;
        DFExpresion(data, index, start_row, start_col, half, result, count);
        DFExpresion(data, index, start_row + half, start_col, half, result, count);
        DFExpresion(data, index, start_row, start_col + size, half, result, count);
        DFExpresion(data, index, start_row + size, start_col + size, half, result, count);
    }
}
 
int main() {
    char data[100];
    int size;
    int index, count;
    int result[100][2];
    scanf("%s", data);
    scanf("%d", &size);   
    DFExpresion(data, &index, 0, 0, size, result, &count);
    if (count == 0) {
        printf("all white");
    }
    else{         
        
    }
    return 0;
}