#include "timberlog.h"
#include "materials.h"
#include "game_manager.h"

constexpr auto COLOR_RED = 255, COLOR_GREEN = 100, COLOR_BLUE = 20, SLICES = 20,
               STACKS = 20;

constexpr auto RADIUS_0 = 0.5f, RADIUS_Z = 0.5f, HEIGHT = 6.0f,
               COORD_X = HEIGHT / -2, COORD_Y = 0.0f, COORD_Z = 0.0f;

timberlog::timberlog() {
    bounding_box() = ::bounding_box(-3.5, 0, -1.8, 3.5, 0, 1.8);
}

void timberlog::draw() {
    glColor3ub(COLOR_RED, COLOR_GREEN, COLOR_BLUE);
    materials::river_margin.use();

    // Timberlog
    glPushMatrix();
    glTranslatef(COORD_X, COORD_Y, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(3.0, 1.0, 1.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, HEIGHT, SLICES, STACKS);
    glPopMatrix();
}

void timberlog::update(glut_time_t dt) {
    dynamic_object::update(dt);

    if (position().x() > game_manager::instance().game_object_bounds().x2()) {
        position().x() = game_manager::instance().game_object_bounds().x1();
    }
}
