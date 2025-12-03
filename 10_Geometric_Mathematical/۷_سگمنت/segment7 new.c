#include <stdio.h>
#include <string.h>
int main(){
    char str[1000];
    scanf("%s" , &str);
    int lenght = strlen(str);
    char number[1000];
    for(int i = 0; i < 1000; i++)
        number[i] = '\0';

    int i , k , j;
    int idx=0;

    for(i=0 ; i<lenght ; i++){
        if (str[1]== '.'){
            if (i == 1 ){
                i++;
            }

            if(str[i] != 'e'){
                number[idx++] = str[i];
            }

            else{
                number[idx] = '\0';
                k = i;
                break;
            }
        }

        else{
            number[idx] = str[0];
            k=1;
        }
    }

    //printf("number: %s\n", number);
    int mmd = 0;
    for(int q=0 ; number[q] != '\0' ; q++){
        mmd = mmd*10 + (number[q] - '0');
    }

    //printf("mmd: %d\n", mmd);

    int segment = 0;
    while (mmd>0){
        int u = mmd%10;
        mmd = (mmd-u)/10;
        if (u == 0){
            segment +=6;
        }
        else if (u ==1 ){
            segment +=2;
        }
        else if (u ==2){
            segment +=5;
        }
        else if (u ==3 ){
            segment +=5;
        }
        else if (u ==4 ){
            segment += 4;
        }
        else if (u ==5){
            segment += 5;
        }
        else if (u ==6){
            segment += 6;
        }
        else if (u ==7){
            segment += 3;
        }
        else if (u ==8){
            segment += 7;
        }
        else if (u ==9){
            segment += 6;
        }
    }

    char tavan[1000] = {'\0'};

    int iux = 0;
    for(int j = k + 1; j < lenght; j++) {
        tavan[iux] = str[j];
        iux++;
    }

    int nmd=0;

    for (i = 0 ; tavan[i] != '\0' ; i++){
        //printf("i = %d\n", i);
        nmd = nmd * 10 + (tavan[i] - '0');
    }

    //printf("tavan: %s\n", tavan);
    //printf("nmd: %d\n", nmd);
    if (nmd != 0){
        if (str[1] == 'e'){
            segment += (nmd)*6;
        }
        else{
            segment += (nmd-(k-2))*6;
        }
    }

    printf("%d" , segment);






}
