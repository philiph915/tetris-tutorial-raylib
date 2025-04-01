#pragma once

#include "block.h"
#include "position.h"

class LBlock : public Block {
public:
    LBlock() {
        id = 1;
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};  // Rotation state 0
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};  // Rotation state 1
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};  // Rotation state 2
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};  // Rotation state 3
        Move(0, 3);
    }
};

class JBlock : public Block {
public:
    JBlock() {
        id = 2;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};  // Rotation state 0
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};  // Rotation state 1
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};  // Rotation state 2
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};  // Rotation state 3
        Move(0, 3);
    }
};

class IBlock : public Block {
public:
    IBlock() {
        id = 3;
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};  // Rotation state 0
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};  // Rotation state 1
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};  // Rotation state 2
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};  // Rotation state 3
        Move(-1, 3);
    }
};

class OBlock : public Block {
public:
    OBlock() {
        id = 4;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};  // Rotation state 0
        Move(0, 4);
    }
};

class SBlock : public Block {
public:
    SBlock() {
        id = 5;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};  // Rotation state 0
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};  // Rotation state 1
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};  // Rotation state 2
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};  // Rotation state 3
        Move(0, 3);
    }
};

class TBlock : public Block {
public:
    TBlock() {
        id = 6;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};  // Rotation state 0
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};  // Rotation state 1
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};  // Rotation state 2
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};  // Rotation state 3
        Move(0, 3);
    }
};

class ZBlock : public Block {
public:
    ZBlock() {
        id = 7;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};  // Rotation state 0
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};  // Rotation state 1
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};  // Rotation state 2
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};  // Rotation state 3
        Move(0, 3);
    }
};
