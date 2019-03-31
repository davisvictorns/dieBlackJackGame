#include "Die.h"

Die::Die() : rd(), gen(rd()), dis(1, 6){
    value = round(dis(gen));
}

int Die::roll(){
    value = round(dis(gen));
    return value;
}

int Die::getValue(){
    return value;
}