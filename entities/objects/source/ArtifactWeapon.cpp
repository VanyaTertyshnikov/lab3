//
// Created by vanish2 on 12.12.23.
//

#include "ArtifactWeapon.h"

void ArtifactWeapon::be_loaded(json data) {
    Artifact::be_loaded(data);
    Weapon::be_loaded(data);
}
