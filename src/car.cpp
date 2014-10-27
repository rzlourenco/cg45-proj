#include "car.h"

constexpr auto BODY_COLOR_RED = 50, BODY_COLOR_GREEN = 50, BODY_COLOR_BLUE = 50,
               WHEEL_COLOR_RED = 10, WHEEL_COLOR_GREEN = 10,
               WHEEL_COLOR_BLUE = 10, WHEEL_SIZE_N_SIDES = 15,
               WHEEL_SIZE_RINGS = 15;

constexpr auto BODY_SIZE_LOWER_X = 6.0f, BODY_SIZE_LOWER_Y = 1.0f,
               BODY_SIZE_LOWER_Z = 3.0f, BODY_SIZE_UPPER_X = 3.0f,
               BODY_SIZE_UPPER_Y = 1.0f, BODY_SIZE_UPPER_Z = 3.0f,
               BODY_COORD_LOWER_X = 0.0f, BODY_COORD_LOWER_Y = 1.0f,
               BODY_COORD_LOWER_Z = 0.0f, BODY_COORD_UPPER_X = -0.2f,
               BODY_COORD_UPPER_Y = 2.0f, BODY_COORD_UPPER_Z = 0.0f,
               WHEEL_SIZE_INNER_RADIUS = 0.3f, WHEEL_SIZE_OUTER_RADIUS = 0.5f,
               WHEEL_COORD_FRONT_LEFT_X = 1.5f, WHEEL_COORD_FRONT_LEFT_Y = 0.5f,
               WHEEL_COORD_FRONT_LEFT_Z = -1.5f,
               WHEEL_COORD_FRONT_RIGHT_X = 1.5f,
               WHEEL_COORD_FRONT_RIGHT_Y = 0.5f,
               WHEEL_COORD_FRONT_RIGHT_Z = 1.5f,
               WHEEL_COORD_BACK_LEFT_X = -1.5f, WHEEL_COORD_BACK_LEFT_Y = 0.5f,
               WHEEL_COORD_BACK_LEFT_Z = -1.5f,
               WHEEL_COORD_BACK_RIGHT_X = -1.5f,
               WHEEL_COORD_BACK_RIGHT_Y = 0.5f, WHEEL_COORD_BACK_RIGHT_Z = 1.5f;

car::car() {
    bounding_box() = ::bounding_box(
        -BODY_SIZE_LOWER_X / 2, -BODY_SIZE_LOWER_Y, -BODY_SIZE_LOWER_Z / 2,
        BODY_SIZE_LOWER_X / 2, BODY_SIZE_UPPER_Y, BODY_SIZE_LOWER_Z / 2);
}

void car::draw() {

    glColor3ub(BODY_COLOR_RED, BODY_COLOR_GREEN, BODY_COLOR_BLUE);

    // Lower Body
    glPushMatrix();
    glTranslatef(BODY_COORD_LOWER_X, BODY_COORD_LOWER_Y, BODY_COORD_LOWER_Z);
    glScalef(BODY_SIZE_LOWER_X, BODY_SIZE_LOWER_Y, BODY_SIZE_LOWER_Z);
    glutSolidCube(1);
    glPopMatrix();

    // Upper Body
    glPushMatrix();
    glTranslatef(BODY_COORD_UPPER_X, BODY_COORD_UPPER_Y, BODY_COORD_UPPER_Z);
    glScalef(BODY_SIZE_UPPER_X, BODY_SIZE_UPPER_Y, BODY_SIZE_UPPER_Z);
    glutSolidCube(1);
    glPopMatrix();

    // Front Triangle
    glPushMatrix();
    glTranslatef(1.62f, 1.72f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(1.5f, 0.75f, 3.0f);
    glutSolidCube(1);
    glPopMatrix();

    // Back Triangle
    glPushMatrix();
    glTranslatef(-1.85f, 1.72f, 0.0f);
    glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
    glScalef(1.5f, 0.55f, 3.0f);
    glutSolidCube(1);
    glPopMatrix();

    glColor3ub(WHEEL_COLOR_RED, WHEEL_COLOR_GREEN, WHEEL_COLOR_BLUE);

    // Front-Left Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_FRONT_LEFT_X, WHEEL_COORD_FRONT_LEFT_Y,
                 WHEEL_COORD_FRONT_LEFT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Front-Right Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_FRONT_RIGHT_X, WHEEL_COORD_FRONT_RIGHT_Y,
                 WHEEL_COORD_FRONT_RIGHT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Left Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_LEFT_X, WHEEL_COORD_BACK_LEFT_Y,
                 WHEEL_COORD_BACK_LEFT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Right Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_RIGHT_X, WHEEL_COORD_BACK_RIGHT_Y,
                 WHEEL_COORD_BACK_RIGHT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();
}

void car::update(glut_time_t dt) {
    dynamic_object::update(dt);
    if(speed().x() < 4.0){
		speed().x() += 0.0003;
	}

    if (position().x() > 2.75) {
        position().x() = -2.90;
    }
}
