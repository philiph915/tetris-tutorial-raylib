#include "block.h"
#include "position.h"

class LBlock : public Block {  // LBlock is a child of the Block class
    public:
        // constructor method
        LBlock(){
            id = 1;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0
            cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)}; // Rotation state 1
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)}; // Rotation state 2
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(0,3);
        }
};

class JBlock : public Block {  
    public:
        // constructor method
        JBlock(){
            id = 2;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0
            cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)}; // Rotation state 1
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)}; // Rotation state 2
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(0,3);
        }
};

class IBlock : public Block {  
    public:
        // constructor method
        IBlock(){
            id = 3;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)}; // Rotation state 0
            cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)}; // Rotation state 1
            cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)}; // Rotation state 2
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(-1,3);
        }
};

class OBlock : public Block {  
    public:
        // constructor method
        OBlock(){
            id = 4;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}; // Rotation state 0 (all rotation states are identical)

            // Move the block to its initial spawn location
            Move(0,4);
        }
};

class SBlock : public Block {  
    public:
        // constructor method
        SBlock(){
            id = 5;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)}; // Rotation state 0
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)}; // Rotation state 1
            cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)}; // Rotation state 2
            cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(0,3);
        }
};

class TBlock : public Block {  
    public:
        // constructor method
        TBlock(){
            id = 6;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)}; // Rotation state 0
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 1
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 2
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(0,3);
        }
};

class ZBlock : public Block {  
    public:
        // constructor method
        ZBlock(){
            id = 7;

            // define which blocks are occupied all of the rotation states
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)}; // Rotation state 0
            cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation state 1
            cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)}; // Rotation state 2
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}; // Rotation state 3

            // Move the block to its initial spawn location
            Move(0,3);
        }
};