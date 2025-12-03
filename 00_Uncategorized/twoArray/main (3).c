#include <stdio.h>

int main() {
    int m , n;
    scanf("%d %d" , &m , &n);
    int A[m];
    int B[n];
    for(int i=0 ; i<m ; i++)
        scanf("%d" , &A[i]);

    for(int i=0 ; i<n ; i++)
        scanf("%d" , &B[i]);

    int x =0 ;
    for(int i=0 ; i<m ; i++){
        if(A[i]>B[x]){
            if(x+1<n && A[i]>B[x+1]){
                if(x+2<n && A[i]>B[x+2]){
                    if(x+3<n && A[i]>B[x+3]){
                        if(x+4<n && A[i]>B[x+4]){
                            if(x+5<n && A[i]>B[x+5]){
                                if(x+6<n && A[i]>B[x+6]){
                                    if(x+7<n && A[i]>B[x+7]){
                                        if(x+8<n && A[i]>B[x+8]){
                                            if(x+9<n && A[i]>B[x+9]){
                                                if(x+10<n && A[i]>B[x+10]){
                                                    if(x+11<n && A[i]>B[x+11]){
                                                        if(x+12<n && A[i]>B[x+12]){
                                                            if(x+13<n && A[i]>B[x+13]){
                                                                if(x+14<n && A[i]>B[x+14]){
                                                                    if(x+15<n && A[i]>B[x+15]){
                                                                        if(x+16<n && A[i]>B[x+16]){
                                                                            if(x+17<n && A[i]>B[x+17]){
                                                                                if(x+18<n && A[i]>B[x+18]){
                                                                                    if(x+19<n && A[i]>B[x+19]){
                                                                                        if(x+20<n && A[i]>B[x+20]){

                                                                                        }
                                                                                        else if(x+19<n){
                                                                                            x+=19;
                                                                                            printf("%d " , B[x]);
                                                                                        }
                                                                                    }
                                                                                    else if(x+18<n){
                                                                                        x+=18;
                                                                                        printf("%d " , B[x]);
                                                                                    }
                                                                                }
                                                                                else if(x+17<n){
                                                                                    x+=17;
                                                                                    printf("%d " , B[x]);
                                                                                }
                                                                            }
                                                                            else if(x+16<n){
                                                                                x+=16;
                                                                                printf("%d " , B[x]);
                                                                            }
                                                                        }
                                                                        else if(x+15<n){
                                                                            x+=15;
                                                                            printf("%d " , B[x]);
                                                                        }
                                                                    }
                                                                    else if(x+14<n){
                                                                        x+=14;
                                                                        printf("%d " , B[x]);
                                                                    }

                                                                }
                                                                else if(x+13<n){
                                                                    x+=13;
                                                                    printf("%d " , B[x]);
                                                                }
                                                            }
                                                            else if(x+12<n){
                                                                x+=12;
                                                                printf("%d " , B[x]);
                                                            }
                                                        }
                                                        else if(x+11<n){
                                                            x+=11;
                                                            printf("%d " , B[x]);
                                                        }
                                                    }
                                                    else if(x+10<n){
                                                        x+=10;
                                                        printf("%d " , B[x]);
                                                    }
                                                }
                                                else if(x+9<n){
                                                    x+=9;
                                                    printf("%d " , B[x]);
                                                }
                                            }
                                            else if(x+8<n){
                                                x+=8;
                                                printf("%d " , B[x]);
                                            }
                                        }
                                        else if(x+7<n){
                                            x+=7;
                                            printf("%d " , B[x]);
                                        }
                                    }
                                    else if(x+6<n){
                                        x+=6;
                                        printf("%d " , B[x]);
                                    }
                                }
                                else if(x+5<n){
                                    x+=5;
                                    printf("%d " , B[x]);
                                }
                            }
                            else if(x+4<n){
                                x += 4;
                                printf("%d ", B[x]);
                            }
                        }
                        else if(x+3<n){
                            x+=3;
                            printf("%d ", B[x]);
                        }

                    }
                    else if(x+2<n){
                        x+= 2;
                        printf("%d " , B[x]);

                    }
                }
                else if(x+1<n){
                    x += 1;
                    printf("%d " , B[x]);

                }
            }
            else{
                printf("%d " , B[x]);
            }
        }
        else{
            printf("%d " , B[x]);
        }
    }
}
