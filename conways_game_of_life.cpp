#include <iostream>
#include <unistd.h>
//#define HEIGHT 12
//#define WIDTH 20
#define HEIGHT 75
#define WIDTH 150

using namespace std;

int how_many_alive(int t[HEIGHT][WIDTH], int x, int y){
    int neighbor[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},{ 0, -1},{ 0, 1},{ 1, -1}, { 1, 0}, { 1, 1}};
    int alivec = 0;
    for (int i = 0; i < 8; i++) {
        int dx = neighbor[i][0], dy = neighbor[i][1];
        int neighborX = (x + dx + WIDTH) % WIDTH;
        int neighborY = (y + dy + HEIGHT) % HEIGHT;
        if(t[neighborY][neighborX] == 1) alivec++;
    }
    return alivec;
}
int is_alive(int t[HEIGHT][WIDTH], int x, int y){
    int alivec = how_many_alive(t, x, y);
    if(t[y][x] == 1){
        if(alivec == 2 || alivec == 3)  return 1;
        return 0;
    }
    else{
        if(alivec == 3) return 1;
        return 0;
    }
}
void next_gen(int t[HEIGHT][WIDTH]){
    int next_t[HEIGHT][WIDTH] = {0};
    for(int i = 0; i<HEIGHT; i++){
        for(int j = 0; j<WIDTH; j++){
            next_t[i][j] = is_alive(t,j,i);
        }
    }
    
    for(int i = 0; i<HEIGHT; i++){
        for(int j = 0; j<WIDTH; j++){
            t[i][j] = next_t[i][j];
        }
    }
}
void printGrid(int t[HEIGHT][WIDTH]) {
    system("clear"); // "cls" on Windows
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << (t[i][j] ? "#" : " ");
        }
        cout << endl;
    }
}
int main(){
    int t[HEIGHT][WIDTH] = {};
    
    //t[4][7] = t[4][9] = t[4][10]=t[5][7]=t[5][8]=t[5][9] = t[6][8] = 1;
    t[5][1] = 1;
    t[6][1] = 1;

    t[5][2] = 1;
    t[6][2] = 1;

    t[5][11] = 1;
    t[6][11] = 1;
    t[7][11] = 1;

    t[4][12] = 1;
    t[8][12] = 1;

    t[3][13] = 1;
    t[9][13] = 1;

    t[3][14] = 1;
    t[9][14] = 1;

    t[6][15] = 1;

    t[4][16] = 1;
    t[8][16] = 1;

    t[5][17] = 1;
    t[6][17] = 1;
    t[7][17] = 1;

    t[6][18] = 1;

    t[3][21] = 1;
    t[9][21] = 1;

    t[3][22] = 1;
    t[9][22] = 1;

    t[2][23] = 1;
    t[10][23] = 1;

    t[2][24] = 1;
    t[10][24] = 1;

    t[5][25] = 1;
    t[6][25] = 1;

    t[5][35] = 1;
    t[6][35] = 1;

    t[5][36] = 1;
    t[6][36] = 1;

    printGrid(t);
    usleep(500000);
    for(int k = 0; k<1000; k++){
        next_gen(t);
        printGrid(t);
        usleep(5000);
    }

    return 0;
}
