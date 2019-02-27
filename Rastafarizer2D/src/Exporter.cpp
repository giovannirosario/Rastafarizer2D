#include "Exporter.h"

void Exporter::export_png(Canvas * canvas, std::string f_name) {}

void Exporter::export_ppm(Canvas * canvas, std::string f_name) {
    std::ofstream file;
    file.open(f_name + ".ppm");
    file << "P6" << std::endl;
    file << canvas->get_width() << " " << canvas->get_height() << std::endl;
    file << "255 \n";

    Color * pixels = canvas->get_canvas();

    for(int i = 0; i < canvas->get_width(); i++) {
        for(int j = 0; j < canvas->get_height();j++) {
            file << (int) pixels[i*j].get_r() << " ";
            file << (int) pixels[i*j].get_g() << " ";
            file << (int) pixels[i*j].get_b() << " ";
        }
        file << std::endl;
    }
        
    

}