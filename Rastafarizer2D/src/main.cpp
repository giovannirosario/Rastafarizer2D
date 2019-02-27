#include <iostream>
#include "Canvas.h"
#include "Color.h"
#include "Exporter.h"
#include "Point2D.h"

int main () {
    Point2D start = Point2D(50, 50);
    Point2D end = Point2D(300, 120);

    Canvas image = Canvas(800, 600);
    Color imperial_red = Color(237, 41, 57);

    //image.draw_background(imperial_red);
    image.draw_line(start, end, imperial_red);

    Exporter exporter = Exporter();

    exporter.export_ppm(image, "testfile");

}