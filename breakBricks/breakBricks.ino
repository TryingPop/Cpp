#include "NDelayFunc.h"
#include "DotMatrix.h"

// 맵
unsigned int game_display[1+8][1+8] ={
  
  {-1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1,  1,  1,  1,  1,  1,  1,  1,  1},
  {-1,  1,  1,  1,  1,  1,  1,  1,  1},
  {-1,  1,  1,  1,  1,  1,  1,  1,  1},
  {-1,  1,  1,  1,  1,  1,  1,  1,  1},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  0,  1,  0,  0,  0,  0},
  {-1,  0,  0,  1,  1,  1,  0,  0,  0}
};

// 패배시 나오는 표정
const unsigned int game_lose[1+8][1+8]{

  {-1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  1,  1,  0,  0,  1,  1,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  1,  1,  1,  1,  0,  0},
  {-1,  0,  1,  0,  0,  0,  0,  1,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0}
};

// 승리 시 나오는 표정
const unsigned int game_win[1+8][1+8]{

  {-1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  1,  0,  0,  1,  0,  0},
  {-1,  0,  0,  1,  0,  0,  1,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  1,  0,  0,  0,  0,  1,  0},
  {-1,  0,  0,  1,  1,  1,  1,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0},
  {-1,  0,  0,  0,  0,  0,  0,  0,  0}
};

enum {PLAY = 0, LOSE, WIN};
int game_state = PLAY;

// 공의 위치
int ball_x = 4;
int ball_x_dir = 1;
int ball_y = 7;
int ball_y_dir = 1;

// 블럭 개수
int how_many_bricks = 24;

// 공의 이동
void ball_move(){
  
  // 시작 중이 아니면 종료
  if (game_state != PLAY){

    return;
  }

  // 공이 있는 곳 불 끄기
  game_display[ball_y][ball_x] = 0;
  
  // x 방향 이동
  ball_x += ball_x_dir;

  // 오른쪽에 붙었는지 확인
  if(ball_x >= 8){
  
    ball_x = 8;
    ball_x_dir = -ball_x_dir;
  }

  // 왼쪽에 붙었는지 확인
  if (ball_x <= 1){
  
    ball_x = 1;
    ball_x_dir = - ball_x_dir;
  }

  // y 방향 이동
  ball_y += ball_y_dir;
  
  // 아래에 닿았는지 확인
  if (ball_y >= 8){
  
    // 채가 있는 경우
    if (game_display[ball_y][ball_x] == 1){

      ball_y -= 2 * ball_y_dir;
      ball_y_dir =-ball_y_dir;
    }
    else{

      game_state = LOSE;
      return;
    }
  }
  
  // 위에 닿았는지 확인
  if (ball_y <= 1){
      
    ball_y = 1;
    ball_y_dir = -ball_y_dir;
  }

  // 벽돌과 공이 충돌 했는가?
  if (game_display[ball_y+ball_y_dir][ball_x] == 1){

    if (ball_y != 7){

      game_display[ball_y + ball_y_dir][ball_x] = 0;
      how_many_bricks--;
      
      if (how_many_bicks == 0) {
        
        game_state = WIN;
      }
    }

    ball_y_dir = -ball_y_dir;
  }
  else if(game_display[ball_y + ball_y_dir][ball_x + ball_x_dir] == 1){

    if (ball_y != 7){

      game_display[ball_y + ball_y_dir][ball_x + ball_x_dir] = 0;
      how_many_bricks--;

      if (how_many_bricks == 0){

        game_state = WIN;
      }
    }

    ball_y_dir = -ball_y_dir;
    ball_x_dir = -ball_x_dir;
  }

  game_display[ball_y][ball_x] = 1;
}

// ball move 함수 500ms 마다 시행
NDelayFunc nDelayGame(500, ball_move);

// 게임 상태 그리기
void draw(){

  if (game_state == PLAY){

    DotMatrix.draw(game_display);
  }
  else if (game_state == LOSE){

    DotMatrix.draw(game_lose);
  }
  else if (game_state == WIN){
    
    DotMatrix.draw(game_win);
  }
}

// draw 함수 1ms마다 시행
NDelayFunc nDelayDraw(1, draw);

// 바의 초기 위치
int bar_x = 4;
const int bar_y = 8;

// 바 움직임
void bar_move(){

  if (game_state != PLAY){

    return;
  }

  int analogValue = analogRead(A5);
  // Serial.println(analogValue);

  static int prevAnalogValue = 0;

  int new_bar_x = bar_x;

  if (analogValue > prevAnalogValue + 1024/8){

    prevAnalogValue = analogValue;
    new_bar_x++;

    if (new_bar_x >=7){

      new_bar_x =7;
    }

    Serial.println(new_bar_x);
  }
  else if (analogValue < prevAnalogValue - 1024/8){

    prevAnalogValue = analogValue;
    new_bar--;

    if (new_bar_x <= 2){

      new_bar_x = 2;
    }

    Serial.println(new_bar_x);
  }


  // bar_x = new_bar_x;
  if (new_bar_x != bar_x){

    game_display[bar_y][bar_x] = 0;
    game_display[bar_y][bar_x-1] = 0;
    game_display[bar_y][bar_x+1] = 0;

    bar_x = new_bar_x;

    game_display[bar_y][bar_x] = 1;
    game_display[bar_y][bar_x-1] = 1;
    game_display[bar_y][bar_x+1] = 1;
  }
}

void setup() {
  
  DotMatrix.init();
  Serial.begin(115200);
}

void loop() {
  
  bar_move();
  nDelayGame.run();
  nDelayDraw.run();
}
