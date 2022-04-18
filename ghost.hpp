//
//  ghost.hpp
//  VaxMan
//
//  Created by Brian Johnston on 9/23/21.
//

#ifndef ghost_hpp
#define ghost_hpp

#include <stdio.h>
#include <vector>

#endif /* ghost_hpp */

class Ghost {
public:
    float posX;
    float posY;
    float direction;
    
    Ghost(float x, float y, float dir);
    void updateMonster(std::vector<std::vector<bool>> bitmap);
    void drawMonster(float r, float g, float b);
};
