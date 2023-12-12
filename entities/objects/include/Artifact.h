//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ARTIFACT_H
#define LAB3_ARTIFACT_H

#include "Creature.h"

class Artifact {
private:
    Primary influence;

public:
    Artifact() = default;
    virtual ~Artifact() = default;

    [[nodiscard]] Primary get_influence() const;

    void be_loaded(json data);
};


#endif //LAB3_ARTIFACT_H
