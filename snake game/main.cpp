#include <iostream>
// make the input library console input ouput
#include <conio.h>
#include <windows.h>

using namespace std;
/* function pada game 
1. setup (begining function)
2. draw (buat gambarnya)
3. input (buat kendarain)
4. logic (algoritma)
*/
// global variabel 
bool gameOver;
// make a map 
const int width = 20;
const int height = 20;
// make a assets position
int x,y,fruitX,fruitY, score;
// implementing the tail
// make the tail max 100 "O";
int tailX[100],tailY[100];
// make the length of tail 
int nTail;
// make a keybindings direction the snake 
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
// a declaration of enum keybindings
eDirection dir;
// begining the game 
void setup()
{
    gameOver=false;
    dir=STOP;
    // make a snake position while the game on setup
    // position on the central of the display
    x = width/2;
    y = height/2;
    // make the fruit run randomly 
    fruitX= rand() % width;
    fruitY= rand() % height;
    // set the score 
    score = 0;
}

void draw()
{
// make the display fix but this can make a little bit flicker
system("cls");

/* make the display
#######
#     #
#######
*/

// top display
for(int i=0; i<width+2; i++)
cout<<"#";
cout<<endl;

// make the sideways
for(int i =0; i< height;i++){
    for(int j=0; j< width; j++){
        // make a line on the left and right sideways
        if(j==0)
            cout<<"#";
        // make the snake position and the fruit on the display
        // the snake position 
        if(i==y && j==x)
            cout<<"O";
        
        // the fruits position
        else if(j==fruitX && i==fruitY)
            cout<<"*";
        
        //the blankspace
        else{
            bool print= false;
            for(int k=0; k<nTail; k++){
                // drawing the tail
                if(tailX[k]==j && tailY[k]==i){
                    cout<<"o";
                    /*
                    note:
                    cara seperti ini mengganggu looping cout<<" ";
                    jadi seakan ketika dia else ada 2 draw yang dikerjakan
                    jadinya tail tidak berjalan dengan baik dan cout<<" "\
                    juga tidak berjalan dengan baik cara memisahkannya
                    menggunakan boolean sebaliknya dari perintah else agar si ekor
                    tetap di dalam tempatnya
                    */
                    print = true;
                }
            }
            if(!print)
            cout<<" ";
            
        }
        // why -1 because we start on 0 so if you want 20 lines it just 19 lines;
        if(j==width-1){
            cout<<"#";
        }
    }
    cout<<endl;
}

// bottom display  
// why we increase 2 point because the line look the less line 
for(int i =0; i<width+2; i++)
cout<<"#";
cout<<endl;
cout<<"Score: "<<score<<endl;
}

void input()
{
// make the keybindings input with the kb hit for the return have the positives input
    if(_kbhit()){
        // on the getch because getch is the asci value 
        switch(_getch()){
            // handle the controls
            case 'a':
                dir= LEFT;
                break;
            case 'd':
                dir= RIGHT;
                break;
            case 'w':
                dir= UP;
                break;
            case 's':
                dir= DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }

    }
}
void logic(){
    // make the tail movement
    // prevX=tail yang dijalankan diawal/sebelum tail setelahnya;
    // buat logic tail  oooo bertambah saat dimakan bukan buat tail ooo follow
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    /*
    dibuatkan logic follownya jadi saat
    kepala belok maka ekor juga belok 
    dan dimulai dari ekor awal o lalu ekor berikutnya ikuti
    jadi begini :
     o   Oooo
     o
     o
     O   oooO  
    */
    tailX[0]=x;
    tailY[0]=y;
    // make looping to print the tail snake;
    for(int i=1; i<nTail; i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        // mendeklarasikan bahwa tail[i] itu ada setelah prev;
        tailX[i]=prevX;
        tailY[i]=prevY;
        // deklarasi lagi agar bisa di update saat diprint
       prevX=prev2X;
       prevY=prev2Y;
        /*
        jadi gambarannya 
        tail[0]=o;
        tail[0] kan sudah di deklarasi kan terlebih dahulu 
        pada prev nah agar bisa muncul setelahnya maka
        dibuat lah looping yang menginisiasi kalo tail di saat looping itu
        terjadi setelah tail[0] maka terbentuk lah sebagai berikut :
        tail[1]=oo;
        tail[2]=ooo;
        dst;
        */
    }


    switch(dir){
            // make the simple logic for the keybinding with 
            // with the increment and decrement logic 
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN :
                y++;
                break;
            default :
                break;
        }
    // make the logic 
    // while the snack run into line then the snack gameOver
    // if(x>width || x<0 || y>height || y<0){
    //     gameOver = true;
    // }
    // make the snake keep run if he hit the wall and make the snake can back to display again
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
    // make the logic if the snake eat the tail ouself then gameover
    for(int i=0; i<nTail; i++)
        if(tailX[i]==x && tailY[i]==y)
            gameOver = true;
    // and when the snake aeat the tails snake can incrase
    if(x==fruitX && y==fruitY){
        score +=10;
        // make the fruit run randomly and can eat of the snack
        fruitX= rand() % width;
        fruitY= rand() % height;
        // if the snake eat it then the tail can increase
        nTail++;
    }




}

int main()
{
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
        Sleep(10);
    }
 
    /* code */
    return 0;
}
