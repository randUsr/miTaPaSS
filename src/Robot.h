#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <iostream>

#define GO_TO_SOURCE 1;
#define RANDOM_WALK 0;
#define GO_TO_NEST -1;

class Robot {
 public:
  bool carrying = false;
  bool drop = false;
  int dir = RANDOM_WALK;

  Robot(int x, int y, int x_min, int x_max, int y_min, int y_max) :
    x(x), y(y), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max) {}

  int getX() {
    return x;
  }

  int getY() {
    return y;
  }

  void setPos(int newX, int newY) {
    if (newX < x_max && newX >= x_min) {
      x = newX;
    }
    if (newY < y_max && newY >= y_min) {
      y = newY;
    }
  }

  void moveForward() {
    setPos(x, y+1);
  }

  void moveBackward() {
    setPos(x, y-1);
  }


  int getDir() {
    return dir;
    }

  void setDir(int i) {
    dir = i;
  }


  bool isCarrying() {
    return carrying;
  }

  void carry(bool c) {
    carrying = c;
  }

  float getMotivation1() {
    return motivation1;
  }

  void setMotivation1(bool increase) {
    if (increase) {
      motivation1 += 0.1;
    } else {
      motivation1 -= 0.1;
    }
  }

  void addMotivation1(float mot) {
    motivation1 += mot;
  }

  float getMotivation2() {
    return motivation2;
  }

  void setMotivation2(bool increase) {
    if (increase) {
      motivation2 += 0.1;
    } else {
      motivation2 -= 0.1;
    }
  }

  bool getDrop() {
    return drop;
  }

  void setDrop(bool d) {
    drop = d;
  }

  friend std::ostream& operator<< (std::ostream &out, const Robot &r){
    return out
      << "Rob(" << r.x << ", " << r.y << "):"
      << " c=" << r.carrying
      << " d=" << r.drop
      << " dir=" << r.dir
      << " m1=" << r.motivation1
      << " m2=" << r.motivation2
      << std::endl;
  }

 private:
  int x, y;
  int x_min, x_max, y_min, y_max;
  float motivation1 = 0, motivation2 = 0;
};

//std::ostream& operator<<(std::ostream &strm, const Robot &r)

#endif  // SRC_ROBOT_H_
